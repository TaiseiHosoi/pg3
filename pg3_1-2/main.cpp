#include <functional>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include"windows.h"

#include"Enemy.h"

bool Enemy::isAlive;

int main()
{
    
    Enemy* enemy1 = new Enemy;
    Enemy* enemy2 = new Enemy;
    Enemy* enemy3 = new Enemy;

    enemy1->Initialize();
    enemy2->Initialize();
    enemy3->Initialize();

    // �I���̃J�E���g�_�E��
    int finalCountdown = 3;



    //�Q�[���V�[��
    while (true) {
        
        finalCountdown--;

        if (finalCountdown <= 0) {
            Enemy::isAlive = false;
        }

        enemy1->Draw();
        enemy2->Draw();
        enemy3->Draw();
        Sleep(1000); // 1�b�X���[�v
    }


    system("pause");
    return 0;
}