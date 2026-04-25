#pragma once
#include "player/Player.h"
#include "bullet/BulletManager.h"
#include "enemy/EnemyManager.h"
#include "particle/ParticleManager.h"
#include "system/WeaponSystem.h"

class Game
    {
        public:
            Player player;
            BulletManager bulletManager;
            EnemyManager enemyManager;
            ParticleManager particleManager;
            WeaponSystem weaponSystem;
            Camera2D camera;

            int score = 0;
            bool gameOver = false;

            float fireTimer = 0;
            float fireInterval = 0.2f;
            float shakeTimer = 0;
            float shakeDuration = 0.2f;
            float shakePower = 10.0f;

            Game();
            void HandleInput();
            void UpdateSystems();
            void HandleCombat();
            void HandleGameState();
            void HandleGameOver();
            void TriggerShake();
            void Reset();
            void Update();
            void DebugKey();

            void DrawGameWorld();
            void DrawUI();
            void DrawGameOver();
            void Draw();
    };