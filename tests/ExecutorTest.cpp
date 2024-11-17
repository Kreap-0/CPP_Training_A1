#include <gtest/gtest.h>

#include <tuple>

#include "Executor.hpp"

namespace adas
{

bool operator==(const Pose& X, const Pose& Y)
{
    return std::tie(X.x, X.y, X.heading) == std::tie(Y.x, Y.y, Y.heading);
}

TEST(ExecutorTest, should_return_init_pose_when_without_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when

    // then
    const adas::Pose target({0, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor());
    // when

    // then
    const Pose target({0, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}

}  // namespace adas