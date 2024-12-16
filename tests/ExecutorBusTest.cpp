#include <gtest/gtest.h>

#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{

TEST(ExecutorBusTest, should_return_x_minus_1_given_command_is_BL_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::BUS));
    // when
    executor->Execute("BL");
    // then
    const Pose target{-1, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorBusTest, should_return_x_minus_1_given_command_is_BR_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::BUS));
    // when
    executor->Execute("BR");
    // then
    const Pose target{-1, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorBusTest, should_return_x_plus_1_given_command_is_L_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::BUS));
    // when
    executor->Execute("L");
    // then
    const Pose target{1, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorBusTest, should_return_x_plus_1_given_command_is_R_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::BUS));
    // when
    executor->Execute("R");
    // then
    const Pose target{1, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorBusTest, should_return_x_plus_2_given_command_is_FL_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::BUS));
    // when
    executor->Execute("FL");
    // then
    const Pose target{2, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorBusTest, should_return_x_plus_2_given_command_is_FR_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::BUS));
    // when
    executor->Execute("FR");
    // then
    const Pose target{2, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorBusTest, should_return_x_minus_2_given_command_is_BFL_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::BUS));
    // when
    executor->Execute("BFL");
    // then
    const Pose target{-2, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorBusTest, should_return_x_minus_2_given_command_is_BFR_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, CarType::BUS));
    // when
    executor->Execute("BFR");
    // then
    const Pose target{-2, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}

}  // namespace adas