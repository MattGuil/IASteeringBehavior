#include "AgentPoursuiveur.h"

AgentPoursuiveur::AgentPoursuiveur(GameWorld* world,
                                   Vector2D position,
                                   double    rotation,
                                   Vector2D velocity,
                                   double    mass,
                                   double    max_force,
                                   double    max_speed,
                                   double    max_turn_rate,
                                   double    scale,
                                   Vehicle* leader,
                                   Vector2D offset,
                                   bool     leaderIsControlled)
    : m_leader(leader), m_offset(offset), Vehicle(world, position, rotation, velocity, mass, max_force, max_speed, max_turn_rate, scale)
{
    if (!leaderIsControlled) {
        this->SetMaxSpeed(70);
    }
    else {
        this->SetMaxSpeed(100);
    }
	this->Steering()->OffsetPursuitOn(leader, offset);
}

Vector2D AgentPoursuiveur::GetOffset() {
    return this->m_offset;
}

Vehicle* AgentPoursuiveur::GetLeader() {
    return this->m_leader;
}

void AgentPoursuiveur::SetOffset(Vector2D newOffset) {
    this->Steering()->SetOffset(newOffset);
    this->m_offset = newOffset;
}