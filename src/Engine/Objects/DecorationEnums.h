#pragma once

#include <cstdint>

#include "Utility/Flags.h"

/**
 * Enum of all decorations in the game, e.g. trees, trash heaps, pedestals, etc.
 *
 * DON'T EDIT, THIS IS AUTOGENERATED CODE.
 *
 * @see runDecorationsCodegen
 */
enum class DecorationId : int32_t {
    DECORATION_NULL = 0,
    DECORATION_PENDING = 1,                // Pending!, test, r=16
    DECORATION_PARTY_START = 2,            // Party Start, test
    DECORATION_FOUNTAIN_FOUNT1 = 3,        // fount1, fountain
    DECORATION_TRASH_HEAP_DEC01 = 4,       // dec01, trash heap
    DECORATION_CAMPFIRE = 5,               // dec02, campfire
    DECORATION_CAULDRON = 6,               // dec03, cauldron
    DECORATION_CHANDELIER = 7,             // dec04, chandelier
    DECORATION_CAGE_DEC05 = 8,             // dec05, cage
    DECORATION_CAGE_DEC06 = 9,             // dec06, cage
    DECORATION_CAGE_DEC07 = 10,            // dec07, cage
    DECORATION_FRUIT_BOWL = 11,            // dec08, fruit bowl
    DECORATION_ROCK_DEC09 = 12,            // dec09, rock
    DECORATION_TRASH_HEAP_DEC10 = 13,      // dec10, trash heap
    DECORATION_DIRT = 14,                  // dec11, dirt
    DECORATION_WOOD_DEC12 = 15,            // dec12, wood
    DECORATION_WOOD_DEC13 = 16,            // dec13, wood
    DECORATION_WOOD_DEC14 = 17,            // dec14, wood
    DECORATION_WOOD_DEC15 = 18,            // dec15, wood
    DECORATION_WOOD_DEC16 = 19,            // dec16, wood
    DECORATION_WOOD_DEC17 = 20,            // dec17, wood
    DECORATION_BONES_DEC18 = 21,           // dec18, bones
    DECORATION_BONES_DEC19 = 22,           // dec19, bones
    DECORATION_SKULL = 23,                 // dec20, skull
    DECORATION_CASK = 24,                  // dec21, cask, snd=10
    DECORATION_SHIP = 25,                  // dec22, ship, snd=18
    DECORATION_BAG = 26,                   // dec23, bag
    DECORATION_BARREL_DEC24 = 27,          // dec24, barrel
    DECORATION_KEG = 28,                   // dec25, keg
    DECORATION_FIRE_DEC26 = 29,            // dec26, fire
    DECORATION_FIRE_DEC27 = 30,            // dec27, fire
    DECORATION_TORCH01 = 31,               // torch01, torch, r=512, #ff8000
    DECORATION_TORCH02 = 32,               // torch02, torch, r=512, #ff8000
    DECORATION_TORCH03 = 33,               // torch03, torch, r=512, #ff8000
    DECORATION_BARREL_DEC32 = 34,          // dec32, barrel, snd=228
    DECORATION_BUOY = 35,                  // dec33, buoy
    DECORATION_ROCK_DEC34 = 36,            // dec34, rock
    DECORATION_FOUNTAIN_DEC35 = 37,        // dec35, fountain, snd=10
    DECORATION_LARGE_FIRE = 38,            // fire01, large fire, r=256, #ff0000
    DECORATION_NORTH_START = 39,           // north start, null
    DECORATION_SOUTH_START = 40,           // south start, null
    DECORATION_EAST_START = 41,            // east start, null
    DECORATION_WEST_START = 42,            // west start, null
    DECORATION_BOTTLE = 43,                // dec41, bottle
    DECORATION_BOWL_DEC42 = 44,            // dec42, bowl
    DECORATION_STACK_OF_BOWLS_DEC43 = 45,  // dec43, stack of bowls
    DECORATION_BOWL_DEC44 = 46,            // dec44, bowl
    DECORATION_STACK_OF_BOWLS_DEC45 = 47,  // dec45, stack of bowls
    DECORATION_GOBLET_DEC46 = 48,          // dec46, goblet
    DECORATION_GOBLET_DEC47 = 49,          // dec47, goblet
    DECORATION_GOBLET_DEC48 = 50,          // dec48, goblet
    DECORATION_MILE_MARKET = 51,           // dec49, mile market
    DECORATION_PLATE_DEC50 = 52,           // dec50, plate
    DECORATION_STACK_OF_PLATES_DEC51 = 53, // dec51, stack of plates
    DECORATION_PLATE_DEC52 = 54,           // dec52, plate
    DECORATION_STACK_OF_PLATES_DEC53 = 55, // dec53, stack of plates
    DECORATION_TREE01 = 56,                // tree01, tree
    DECORATION_TREE02 = 57,                // tree02, tree
    DECORATION_TREE03 = 58,                // tree03, tree
    DECORATION_TREE04 = 59,                // tree04, tree
    DECORATION_TREE05 = 60,                // tree05, tree
    DECORATION_TREE06 = 61,                // tree06, tree
    DECORATION_TREE07 = 62,                // tree07, tree
    DECORATION_TREE08 = 63,                // tree08, tree
    DECORATION_TREE09 = 64,                // tree09, tree
    DECORATION_TREE10 = 65,                // tree10, tree
    DECORATION_TREE11 = 66,                // tree11, tree
    DECORATION_TREE12 = 67,                // tree12, tree
    DECORATION_TREE13 = 68,                // tree13, tree
    DECORATION_TREE14 = 69,                // tree14, tree
    DECORATION_TREE15 = 70,                // tree15, tree
    DECORATION_TREE16 = 71,                // tree16, tree
    DECORATION_TREE17 = 72,                // tree17, tree
    DECORATION_TREE18 = 73,                // tree18, tree
    DECORATION_TREE19 = 74,                // tree19, tree
    DECORATION_TREE20 = 75,                // tree20, tree
    DECORATION_TREE21 = 76,                // tree21, tree
    DECORATION_TREE22 = 77,                // tree22, tree
    DECORATION_TREE23 = 78,                // tree23, tree
    DECORATION_TREE24 = 79,                // tree24, tree
    DECORATION_TREE25 = 80,                // tree25, tree
    DECORATION_TREE26 = 81,                // tree26, tree
    DECORATION_TREE27 = 82,                // tree27, tree
    DECORATION_TREE28 = 83,                // tree28, tree
    DECORATION_TREE29 = 84,                // tree29, tree
    DECORATION_TREE30 = 85,                // tree30, tree
    DECORATION_TREE31 = 86,                // tree31, tree
    DECORATION_TREE32 = 87,                // tree32, tree
    DECORATION_TREE33 = 88,                // tree33, tree
    DECORATION_TREE34 = 89,                // tree34, tree
    DECORATION_TREE35 = 90,                // tree35, tree
    DECORATION_TREE36 = 91,                // tree36, tree
    DECORATION_TREE37 = 92,                // tree37, tree
    DECORATION_TREE38 = 93,                // tree38, tree
    DECORATION_TREE39 = 94,                // tree39, tree
    DECORATION_TREE40 = 95,                // tree40, tree
    DECORATION_TREE41 = 96,                // tree41, tree
    DECORATION_TREE42 = 97,                // tree42, tree
    DECORATION_SNDBROOK = 98,              // Snd_Brook, test, snd=10
    DECORATION_SNDBOAT = 99,               // Snd_Boat, test, snd=18
    DECORATION_SNDHOWL = 100,              // Snd_Howl, test, snd=233
    DECORATION_SNDDRAGON = 101,            // Snd_Dragon, test, snd=1103
    DECORATION_BUSH01 = 102,               // bush01, bush
    DECORATION_BUSH02 = 103,               // bush02, bush
    DECORATION_BUSH03 = 104,               // bush03, bush
    DECORATION_BUSH04 = 105,               // bush04, bush
    DECORATION_BUSH05 = 106,               // bush05, bush
    DECORATION_BUSH06 = 107,               // bush06, bush
    DECORATION_BUSH07 = 108,               // bush07, bush
    DECORATION_BUSH08 = 109,               // bush08, bush
    DECORATION_ROCK01 = 110,               // rock01, rock
    DECORATION_ROCK02 = 111,               // rock02, rock
    DECORATION_ROCK03 = 112,               // rock03, rock
    DECORATION_ROCK04 = 113,               // rock04, rock
    DECORATION_ROCK05 = 114,               // rock05, rock
    DECORATION_ROCK06 = 115,               // rock06, rock
    DECORATION_ROCK07 = 116,               // rock07, rock
    DECORATION_ROCK08 = 117,               // rock08, rock
    DECORATION_ROCK09 = 118,               // rock09, rock
    DECORATION_ROCK10 = 119,               // rock10, rock
    DECORATION_ROCK11 = 120,               // rock11, rock
    DECORATION_ROCK12 = 121,               // rock12, rock
    DECORATION_ROCK13 = 122,               // rock13, rock
    DECORATION_ROCK14 = 123,               // rock14, rock
    DECORATION_ROCK15 = 124,               // rock15, rock
    DECORATION_ROCK16 = 125,               // rock16, rock
    DECORATION_ROCK17 = 126,               // rock17, rock
    DECORATION_ROCK18 = 127,               // rock18, rock
    DECORATION_ROCK19 = 128,               // rock19, rock
    DECORATION_ROCK20 = 129,               // rock20, rock
    DECORATION_TORCH05 = 130,              // TORCH05, torch, r=512, #1c00ff
    DECORATION_TORCH06 = 131,              // torch06, torch, r=512, #00ff00
    DECORATION_TORCH07 = 132,              // torch07, torch, r=512, #ff0000
    DECORATION_CACTUS_BUSH09 = 133,        // bush09, cactus
    DECORATION_CACTUS_BUSH10 = 134,        // bush10, cactus
    DECORATION_CACTUS_BUSH11 = 135,        // bush11, cactus
    DECORATION_CACTUS_BUSH12 = 136,        // bush12, cactus
    DECORATION_CACTUS_BUSH13 = 137,        // bush13, cactus
    DECORATION_CACTUS_BUSH14 = 138,        // bush14, cactus
    DECORATION_CACTUS_BUSH15 = 139,        // bush15, cactus
    DECORATION_CACTUS_BUSH16 = 140,        // bush16, cactus
    DECORATION_FLOWER01 = 141,             // flower01, flower
    DECORATION_FLOWER02 = 142,             // flower02, flower
    DECORATION_FLOWER03 = 143,             // flower03, flower
    DECORATION_FLOWER04 = 144,             // flower04, flower
    DECORATION_FLOWER05 = 145,             // flower05, flower
    DECORATION_FLOWER06 = 146,             // flower06, flower
    DECORATION_FLOWER07 = 147,             // flower07, flower
    DECORATION_FLOWER08 = 148,             // flower08, flower
    DECORATION_FLOWER09 = 149,             // flower09, flower
    DECORATION_FLOWER10 = 150,             // flower10, flower
    DECORATION_FLOWER11 = 151,             // flower11, flower
    DECORATION_FLOWER12 = 152,             // flower12, flower
    DECORATION_FLOWER13 = 153,             // flower13, flower
    DECORATION_FLOWER14 = 154,             // flower14, flower
    DECORATION_FLOWER15 = 155,             // flower15, flower
    DECORATION_FLOWER16 = 156,             // flower16, flower
    DECORATION_PLANT01A = 157,             // plant01a, plant
    DECORATION_PLANT01B = 158,             // plant01b, plant
    DECORATION_PLANT02A = 159,             // plant02a, plant
    DECORATION_PLANT02B = 160,             // plant02b, plant
    DECORATION_PLANT03A = 161,             // plant03a, plant
    DECORATION_PLANT03B = 162,             // plant03b, plant
    DECORATION_PLANT04A = 163,             // plant04a, plant
    DECORATION_PLANT04B = 164,             // plant04b, plant
    DECORATION_PLANT05A = 165,             // plant05a, plant
    DECORATION_PLANT05B = 166,             // plant05b, plant
    DECORATION_PLANT06A = 167,             // plant06a, plant
    DECORATION_PLANT06B = 168,             // plant06b, plant
    DECORATION_PLANT07A = 169,             // plant07a, plant
    DECORATION_PLANT07B = 170,             // plant07b, plant
    DECORATION_PLANT08A = 171,             // plant08a, plant
    DECORATION_PLANT08B = 172,             // plant08b, plant
    DECORATION_PLANT09A = 173,             // plant09a, plant
    DECORATION_PLANT09B = 174,             // plant09b, plant
    DECORATION_PLANT10A = 175,             // plant10a, plant
    DECORATION_PLANT10B = 176,             // plant10b, plant
    DECORATION_PLANT11A = 177,             // plant11a, plant
    DECORATION_PLANT11B = 178,             // plant11b, plant
    DECORATION_PLANT12A = 179,             // plant12a, plant
    DECORATION_PLANT12B = 180,             // plant12b, plant
    DECORATION_STATUE_DEC54 = 181,         // dec54, statue
    DECORATION_STATUE_DEC55 = 182,         // dec55, statue
    DECORATION_VASE = 183,                 // dec97, vase
    DECORATION_FIRE_DEC24 = 184,           // dec24, fire
    DECORATION_MUSHROOM_DEC86 = 185,       // dec86, mushroom
    DECORATION_LOG = 186,                  // dec87, log
    DECORATION_MUSHROOM_DEC88 = 187,       // dec88, mushroom
    DECORATION_FOSSIL_DEC89 = 188,         // dec89, fossil
    DECORATION_FOSSIL_DEC90 = 189,         // dec90, fossil
    DECORATION_MUSHROOM_DEC91 = 190,       // dec91, mushroom
    DECORATION_STALAGMITE = 191,           // dec92, stalagmite
    DECORATION_MUSHROOM_DEC93 = 192,       // dec93, mushroom
    DECORATION_MUSHROOM_DEC98 = 193,       // dec98, mushroom
    DECORATION_MUSHROOM_DEC99 = 194,       // dec99, mushroom
    DECORATION_TREE60 = 195,               // tree60, tree
    DECORATION_TREE61 = 196,               // tree61, tree
    DECORATION_TREE62 = 197,               // tree62, tree
    DECORATION_TREE63 = 198,               // tree63, tree
    DECORATION_TREE64 = 199,               // tree64, tree
    DECORATION_TREE65 = 200,               // tree65, tree
    DECORATION_TREE66 = 201,               // tree66, tree
    DECORATION_STATUE_DEC94 = 202,         // dec94, statue
    DECORATION_STATUE_DEC95 = 203,         // dec95, statue
    DECORATION_STATUE_DEC96 = 204,         // dec96, statue
    DECORATION_TREE69 = 205,               // tree69, tree69
    DECORATION_BEACON_FIRE_DEC60 = 206,    // dec60, beacon fire, r=128
    DECORATION_BEACON_FIRE_DEC61 = 207,    // dec61, beacon fire, r=128
    DECORATION_BEACON_FIRE_DEC62 = 208,    // dec62, beacon fire, r=128
    DECORATION_BEACON_FIRE_DEC63 = 209,    // dec63, beacon fire, r=128
    DECORATION_MAGIC_PEDASTAL_DEC64 = 210, // dec64, magic pedastal, r=64
    DECORATION_MAGIC_PEDASTAL_DEC65 = 211, // dec65, magic pedastal, r=64
    DECORATION_MAGIC_PEDASTAL_DEC66 = 212, // dec66, magic pedastal, r=64
    DECORATION_MAGIC_PEDASTAL_DEC67 = 213, // dec67, magic pedastal, r=64
    DECORATION_MAGIC_PEDASTAL_DEC68 = 214, // dec68, magic pedastal, r=64
    DECORATION_MAGIC_PEDASTAL_DEC69 = 215, // dec69, magic pedastal, r=64
    DECORATION_MAGIC_PEDASTAL_DEC70 = 216, // dec70, magic pedastal, r=64
    DECORATION_MAGIC_PEDASTAL_DEC71 = 217, // dec71, magic pedastal, r=64
    DECORATION_MAGIC_PEDASTAL_DEC72 = 218, // dec72, magic pedastal, r=64
    DECORATION_MAGIC_PEDASTAL_DEC73 = 219, // dec73, magic pedastal, r=64
    DECORATION_MAGIC_PEDASTAL_DEC74 = 220, // dec74, magic pedastal, r=64
    DECORATION_MAGIC_PEDASTAL_DEC75 = 221, // dec75, magic pedastal, r=64
    DECORATION_BURNED_OUT_FIRE = 222,      // dec24x, burned out fire
    DECORATION_TREE43 = 224,               // tree43, tree
    DECORATION_TREE44 = 225,               // tree44, tree
    DECORATION_TREE45 = 226,               // tree45, tree
    DECORATION_TREE46 = 227,               // tree46, tree
};
using enum DecorationId;


enum class DecorationDescFlag : uint16_t {
    DECORATION_DESC_MOVE_THROUGH = 0x0001,
    DECORATION_DESC_DONT_DRAW = 0x0002,
    DECORATION_DESC_FLICKER_SLOW = 0x0004,
    DECORATION_DESC_FICKER_AVERAGE = 0x0008,
    DECORATION_DESC_FICKER_FAST = 0x0010,
    DECORATION_DESC_MARKER = 0x0020,
    DECORATION_DESC_SLOW_LOOP = 0x0040,
    DECORATION_DESC_EMITS_FIRE = 0x0080,
    DECORATION_DESC_SOUND_ON_DAWN = 0x0100,
    DECORATION_DESC_SOUND_ON_DUSK = 0x0200,
    DECORATION_DESC_EMITS_SMOKE = 0x0400,
};
using enum DecorationDescFlag;
MM_DECLARE_FLAGS(DecorationDescFlags, DecorationDescFlag)
MM_DECLARE_OPERATORS_FOR_FLAGS(DecorationDescFlags)


enum class LevelDecorationFlag : uint16_t {
    LEVEL_DECORATION_TRIGGERED_BY_TOUCH = 0x01,
    LEVEL_DECORATION_TRIGGERED_BY_MONSTER = 0x02,
    LEVEL_DECORATION_TRIGGERED_BY_OBJECT = 0x04,
    LEVEL_DECORATION_VISIBLE_ON_MAP = 0x08,
    LEVEL_DECORATION_CHEST = 0x10,
    LEVEL_DECORATION_INVISIBLE = 0x20,
    LEVEL_DECORATION_OBELISK_CHEST = 0x40,
};
using enum LevelDecorationFlag;
MM_DECLARE_FLAGS(LevelDecorationFlags, LevelDecorationFlag)
MM_DECLARE_OPERATORS_FOR_FLAGS(LevelDecorationFlags)
