#include "enemy/Enemy.h"
#include <math.h>

Enemy::Enemy(Vector2 pos, EnemyType t) // 적 기본 정보 구현
    {
        position = pos; // 시작 위치
        type = t; // 적 종류

        if(type == EnemyType::Normal) // 적 종류가 Normal일 경우 속도 120, 크기 20, hp 3를 가지고 있음
            {
                speed = 120;
                radius = 20;
                hp = 3;
            }

        if(type == EnemyType::Fast) // 적 종류가 Fast일 경우 속도 220, 크기 15, hp 1를 가지고 있음
            {
                speed = 220;
                radius = 15;
                hp = 1;
            }

        if (type == EnemyType::Tank) // 적 종류가 Tank일 경우 속도 70, 크기 30, hp 5를 가지고 있음
            {
                speed = 70;
                radius = 30;
                hp = 5;
            }
    }

void Enemy::Update(Vector2 playerPos, float playerRadius) // 적 상태 변경 기능 구현
    {
        float dt = GetFrameTime(); // 1 프레임 동안 흐른 시간 변수 dt

        Vector2 dir; // 적 이동방향

        dir.x = playerPos.x - position.x; // 적이 플레이어가 있는 방향으로 x좌표 만큼 이동
        dir.y = playerPos.y - position.y; // 적이 플레이어가 있는 방향으로 y좌표 만큼 이동

        float length = sqrt(dir.x * dir.x + dir.y * dir.y); // 적과 플레이어 사이 거리
        if (length > 0.0001f) // 방향벡터 정규화
            {
                dir.x /= length; // 방향만 남기고 길이를 1로 만듬
                dir.y /= length; // 방향만 남기고 길이를 1로 만듬
            }

        float minDist = radius + playerRadius;

        if (length > minDist)
        {
            position.x += dir.x * speed * dt;
            position.y += dir.y * speed * dt;
        }

    }

void Enemy::Draw() // 적의 현재 상태를 보여주는 기능
    {
        Color color = RED;

        if (type == EnemyType::Fast) // 적 종류가 Fast 일때 오렌지색
            {
                color = ORANGE;
            }

        if (type == EnemyType::Tank) // 적 종류가 Tank 일때 보라색
            {
                color = PURPLE;
            }

        DrawCircleV(position, radius, color); // EnemyType이 결정되면 color에 맞춰 적 상태가 보임
    }