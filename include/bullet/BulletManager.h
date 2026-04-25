#pragma once
#include "Bullet.h"
#include <vector>

class BulletManager // 총알 관리 클래스
    {
        public:
            std::vector<Bullet> bullets; // 총알들을 저장하는 bullets 선언
            void Shoot(Vector2 start, Vector2 dir, float speed, int penetration); // 총알 발사 기능
            void Update(); // 총알 관리 상태 업데이트
            void Draw(); // 현재 총알들의 상태 보여주기
    };