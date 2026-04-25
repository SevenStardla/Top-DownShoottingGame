#pragma once
#include "Particle.h"
#include <vector>

class ParticleManager
    {
        public:
            std::vector<Particle> particles;

            void Spawn(Vector2 pos);
            void Update();
            void Draw();
    };