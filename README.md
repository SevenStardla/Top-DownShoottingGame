Top-Down Shooter (C++ / raylib)

Features
- Player movement
- Enemy tracking AI
- Collision System
- Weapon System
- Wave System
- Debug key System

Tech
- C++
- raylib

## Directory Structure

```text
Top-DownShooterGame
├── .vscode
│   ├── c_cpp_properties.json
│   ├── launch.json
│   └── tasks.json
│
├── build
│   └── game.exe
│
├── include
│   ├── player
│   │   └── Player.h
│   │
│   ├── enemy
│   │   ├── Enemy.h
│   │   └── EnemyManager.h
│   │
│   ├── bullet
│   │   ├── Bullet.h
│   │   └── BulletManager.h
│   │
│   ├── game
│   │   └── Game.h
│   │
│   ├── particle
│   │   ├── Particle.h
│   │   └── ParticleManager.h
│   │
│   └── system
│       ├── CollisionSystem.h
│       └── WeaponSystem.h
│
└── src
    ├── player
    │   └── Player.cpp
    │
    ├── enemy
    │   ├── Enemy.cpp
    │   └── EnemyManager.cpp
    │
    ├── bullet
    │   ├── Bullet.cpp
    │   └── BulletManager.cpp
    │
    ├── game
    │   └── Game.cpp
    │
    ├── particle
    │   ├── Particle.cpp
    │   └── ParticleManager.cpp
    │
    └── system
        ├── CollisionSystem.cpp
        └── WeaponSystem.cpp
```
