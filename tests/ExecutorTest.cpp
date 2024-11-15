#include <gtest/gtest.h>

#include <tuple>

#include "Executor.hpp"

namespace adas
{
bool operator==(const Pose& X, const Pose& Y)
{
    return std::tie(X.x, X.y, X.heading) == std::tie(Y.x, Y.y, Y.heading);
}
}  // namespace adas

TEST(ExecutorTest, should_return_init_pose_when_without_command)
{
    // given
    std::unique_ptr<adas::Executor> executor(adas::Executor::NewExecutor({0, 0, 'E'}));

    // when

    // then
    const adas::Pose target({0, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}