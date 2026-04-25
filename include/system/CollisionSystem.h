#pragma once
#include "bullet/BulletManager.h"
#include "enemy/EnemyManager.h"
#include "particle/ParticleManager.h"
#include "player/Player.h"

class
CollisionSystem // 충돌 클래스
    {
        public:
            static bool CheckCircle(Vector2 a, float ra, Vector2 b, float rb); // 플레이어, 적, 총알이 서로 충돌하는지 확인하는 기능 / 플레이어, 적, 총알들을 나타내는 것이 모두 원이기 때문에 CheckCircle이라는 기능 정의

            static void BulletVsEnemy(BulletManager& bullets, EnemyManager& enemies, ParticleManager& particles, int& score); // 총알과 적이 서로 충돌할때 나타나는 기능

            static bool EnemyVsPlayer(EnemyManager& enemies, Player& player);
            // 적과 플레이어가 서로 충돌할때 나타나는 기능
    };