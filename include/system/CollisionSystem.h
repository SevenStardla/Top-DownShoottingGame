#pragma once
#include "raylib.h"
#include <vector>
#include <cstddef>
// #include "bullet/BulletManager.h"
// #include "enemy/EnemyManager.h"
// #include "particle/ParticleManager.h"
// #include "player/Player.h"
class BulletManager;
class EnemyManager;
class ParticleManager;
class Player;

// 충돌 시스템은 모든 객체의 충돌을 알아야하기 때문에 다음과 같은 객체를 포함(include)시킬 수 있도록 한다.
struct Hit {
    size_t bulletIdx;
    size_t enemyIdx;
};

class CollisionSystem // 충돌 클래스
    {
        public:
            std::vector<Hit> hits;
            static bool CheckCircle(Vector2 a, float ra, Vector2 b, float rb); // 플레이어, 적, 총알 등 적을 나타내는 객체가 모두 원이기 때문에 원을 체크하여 충돌을 만드는 것이 더 수월하다.

            static bool EnemyVsPlayer(EnemyManager& enemies, Player& player);
            // 적이 플레이어에게 닿았을떄 충돌이 발생하도록 한다.
    };