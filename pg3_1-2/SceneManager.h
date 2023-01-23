#pragma once
#include"Singleton.h"

class SceneManager :public Singleton<SceneManager>
{
	friend Singleton<SceneManager>;
private:
	// コンストラクタ,デストラクタ
	SceneManager();

	~SceneManager();
public:
	
	void ChangeScene(int sceneNum);

	void TitleScene();
	void NewGameScene();
	void GamePlayScene();
	void GameClearScene();
};

