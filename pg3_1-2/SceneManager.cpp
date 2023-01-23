#include "SceneManager.h"
#include <stdio.h>

SceneManager::~SceneManager()
{
}

void SceneManager::ChangeScene(int sceneNum)
{
	switch (sceneNum)
	{
	case 0:
		TitleScene();
		break;
	case 1:
		NewGameScene();
		break;
	case 2:
		GamePlayScene();
		break;
	case 3:
		GameClearScene();
		break;
	default:
		break;
	}
}

void SceneManager::TitleScene()
{
	printf("Title\n");
}

void SceneManager::NewGameScene()
{
	printf("NewGame\n");
}

void SceneManager::GamePlayScene()
{
	printf("GameScene\n");
}

void SceneManager::GameClearScene()
{
	printf("GameClear\n");
}
