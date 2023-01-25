#pragma once


class SceneManager final
{

	
private:
	// �R���X�g���N�^,�f�X�g���N�^
	SceneManager();

	~SceneManager();
public:
	// �C���X�^���X
	static SceneManager* GetInstance();

public:
	// �R�s�[�R���X�g���N�^�𖳌��ɂ���
	SceneManager(const SceneManager&) = delete;
	// ������Z�q�𖳌��ɂ���
	SceneManager& operator=(const SceneManager&) = delete;

public:
	
	void ChangeScene(int sceneNum);

	void TitleScene();
	void NewGameScene();
	void GamePlayScene();
	void GameClearScene();
};

