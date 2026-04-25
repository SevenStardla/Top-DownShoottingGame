#pragma once
#include "raylib.h"

enum class EnemyType // 적 종류
    {
        Normal, // 기본 적
        Fast, // 빠른 속도의 적
        Tank // 체력이 높은 적
    };

class Enemy // 적 클래스
    {
        public:
            Vector2 position; // 적 위치
            float speed; // 적 속도
            float radius; // 적 크기

            int hp; // 적이 가지고 있는 hp

            EnemyType type; // 적 종류를 가지고 있는 enum class 변수 type

            Enemy(Vector2 pos, EnemyType t); // 적 정보

            void Update(Vector2 playerPos, float playerRadius); // 적 상태 업데이트
            void Draw(); // 현재 적 상태 화면에 보여주기
    };