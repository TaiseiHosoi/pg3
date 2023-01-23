#pragma once
#include"Singleton.h"

class SceneManager :public Singleton<SceneManager>
{
	friend Singleton<SceneManager>;
private:
	// �R���X�g���N�^,�f�X�g���N�^
	SceneManager();

	~SceneManager();
public:
	
	void ChangeScene(int sceneNum);

	void TitleScene();
	void NewGameScene();
	void GamePlayScene();
	void GameClearScene();
};

