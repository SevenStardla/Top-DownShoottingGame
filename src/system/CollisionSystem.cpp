#include "system/CollisionSystem.h"
#include <iostream>

bool CollisionSystem::CheckCircle(Vector2 a, float ra, Vector2 b, float rb) // 플레이어, 적, 총알
    {
        float dx = a.x - b.x;
        float dy = a.y - b.y;

        float distSq = dx * dx + dy * dy;
        float r = ra + rb;

        return distSq <= r * r;
    }

void CollisionSystem::BulletVsEnemy(BulletManager& bullets, EnemyManager& enemies, ParticleManager& particles, int& score)
    {
        for (size_t x = 0; x < bullets.bullets.size(); )
{
            bool removed = false;

            for (size_t y = 0; y < enemies.enemies.size(); y++)
            {
                if(CheckCircle(bullets.bullets[x].position, bullets.bullets[x].radius, enemies.enemies[y].position, enemies.enemies[y].radius))
                {
                    Vector2 enemyPos = enemies.enemies[y].position;
                    float enemyRadius = enemies.enemies[y].radius;

                    particles.Spawn(enemies.enemies[y].position);

                    enemies.enemies[y].hp--;

                    if(enemies.enemies[y].hp <= 0)
                    {
                        enemies.enemies.erase(enemies.enemies.begin() + y);
                        score += 10;
                    }

                    bullets.bullets[x].penetration--;

                    Vector2 pushDir = Vector2Normalize(bullets.bullets[x].velocity);
                        if(Vector2Length(pushDir) > 0.0001f)
                            {
                                pushDir = Vector2Normalize(pushDir);
                            }
                        else
                            {
                                pushDir = {1.0f, 0.0f};
                            }

                    float pushDistance = enemyRadius + bullets.bullets[x].radius + 4.0f;

                    bullets.bullets[x].position = Vector2Add(enemyPos,Vector2Scale(pushDir, pushDistance));
                        if(bullets.bullets[x].penetration <= 0)
                            {
                                bullets.bullets.erase(bullets.bullets.begin() + x);
                                removed = true;
                            }

                    break;
                }
            }

            if(!removed)
                {
                    x++;
                }
        }
    }


bool CollisionSystem::EnemyVsPlayer(EnemyManager& enemies, Player& player)
    {
        for (auto& enemy : enemies.enemies)
        {
            if(CheckCircle(enemy.position, enemy.radius, player.position, player.radius))
            {
            if (player.damageTimer > 0)
                {
                    return false;
                }
                player.TakeDamage(10);
                player.damageTimer = player.damageCooldown;
                return true;
            }
        }
        return false;
    }