#include "player/Player.h"

Player::Player() // 플레이어가 가질 수 있는 데이터목록
    {
        maxHp = 100;
        hp = maxHp;
//  플레이어의 최대체력을 보존하고 hp가 깎일 것을 대비하여 hp의 두가지 변수를 선언
        position = {400, 300}; // 플레이어 시작위치를 대략 화면 중앙에 설정해 사방으로 오는 적들을 대비할 수 있도록 시작위치를 다음과 같이 설정함
        speed = 300.0f; // 플레이어 이동 속도
        radius = 20.0f; // 플레이어 크기

        isInvincible = false; // 플레이어가 필요하지 않은 상황에 무적을 받을 수 있는 경우를 고려하여 기본값을 false로 설정

        damageCooldown = 0.5f; // 설정하지 않으면 프레임 단위 현재 60fps 설정 만큼 1초에 60번 데미지를 받게됨 / 탑 다운 슈팅게임에서 가장 필요한 변수 중 하나라고 볼 수 있음
        damageTimer = 0; // damageCooldown의 시간을 받아서 이 damageTimer가 0이상이면 무적을 받을 수 있게 설정

    }

void Player::TakeDamage(int amount) // 플레이어가 적에게 데미지 받는 기능
    {
        float dt = GetFrameTime();
        if(isInvincible) // 무적이면
            {
                damageTimer -= dt;
            }

        if (damageTimer <= 0)
            {
                isInvincible = false;
            }
        hp -= amount; // 데미지 받으면 데미지 amount 만큼 hp 감소

        damageTimer = damageCooldown; // 다음에 데미지 받는 시간을 damageTimer에 적용
        isInvincible = true; // 무적 판정
    }

void Player::Update() // 플레이어의 상태 변경을 위한 기능
    {
        float dt = GetFrameTime(); // 1 프레임 동안 흐른 시간 변수 dt

        if (damageTimer > 0) // 데미지 시간이 있으면
            {
                damageTimer -= dt; // 프레임 단위만큼 다음 데미지 기다리는 시간을 차감
            }
        else // 데미지 시간이 없으면
            {
                isInvincible = false; // 데미지 시간 쿨이 없으면 무적 없음
            }

        if (IsKeyDown(KEY_A)) position.x -= speed * dt; // A a 를 계속 누를때 마다 왼쪽으로 이동
        if (IsKeyDown(KEY_W)) position.y -= speed * dt; // W w 를 계속 누를때 마다 위로 이동
        if (IsKeyDown(KEY_S)) position.y += speed * dt; // S s 를 계속 누를때 마다 아래로 이동
        if (IsKeyDown(KEY_D)) position.x += speed * dt; // D d 를 계속 누를때 마다 오른쪽으로 이동

        Vector2 mouse = GetMousePosition();

        Vector2 dir = Vector2Subtract(mouse, position);

        float length = Vector2Length(dir);

        if(length > 0.0001f)
            {
                direction = Vector2Normalize(dir);
            }
        if(hp == 0)
            {
                hp = 0;
            }
    }

void Player::Draw() // 플레이어의 현재 상태를 보여주는 기능
    {
        Color color = BLUE; // 플레이어의 색은 파랑

        if (isInvincible) // isInvincible != 0과 동일 isInvincible = True, 무적
            {
                if(((int)(damageTimer * 10)) % 2 == 0) // 데미지 시간을 정수 단위로 단계를 쪼개서(0.9 -> 9, 0.8 -> 8, 0.7 -> 7) 플레이어가 적에게 피격시 흰색으로 깜빡이는 효과
                    {
                        color = WHITE;
                    }
            }
        DrawCircleV(position, radius, color); // 플레이어를 나타내는 원 하나 그리기
    }