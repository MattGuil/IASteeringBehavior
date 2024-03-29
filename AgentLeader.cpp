#include "AgentLeader.h"

AgentLeader::AgentLeader(GameWorld* world,
                         Vector2D position,
                         double    rotation,
                         Vector2D velocity,
                         double    mass,
                         double    max_force,
                         double    max_speed,
                         double    max_turn_rate,
                         double    scale,
                         bool      isControlled)
    : Vehicle(world, position, rotation, velocity, mass, max_force, max_speed, max_turn_rate, scale)
{
    this->Steering()->FlockingOff();
    this->SetScale(Vector2D(10, 10));
    

    if (!isControlled) {
        this->Steering()->WanderOn();
        this->SetMaxSpeed(60);
    }
    else {
        this->SetMaxSpeed(30);
        return;
    }
}