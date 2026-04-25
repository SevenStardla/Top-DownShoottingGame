#include "particle/ParticleManager.h"
#include <cstdlib>

void ParticleManager::Spawn(Vector2 pos)
    {
        for (int x = 0; x < 10; x++)
            {
                Vector2 vel;

                vel.x = (rand() % 200 - 100);
                vel.y = (rand() % 200 - 100);

                particles.push_back(Particle(pos, vel));
            }
    }
void ParticleManager::Update()
    {
        for (size_t x = 0; x < particles.size(); x++)
            {
                if (particles[x].Update())
                    {
                        particles.erase(particles.begin() + x);
                        x--;
                    }
            }
    }
void ParticleManager::Draw()
    {
        for (auto& p : particles)
            {
                p.Draw();
            }
    }