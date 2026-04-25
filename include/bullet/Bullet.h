#pragma once
#include "raylib.h"
#include "raymath.h"

class Bullet // 총알 클래스
    {
        public:
            Vector2 position; // 총알 위치
            Vector2 velocity; // 총알 속도
            float radius; // 총알 크기
            int penetration;

            Bullet(Vector2 startPos, Vector2 dir, float speed, int penetration); // 총알 생성자(생성위치, 총알 방향)

            void Update(); // 총알 업데이트
            void Draw(); // 총알 상태
    };