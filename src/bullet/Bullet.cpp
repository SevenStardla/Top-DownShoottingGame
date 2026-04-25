#include "bullet/Bullet.h"

Bullet::Bullet(Vector2 startPos, Vector2 dir, float speed, int penetration) // 총알 정보
    {
        position = startPos; // 총알 시작 위치
        velocity = Vector2Scale(dir, speed);
        radius = 5.0f; // 총알 크기

        this->penetration = penetration;
    }

void Bullet::Update() // 총알 상태 변경 기능
    {
        float dt = GetFrameTime(); // 1 프레임 동안 흐른 시간 변수 dt

        position.x += velocity.x * dt; // 1 프레임 만큼 x좌표 총알 위치 변경
        position.y += velocity.y * dt; // 1 프레임 만큼 y좌표 총알 위치 변경
    }

void Bullet::Draw() // 총알의 현재 상태를 보여주는 기능
    {
        DrawCircleV(position, radius, YELLOW); // 총알의 색은 노랑색
    }