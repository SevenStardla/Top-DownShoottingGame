#include "enemy/EnemyManager.h"
#include <cstdlib>
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

EnemyManager::EnemyManager()
    {
        wave = 1; // 현재 진행중인 웨이브(게임 단계)
        enemiesToSpawn = 5; // 현재 웨이브에서 생성해야 할 적의 총 수
        waveTimer = 0; // 웨이브 진행 시간 측정용 타이머
        waveInterval = 10.0f; // 다음 단계가 시작되기까지 기다리는 시간
        spawnTimer = 0; // 마지막 적 생성 이후 경과 시간
        spawnInterval = 2.0f; // 다음 적이 생성되기까지의 시간 간격
        difficultyTimer = 10.0f; // 시간이 지남에 따라 난이도를 증가시키기 위한 타이머
    }

void EnemyManager::SetSpeedMultiplier(float multiplier)
    {
        for(auto& enemy : enemies)
        {
            enemy.speed *= multiplier;
        }
    }

void EnemyManager::Separation()
    {
        for(size_t i = 0; i < enemies.size(); i++)
    {
        for(size_t j = i + 1; j < enemies.size(); j++)
        {
            Vector2 diff = Vector2Subtract(
                enemies[i].position,
                enemies[j].position
            );

            float dist = Vector2Length(diff);

            float minDist = enemies[i].radius + enemies[j].radius;

            if(dist < minDist && dist > 0.0001f)
            {
                Vector2 pushDir = Vector2Normalize(diff);

                float pushAmount = (minDist - dist) * 0.3f;

                enemies[i].position = Vector2Add(
                    enemies[i].position,
                    Vector2Scale(pushDir, pushAmount)
                );

                enemies[j].position = Vector2Subtract(
                    enemies[j].position,
                    Vector2Scale(pushDir, pushAmount)
                );
            }
        }
    }
    }
void EnemyManager::Update(Vector2 playerPos, float playerRadius)
    {
        float dt = GetFrameTime();
        waveTimer += dt;

        if (waveTimer >= waveInterval)
        {
            waveTimer = 0;

            wave++;
            enemiesToSpawn += 5 + wave * 2;
        }

        difficultyTimer += dt;
        if (difficultyTimer >= 5.0f)
        {
            difficultyTimer = 0;

            if(spawnInterval > 0.5f)
            {
                spawnInterval = std::max(0.5f, spawnInterval - 0.2f);
            }
        }

        spawnTimer += dt;
        if (spawnTimer >= spawnInterval && enemiesToSpawn > 0)
        {
            spawnTimer = 0;

            Vector2 pos;

                int side = rand() % 4;

                if (side == 0)
                    {
                        pos = {-40, (float)(rand() % SCREEN_HEIGHT)};
                        // pos.x = -40;
                        // pos.y = rand() % 600;
                    }
                else if (side == 1)
                    {
                        pos = {SCREEN_WIDTH + 40, (float)(rand() % SCREEN_HEIGHT)};
                        // pos.x = 840;
                        // pos.y = rand() % 600;
                    }
                else if (side == 2)
                    {
                        pos = {(float)(rand() % SCREEN_WIDTH), -40 };
                        // pos.x = rand() % 800;
                        // pos.y = -40;
                    }
                else
                    {
                        pos = {(float)(rand() % SCREEN_WIDTH), SCREEN_HEIGHT + 40 };
                        // pos.x = rand() % 800;
                        // pos.y = 640;
                    }
                EnemyType type;

                int r = rand() % 3;

                if (r == 0)
                    {
                        type = EnemyType::Normal;
                    }
                else if(r == 1)
                    {
                        type = EnemyType::Fast;
                    }
                else
                    {
                        type = EnemyType::Tank;
                    }
                    enemies.emplace_back(Enemy(pos, type));
                    enemiesToSpawn--;
            }


        for (auto& enemy : enemies)
            {
                enemy.Update(playerPos, playerRadius); // 적 업데이트
            }
        Separation();
    }

void EnemyManager::Draw()
    {
        for (auto& enemy : enemies)
            {
                enemy.Draw();
            }
    }