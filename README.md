# Top-Down Shooting Game

C++과 raylib을 사용해 제작한 2D 탑다운 슈팅 게임입니다.
웨이브 진행, 충돌 처리, 여러 무기 타입과 매니저 기반 구조를 중심으로 구성했습니다.

## Features

- Player movement
- Enemy tracking AI
- Collision system
- Weapon system
- Wave system
- Particle effects

## Tech

- C++
- raylib
- Visual Studio Code

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

## Game Loop

`main.cpp`는 초기화와 메인 루프를 담당하고, `Game` 클래스가 각 Manager와 System의 업데이트 및 렌더링 순서를 관리합니다.

## Troubleshooting

### 문제1: 총알 삭제 후 다음 요소를 건너뛰는 문제

원인:

- `std::vector`에서 총알을 `erase()`하면 뒤의 요소들이 앞으로 이동함
- 삭제 직후 인덱스를 증가시키면 다음 총알을 검사하지 않고 넘어갈 수 있음

해결:

- 총알이 삭제된 경우 `removed` 플래그를 사용해 인덱스를 증가시키지 않도록 처리
- 삭제되지 않은 경우에만 다음 총알로 이동하도록 반복문을 구성

### 문제2: 관통탄이 같은 적과 반복 충돌하는 문제

원인:

- 관통탄이 적과 충돌한 뒤에도 적의 충돌 범위 안에 남아 있으면 같은 적을 다시 타격할 가능성이 있었음

해결:

- 적과 충돌할 때마다 `penetration` 값을 감소
- 충돌 후 총알을 진행 방향 기준으로 적의 충돌 범위 바깥으로 이동
- 남은 관통 횟수가 0이 되면 총알을 제거
