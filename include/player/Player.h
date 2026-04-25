#pragma once
#include "system/WeaponSystem.h"
#include "raylib.h"
#include "raymath.h"

class Player // 플레이어 클래스
    {
        public:
            Vector2 position; // 플레이어 위치
            Vector2 direction; // 플레이어 방향
            float speed; // 플레이어 속도
            float radius; // 플레이어 크기
            float damageTimer; // 받는데미지 전체 시간
            float damageCooldown; // 받는데미지 기다리는 시간
            bool isInvincible; // 플레이어 무적 여부 결정 (true: 무적, false: 무적 없음)

            int maxHp =100; // 플레이어 최대 HP
            int hp = maxHp; // 현재 플레이어 HP
            WeaponType currentWeapon = WeaponType::Normal;
            Player(); // 플레이어 생성자

            void TakeDamage(int amount); // 플레이어가 적에게 데미지 받는 기능
            void Update(); // // 플레이어의 상태 변경을 위한 기능
            void Draw(); // // 플레이어의 현재 상태를 보여주는 기능
    };
