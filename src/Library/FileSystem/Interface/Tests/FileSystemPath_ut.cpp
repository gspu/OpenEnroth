#include <string>
#include <utility>

#include "Testing/Unit/UnitTest.h"

#include "Library/FileSystem/Interface/FileSystemPath.h"

UNIT_TEST(FileSystemPath, Normalization) {
    EXPECT_EQ(FileSystemPath("foo/bar").string(), "foo/bar");
    EXPECT_EQ(FileSystemPath("/foo/bar").string(), "foo/bar");
    EXPECT_EQ(FileSystemPath("foo/bar/").string(), "foo/bar");
    EXPECT_EQ(FileSystemPath("/foo/bar/").string(), "foo/bar");
    EXPECT_EQ(FileSystemPath("/foo//bar/").string(), "foo/bar");
    EXPECT_EQ(FileSystemPath("//foo//bar//").string(), "foo/bar");

    EXPECT_EQ(FileSystemPath("..").string(), "..");
    EXPECT_EQ(FileSystemPath("../..").string(), "../..");
    EXPECT_EQ(FileSystemPath("/../..").string(), "../..");
    EXPECT_EQ(FileSystemPath("../../").string(), "../..");
    EXPECT_EQ(FileSystemPath("/../../").string(), "../..");
    EXPECT_EQ(FileSystemPath("//..//..//").string(), "../..");

    EXPECT_EQ(FileSystemPath("").string(), "");
    EXPECT_EQ(FileSystemPath("/").string(), "");
    EXPECT_EQ(FileSystemPath("//").string(), "");
    EXPECT_EQ(FileSystemPath("/////////").string(), "");
    EXPECT_EQ(FileSystemPath(".").string(), "");
    EXPECT_EQ(FileSystemPath("/.").string(), "");
    EXPECT_EQ(FileSystemPath("./").string(), "");
    EXPECT_EQ(FileSystemPath("/./").string(), "");
    EXPECT_EQ(FileSystemPath("//.//").string(), "");

    EXPECT_EQ(FileSystemPath("foo/bar/.").string(), "foo/bar");
    EXPECT_EQ(FileSystemPath("foo/./bar").string(), "foo/bar");
    EXPECT_EQ(FileSystemPath("./foo/bar").string(), "foo/bar");
    EXPECT_EQ(FileSystemPath("./foo/./bar/.").string(), "foo/bar");

    EXPECT_EQ(FileSystemPath("foo/bar/..").string(), "foo");
    EXPECT_EQ(FileSystemPath("//foo//bar//..//").string(), "foo");
    EXPECT_EQ(FileSystemPath("foo/../bar").string(), "bar");
    EXPECT_EQ(FileSystemPath("//foo//..//bar//").string(), "bar");
    EXPECT_EQ(FileSystemPath("../foo/bar").string(), "../foo/bar");
    EXPECT_EQ(FileSystemPath("//..//foo//bar//").string(), "../foo/bar");

    EXPECT_EQ(FileSystemPath("foo/bar/../..").string(), "");
    EXPECT_EQ(FileSystemPath("foo/../../bar").string(), "../bar");
    EXPECT_EQ(FileSystemPath("../../foo/bar").string(), "../../foo/bar");

    EXPECT_EQ(FileSystemPath("foo/.../bar/...").string(), "foo/.../bar/...");
}

UNIT_TEST(FileSystemPath, Parent) {
    EXPECT_FALSE(FileSystemPath("foo").isParentOf(FileSystemPath("foo")));
    EXPECT_FALSE(FileSystemPath("").isParentOf(FileSystemPath("")));

    EXPECT_TRUE(FileSystemPath("").isParentOf(FileSystemPath("a")));
    EXPECT_TRUE(FileSystemPath("").isParentOf(FileSystemPath("a/b")));
    EXPECT_TRUE(FileSystemPath("a").isParentOf(FileSystemPath("a/b")));

    EXPECT_FALSE(FileSystemPath("a/b").isParentOf(FileSystemPath("a")));
    EXPECT_FALSE(FileSystemPath("a/b").isParentOf(FileSystemPath("")));
    EXPECT_FALSE(FileSystemPath("a").isParentOf(FileSystemPath("")));
}

UNIT_TEST(FileSystemPath, EmptyChunks) {
    EXPECT_TRUE(FileSystemPath().split().empty());
    EXPECT_TRUE(FileSystemPath(".").split().empty());
    EXPECT_FALSE(FileSystemPath("..").split().empty());
    EXPECT_FALSE(FileSystemPath("a").split().empty());
}

UNIT_TEST(FileSystemPath, Tail) {
    FileSystemPath path("a/b/c");

    auto tails = [] (FileSystemPathView path, std::string_view at) -> std::pair<FileSystemPathView, FileSystemPathView> {
        for (std::string_view chunk : path.split())
            if (chunk == at)
                return std::pair(path.split().tailAt(chunk), path.split().tailAfter(chunk));
        return {};
    };

    const auto [tail0, tail1] = tails(path, "a");
    EXPECT_EQ(tail0.string(), "a/b/c");
    EXPECT_EQ(tail1.string(), "b/c");

    const auto [tail2, tail3] = tails(path, "b");
    EXPECT_EQ(tail2.string(), "b/c");
    EXPECT_EQ(tail3.string(), "c");

    const auto [tail4, tail5] = tails(path, "c");
    EXPECT_EQ(tail4.string(), "c");
    EXPECT_EQ(tail5.string(), "");

    const auto [tail6, tail7] = tails(path, "d");
    EXPECT_EQ(tail6.string(), "");
    EXPECT_EQ(tail7.string(), "");
}

UNIT_TEST(FileSystemPath, TailAfterRoot) {
    FileSystemPath path("a/b/c");

    EXPECT_EQ(path.split().tailAfter(""), path);
    // Note: can't call tailAt("") b/c "" is not a valid chunk.
}

UNIT_TEST(FileSystemPath, Appended) {
    auto testOne = [] (std::string_view l, std::string_view r, std::string_view result) {
        EXPECT_EQ((FileSystemPath(l) / FileSystemPath(r)).string(), result);
        EXPECT_EQ((FileSystemPath(l) / r).string(), result);
    };

    testOne("", "", "");
    testOne("", "a", "a");
    testOne("a", "", "a");
    testOne("a", "b", "a/b");
    testOne("a/b", "c", "a/b/c");
    testOne("a/b", "c/d", "a/b/c/d");
}

UNIT_TEST(FileSystemPath, Append) {
    FileSystemPath path0("");
    path0 /= "";
    EXPECT_EQ(path0.string(), "");

    FileSystemPath path1("");
    path1 /= "a";
    EXPECT_EQ(path1.string(), "a");

    FileSystemPath path2("a");
    path2 /= "";
    EXPECT_EQ(path2.string(), "a");

    FileSystemPath path3("a");
    path3 /= "b";
    EXPECT_EQ(path3.string(), "a/b");

    FileSystemPath path4("a/b");
    path4 /= "c";
    EXPECT_EQ(path4.string(), "a/b/c");

    FileSystemPath path5("a/b");
    path5 /= FileSystemPath("c/d");
    EXPECT_EQ(path5.string(), "a/b/c/d");
}

UNIT_TEST(FileSystemPath, AppendedEscaping) {
    auto testOne = [] (std::string_view l, std::string_view r, std::string_view result) {
        EXPECT_EQ((FileSystemPath(l) / FileSystemPath(r)).string(), result);
        EXPECT_EQ((FileSystemPath(l) / r).string(), result);
    };

    testOne("..", "..", "../..");
    testOne("../..", "../..", "../../../..");
    testOne("", "..", "..");
    testOne("..", "", "..");
    testOne("", "../..", "../..");
    testOne("../..", "", "../..");

    testOne("../../abc", "..", "../..");
    testOne("../../abc", "../..", "../../..");
    testOne("../../abc", "../../xyz", "../../../xyz");
    testOne("aa/bb", "../../xyz", "xyz");
    testOne("aa/bb", "../../../xyz", "../xyz");

    testOne("aa", "..", "");
    testOne("aa/bb", "../..", "");
    testOne("aa/bb/cc", "../../..", "");
}

UNIT_TEST(FileSystemPath, EscapingParents) {
    EXPECT_TRUE(FileSystemPath("..").isParentOf(FileSystemPath("")));
    EXPECT_TRUE(FileSystemPath("../..").isParentOf(FileSystemPath("")));
    EXPECT_FALSE(FileSystemPath("../../a").isParentOf(FileSystemPath("")));
    EXPECT_TRUE(FileSystemPath("../../a/..").isParentOf(FileSystemPath("")));
    EXPECT_TRUE(FileSystemPath("../../a/..").isParentOf(FileSystemPath("a")));
    EXPECT_TRUE(FileSystemPath("../..").isParentOf(FileSystemPath("a/b")));

    EXPECT_FALSE(FileSystemPath("").isParentOf(FileSystemPath("..")));
    EXPECT_FALSE(FileSystemPath("").isParentOf(FileSystemPath("../..")));
    EXPECT_FALSE(FileSystemPath("a/b").isParentOf(FileSystemPath("..")));
    EXPECT_FALSE(FileSystemPath("a/b").isParentOf(FileSystemPath("../..")));
    EXPECT_FALSE(FileSystemPath("a/b").isParentOf(FileSystemPath("../../a/b")));

    EXPECT_TRUE(FileSystemPath("../..").isParentOf(FileSystemPath("..")));
    EXPECT_TRUE(FileSystemPath("../../..").isParentOf(FileSystemPath("..")));
    EXPECT_TRUE(FileSystemPath("../../..").isParentOf(FileSystemPath("../b")));
    EXPECT_TRUE(FileSystemPath("../../..").isParentOf(FileSystemPath("../../b")));
    EXPECT_TRUE(FileSystemPath("../../..").isParentOf(FileSystemPath("../../../b")));
    EXPECT_FALSE(FileSystemPath("../../..").isParentOf(FileSystemPath("../../../../b")));
    EXPECT_TRUE(FileSystemPath("../../../a").isParentOf(FileSystemPath("../../../a/b")));
    EXPECT_FALSE(FileSystemPath("../../../a").isParentOf(FileSystemPath("../../../b")));
}

UNIT_TEST(FileSystemPath, TailAtByIterator) {
    FileSystemPath path("a/b");

    auto split = path.split();
    auto pos = split.begin();
    auto end = split.end();

    EXPECT_EQ(*pos, "a");
    EXPECT_EQ(path.split().tailAt(pos).string(), "a/b");

    pos++;
    EXPECT_EQ(*pos, "b");
    EXPECT_EQ(path.split().tailAt(pos).string(), "b");

    pos++;
    EXPECT_EQ(path.split().tailAt(pos).string(), "");
    EXPECT_EQ(pos, end);
}
