#pragma once
#include "Vehicle.h"
#include "SteeringBehaviors.h"

class AgentPoursuiveur : public Vehicle
{
public:
	AgentPoursuiveur(GameWorld* world,
                     Vector2D position,
                     double    rotation,
                     Vector2D  velocity,
                     double    mass,
                     double    max_force,
                     double    max_speed,
                     double    max_turn_rate,
                     double    scale,
                     Vehicle*  leader,
                     Vector2D  offset,
                     bool      leaderIsControlled);

    Vector2D GetOffset();
    Vehicle* GetLeader();
    void SetOffset(Vector2D offset);

private:
    Vehicle* m_leader;
    Vector2D m_offset;
};

