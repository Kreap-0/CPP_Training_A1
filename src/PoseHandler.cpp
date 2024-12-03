#include "PoseHandler.hpp"

namespace adas
{

PoseHandler::PoseHandler(const Pose& pose) noexcept
    : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading))
{
}

void PoseHandler::Move(void) noexcept
{
    point += facing->Move();
}

void PoseHandler::TurnLeft(void) noexcept
{
    facing = &(facing->LeftOne());
}

void PoseHandler::TurnRight(void) noexcept
{
    facing = &(facing->RightOne());
}

void PoseHandler::Fast() noexcept
{
    isFast = !isFast;
}

bool PoseHandler::IsFast() const noexcept
{
    return isFast;
}

Pose PoseHandler::Query() const noexcept
{
    return {point.GetX(), point.GetY(), facing->GetHeading()};
}
}  // namespace adas