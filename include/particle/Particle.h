#pragma once
#include "raylib.h"

class Particle
    {
        public:
            Vector2 position; // 파티클 위치
            Vector2 velocity; // 파티클 속도

            float life; // 파티클 수명
            float radius; // 파티클 크기

            Particle(Vector2 pos, Vector2 vel); // 파티클 생성자

            bool Update(); // 파티클 상태 업데이트
            void Draw(); // 파티클 상태 보여주기

    };