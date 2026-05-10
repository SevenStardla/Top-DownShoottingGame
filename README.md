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

File Directory structure
.vscode
    ㄴ c_cpp_properties.json
    ㄴ launch.json
    ㄴ tasks.json
build
    ㄴ game.exe
include
    ㄴplayer
        ㄴ Player.h
    ㄴ enemy
        ㄴ Enemy.h
        ㄴ EnemyManager.h
    ㄴ bullet
        ㄴ Bullet.h
        ㄴ BulletManager.h
    ㄴ game
        ㄴ Game.h
    ㄴ particle
         ㄴ Particle.h
         ㄴ ParticleManager.h
    ㄴ system
         ㄴ CollisionSystem.h
         ㄴ WeaponSystem.h
src
    ㄴplayer
        ㄴ Player.cpp
    ㄴ enemy
        ㄴ Enemy.cpp
        ㄴ EnemyManager.cpp
    ㄴ bullet
        ㄴ Bullet.cpp
        ㄴ BulletManager.cpp
    ㄴ game
        ㄴ Game.cpp
    ㄴ particle
         ㄴ Particle.cpp
         ㄴ ParticleManager.cpp
    ㄴ system
         ㄴ CollisionSystem.cpp
         ㄴ WeaponSystem.cpp
