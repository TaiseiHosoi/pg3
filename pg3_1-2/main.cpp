#include <functional>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include"windows.h"

#include"Singleton.h"
#include"SceneManager.h"


int main()
{

    SceneManager& sceneManager_ = SceneManager::GetInstance();
   

    enum scene {
        Title,  // 0
        NewGame,    // 1
        GamePlay,   // 2
        GameClear   // 3
    };

    int sceneNum_ = Title;

    while (true) {
        if (sceneNum_ > GameClear) {
            sceneNum_ = Title;
        }
        else {
            sceneNum_++;
        }

        sceneManager_.ChangeScene(sceneNum_);

        Sleep(3000); // 3•bƒXƒŠ[ƒv
    }


    system("pause");
    return 0;
}