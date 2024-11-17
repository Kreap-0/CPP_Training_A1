#pragma once
#include <string>

namespace adas
{
struct Pose {
    int x, y;
    char heading;
};

class Executor
{
public:
    static Executor* NewExecutor(const Pose& pose = {0, 0, 'N'}) noexcept;

    Executor(void) = default;
    virtual ~Executor(void) = default;

    Executor(const Executor&) = delete;

    Executor& operator=(const Executor&) = delete;

    virtual void Execute(const std::string& command) noexcept = 0;
    virtual Pose Query(void) const noexcept = 0;
};
}