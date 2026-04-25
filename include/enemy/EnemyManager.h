#pragma once
#include "Enemy.h"
#include <vector>
#include "raymath.h"

class EnemyManager
    {
        public:
            std::vector<Enemy> enemies;
            // 현재 게임에 존재하는 모든 Enemy 객체를 저장하는 컨테이너
            // Enemy 생성, 업데이트, 삭제를 모두 여기서 관리한다.

            int wave; // 현재 진행중인 웨이브(게임 단계)
            int enemiesToSpawn; // 현재 웨이브에서 생성해야 할 적의 총 수
            float waveTimer; // 웨이브 진행 시간 측정용 타이머
            float waveInterval; // 다음 단계가 시작되기까지 기다리는 시간


            float spawnTimer = 0; // 마지막 적 생성 이후 경과 시간
            float spawnInterval = 2.0f; // 다음 적이 생성되기까지의 시간 간격
            float difficultyTimer = 0; // 시간이 지남에 따라 난이도를 증가시키기 위한 타이머
            EnemyManager();
            void SetSpeedMultiplier(float multiplier);
            void Separation();
            void Update(Vector2 playerPos, float playerRadius); // 모든 Enemy 상태 업데이트 (이동, 생성, 웨이브 관리 등)
            void Draw(); // 현재 존재하는 적들 화면에 보여주기
    };