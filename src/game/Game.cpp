#include "game/Game.h"
#include "system/CollisionSystem.h"
#include "raylib.h"
#include <cmath>

Game::Game()
    {
        camera.target = {400, 300};
        camera.offset = {400, 300};
        camera.rotation = 0;
        camera.zoom = 1;
    }

void Game::TriggerShake()
    {
        shakeTimer = shakeDuration;
    }

void Game::Reset()
    {
        enemyManager.enemies.clear();
        bulletManager.bullets.clear();
        particleManager.particles.clear();

        player.position = {400, 300};
        player.hp = player.maxHp;
        enemyManager.wave = 1;
        enemyManager.enemiesToSpawn = 0;
        enemyManager.SetSpeedMultiplier(1.0f);
        score = 0;
        gameOver = false;
    }

void Game::HandleInput()
    {
        if(gameOver)
            {
                return;
            }
        // 총 발사
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && fireTimer >= fireInterval) // 마우스 왼쪽 버튼을 눌렀을 때
            {
                weaponSystem.Shoot(player.currentWeapon, bulletManager, player.position, player.direction);
                fireTimer = 0;
            }

        if(IsKeyPressed(KEY_ONE))
            {
                player.currentWeapon = WeaponType::Normal;
            }

        if(IsKeyPressed(KEY_TWO))
            {
                player.currentWeapon = WeaponType::Spread;
            }

        if(IsKeyPressed(KEY_THREE))
            {
                player.currentWeapon = WeaponType::Fast;
            }

    }

void Game::DebugKey()
    {
        if(IsKeyPressed(KEY_FOUR))
            {
                player.hp = 0;

            }
    }

void Game::UpdateSystems()
    {
        bulletManager.Update();
        enemyManager.Update(player.position, player.radius);
        particleManager.Update();
    }

void Game::HandleCombat()
    {
        CollisionSystem::BulletVsEnemy(bulletManager, enemyManager, particleManager, score);

        if(CollisionSystem::EnemyVsPlayer(enemyManager, player))
            {
                TriggerShake();
            }
    }

void Game::HandleGameState()
    {
        if (player.hp <= 0)
            {
                gameOver = true;
                enemyManager.SetSpeedMultiplier(0.3f);
            }

        if (shakeTimer > 0)
            {
                shakeTimer -= GetFrameTime();
            }
    }

void Game::HandleGameOver()
    {
        if (gameOver)
            {
                if (IsKeyPressed(KEY_R))
                    {
                        Reset();
                    }
                return;
            }
        if(!gameOver)
            {
                player.Update();
                enemyManager.waveTimer += GetFrameTime();
            }
    }
void Game::Update()
    {
        float dt = GetFrameTime();

        // 항상 실행
        enemyManager.Update(player.position, player.radius);
        bulletManager.Update();
        particleManager.Update();
        DebugKey();

        // 게임오버 상태
        if(gameOver)
        {
            if(IsKeyPressed(KEY_R))
                Reset();
            return;
        }

        fireTimer += dt;

        HandleInput();
        player.Update();

        HandleCombat();
        HandleGameState();
    }

void Game::DrawGameWorld()
    {
        Vector2 shake = {0,0};

        if (shakeTimer > 0)
        {
            shake.x = (rand() % 20 - 10);
            shake.y = (rand() % 20 - 10);
        }

        camera.target = {400 + shake.x, 300 + shake.y};

        BeginMode2D(camera);
        player.Draw(); // 플레이어 그리기
        bulletManager.Draw();
        enemyManager.Draw();
        particleManager.Draw();

        EndMode2D();
    }
void Game::DrawUI()
    {
        float hpPercent = (float)player.hp / player.maxHp;
        DrawText(TextFormat("Wave: %i", enemyManager.wave), 10, 100, 20, WHITE);
        DrawText(TextFormat("HP: %i", player.hp), 10, 40, 20, GREEN);
        DrawRectangle(10, 70, 200, 20, DARKGRAY);
        DrawRectangle(10, 70, 200 * hpPercent, 20, GREEN);
        DrawText(TextFormat("Score: %i", score), 10, 10, 20, WHITE);
    }
void Game::DrawGameOver()
    {
        if (gameOver)
            {
                DrawText("Game Over", 300, 250, 40, RED);
                DrawText("Press R to Restart", 250, 300, 30, WHITE);
            }
    }

void Game::Draw()
    {
        DrawGameWorld();
        DrawUI();
        DrawGameOver();
    }