#pragma once


class SceneManager final
{

	
private:
	// コンストラクタ,デストラクタ
	SceneManager();

	~SceneManager();
public:
	// インスタンス
	static SceneManager* GetInstance();

public:
	// コピーコンストラクタを無効にする
	SceneManager(const SceneManager&) = delete;
	// 代入演算子を無効にする
	SceneManager& operator=(const SceneManager&) = delete;

public:
	
	void ChangeScene(int sceneNum);

	void TitleScene();
	void NewGameScene();
	void GamePlayScene();
	void GameClearScene();
};

