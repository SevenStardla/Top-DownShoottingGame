#include "raylib.h"
#include "game/Game.h"
#include <random>
#include <ctime>
// #include "Player.h"
// #include "Bullet.h"
// #include "Enemy.h"
// #include "math.h"
// #include "BulletManager.h"
// #include "EnemyManager.h"
// #include "CollisionSystem.h"
// #include <cstdlib>
// #include <vector>



int main()
    {
        srand(time(NULL));
        InitWindow(800, 600, "Shooter"); // Shooter 라는 이름의 윈도우 창 생성

        SetTargetFPS(60); // 60 fps 설정

        Game game;

        while (!WindowShouldClose()) // 윈도우 창이 꺼지지 않을 때 까지 반복
        {
            game.Update();

            BeginDrawing(); // 그리기 시작
            ClearBackground(BLACK); // 배경을 검은색으로 지정

            game.Draw();

            EndDrawing(); // 그리기 종료
        }

        CloseWindow(); // 윈도우 창 종료
    }