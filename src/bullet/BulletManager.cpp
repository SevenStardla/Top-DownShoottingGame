#include "bullet/BulletManager.h"

void BulletManager::Shoot(Vector2 start, Vector2 dir, float speed,int penetration) // 총알 발사 기능
    {
        bullets.emplace_back(Bullet(start, dir, speed, penetration)); // 총알 객체를 총알들을 저장하는 공간 맨 뒤로 보냄
    }

void BulletManager::Update() // 총알 관리 상태 변경 기능
    {
        for (auto& bullet : bullets) // 모든 총알 객체를 확인
            {
                bullet.Update(); // 총알 객체의 상태를 변경
            }

            for (size_t x = 0; x < bullets.size(); x++) // 모든 총알의 개수(bullets.size())를 확인
                {
                    if(bullets[x].position.x < 0 || bullets[x].position.x > 800 || bullets[x].position.y < 0 || bullets[x].position.y > 600) // 정해진 화면 밖으로 나가는 경우
                        {
                            bullets.erase(bullets.begin() + x); // bullets의 동적배열 시작위치에서 x 칸 이동한 위치에 있는 칸 삭제
                            x--; // 삭제한 후 남은 객체들은 앞당겨지기 때문에 이전 객체를 다시 검사하기 위한 목적
                        }
                }
    }

void BulletManager::Draw() // 총알 관리 상태를 보여주는 기능
    {
        for (auto& bullet : bullets)
            {
                bullet.Draw(); // 총알 그리기
            }
    }