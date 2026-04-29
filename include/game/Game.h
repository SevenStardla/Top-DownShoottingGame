#pragma once
#include "player/Player.h"
#include "bullet/BulletManager.h"
#include "enemy/EnemyManager.h"
#include "particle/ParticleManager.h"
#include "system/WeaponSystem.h"

// Game 클래스는 게임의 모든 시스템(Player, Enemy, Bullet 등)을 관리하는 중심 클래스이다.
// 각 Manager와 시스템을 업데이트하고 최종적으로 main.cpp에서 게임 루프를 통해 실행된다.
class Game
    {
        public:
        // 게임 시스템 매니저
            Player player;
            BulletManager bulletManager;
            EnemyManager enemyManager;
            ParticleManager particleManager;
            WeaponSystem weaponSystem;

        // 게임 월드를 렌더링하기 위한 2D 카메라 (raylib Camera2D)
            Camera2D camera;


            int score = 0; // 플레이어 점수
            bool gameOver = false; // 게임 종료 상태

            float fireTimer = 0;
            float fireInterval = 0.2f;
            // 총알 발사 쿨타임 관리

            float shakeTimer = 0;
            float shakeDuration = 0.2f;
            float shakePower = 10.0f;
            // 화면 흔들림(Camera Shake)효과 관리

            Game(); // 플레이어가 게임을 시작하는 시점을 정할 수 있도록 하기 위함이다.
            void HandleInput(); // 플레이어 입력 처리
            void UpdateSystems(); // Bullet, Enemy, Particle 등 게임 시스템 업데이트
            void HandleCombat(); // 충돌 처리 (Bullet vs Enemy, Enemy vs Player)
            void HandleGameState(); // 게임 상태 관리 (GameOver 등)
            void HandleGameOver(); // 게임 오버상태만을 핸들링하기 위함이다.
            void TriggerShake(); // 화면 흔들림 효과 시작
            void Reset(); // 게임 상태 초기화
            void Update(); // 게임 로직 업데이트 (프레임마다 호출)
            void DebugKey(); // 디버그용 입력 처리

            void DrawGameWorld(); // 게임 월드 렌더링
            void DrawUI(); // UI 렌더링
            void DrawGameOver(); // 게임오버 화면 렌더링
            void Draw(); // 전체화면 렌더링
    };