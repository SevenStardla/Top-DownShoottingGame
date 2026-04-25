#include "enemy/EnemyManager.h"
#include <cstdlib>
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

EnemyManager::EnemyManager()
    {
        wave = 1;
        enemiesToSpawn = 5;

        waveTimer = 0;
        waveInterval = 10.0f;
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