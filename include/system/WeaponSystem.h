#pragma once
#include "bullet/bulletManager.h"
#include "raylib.h"

enum class WeaponType
    {
        Normal,
        Spread,
        Fast
    };

class WeaponSystem
{
    public:
        void Shoot(WeaponType type,BulletManager& bullets,Vector2 position ,Vector2 direction);

};