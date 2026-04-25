#include "system/WeaponSystem.h"
#include <cmath>

void WeaponSystem::Shoot(WeaponType type,BulletManager& bullets,Vector2 position ,Vector2 direction)
    {
        if(type == WeaponType::Normal)
            {
                bullets.Shoot(position, direction,500.0f, 1);
            }

        else if(type == WeaponType::Spread)
            {
                float angle = 0.35f;

                Vector2 dir1 = direction;

                Vector2 dir2 =
                {
                    direction.x * cos(angle) - direction.y * sin(angle),
                    direction.x * sin(angle) + direction.y * cos(angle)
                };

                Vector2 dir3 =
                {
                    direction.x * cos(-angle) - direction.y * sin(-angle),
                    direction.x * sin(-angle) + direction.y * cos(-angle)
                };

                bullets.Shoot(position, dir1,500.0f, 1);
                bullets.Shoot(position, dir2,500.0f, 1);
                bullets.Shoot(position, dir3,500.0f, 1);
            }

        else if(type == WeaponType::Fast)
            {
                Vector2 fastDir =
                {
                    direction.x * 1.5f,
                    direction.y * 1.5f
                };

                bullets.Shoot(position, fastDir,800.0f, 3);
            }
    }