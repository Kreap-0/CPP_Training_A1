#pragma once
#include <cstdint>
#include <string>

namespace adas
{

struct Pose {
    int x;
    int y;
    char heading;
};

enum class CarType : std::uint16_t {
    NORMAL = 0,
    RACING,
    BUS,
};

class Executor
{
public:
    static Executor* NewExecutor(const Pose& pose = {0, 0, 'N'}, const CarType& cartype = CarType::NORMAL) noexcept;

    Executor(void) = default;
    virtual ~Executor(void) = default;

    Executor(const Executor&) = delete;

    Executor& operator=(const Executor&) = delete;

    virtual void Execute(const std::string& command) noexcept = 0;
    virtual Pose Query(void) const noexcept = 0;
};

}  // namespace adas