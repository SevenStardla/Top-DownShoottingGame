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

## Architecture

- `Player` : 플레이어 입력 및 상태 관리
- `BulletManager` : 총알 생성, 업데이트, 삭제 관리
- `EnemyManager` : 적 생성 및 행동 관리
- `CollisionSystem` : 객체 간 충돌 감지 및 처리
- `WeaponSystem` : 무기 발사 로직 관리
- `ParticleManager` : 파티클 및 이펙트 관리
