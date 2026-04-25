#include "particle/Particle.h"

Particle::Particle(Vector2 pos, Vector2 vel)
    {
        position = pos;
        velocity = vel;

        life = 1.0f;
        radius = 3;
    }

bool Particle::Update()
    {
        float dt = GetFrameTime();

        position.x += velocity.x * dt;
        position.y += velocity.y * dt;

        life -= dt;

        return life <= 0;
    }

void Particle::Draw()
    {
        DrawCircleV(position, radius, YELLOW);
    }