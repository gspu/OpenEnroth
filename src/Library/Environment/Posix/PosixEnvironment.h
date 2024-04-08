#pragma once

#include <string>

#include "Library/Environment/Interface/Environment.h"

class PosixEnvironment : public Environment {
 public:
    [[nodiscard]] virtual std::string queryRegistry(const std::string &path) const override;
    [[nodiscard]] virtual std::string path(EnvironmentPath path) const override;
    [[nodiscard]] virtual std::string getenv(const std::string &key) const override;
};
