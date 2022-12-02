#include <stdio.h>
#include<string>
#include"MyList.h"

template<typename T>

int main() {

	int iterator;	//�C�e���[�^
	int inputValue;	//���͗p
	bool isThrough_ = true;

	//�֐��p
	CELL<std::string>* insertCell;
	CELL<std::string>* editCell;
	CELL<std::string>* removeCell;

	//���X�g�{��
	CELL<std::string> head;
	head.next = nullptr;
	head.prev = nullptr;

	int scene = 0;

	MyList<std::string>list;

	while (true)
	{
		
		if (scene == 0) {
			printf("---------------------------\n");
			printf("�������͂��Ă�������\n");
			printf("1,�v�f�̕\��\n");
			printf("2,�v�f�̑}��\n");
			printf("3,�v�f�̕ҏW\n");
			printf("4,�v�f�̍폜\n");
			scanf_s("%d", &scene);
			isThrough_ = true;
		}
		else if (scene == 1) {
			list.Index(&head, scene);
			scene = 0;
		}
		else if (scene == 2) {
			printf("---------------------------\n");
			printf("\n�v�f��ǉ�����ꏊ���w�肵�Ă��������B\n");
			scanf_s("%d", &iterator);

			printf("\n�}������l����͂��Ă�������\n");
			scanf_s("%d", &inputValue);

			insertCell = list.GetInsertCellAddress(&head, iterator, scene, isThrough_);
			list.Create(insertCell, inputValue);

			if (isThrough_ == true) {
				printf("\n�v�f%d��%d�Ԗڂɑ}������܂���\n", inputValue, iterator);
			}
			else {
				printf("\n�v�f%d���Ō���ɑ}������܂���\n", inputValue);
			}

			scene = 0;
		}
		else if (scene == 3) {
			printf("---------------------------\n");
			printf("\n�ҏW�������v�f�̔ԍ����w�肵�Ă�������\n");
			scanf_s("%d", &iterator);

			printf("\n%d�Ԗڂ̗v�f��ύX����l����͂��Ă�������\n", iterator);
			scanf_s("%d", &inputValue);

			editCell = list.GetInsertCellAddress(&head, iterator, scene, isThrough_);

			if (isThrough_ == true) {
				list.Edit(editCell, inputValue);
				printf("\n%d�Ԗڂ̗v�f��%d�ɕύX����܂���\n", iterator, inputValue);
			}
			else {
				printf("\n%d�Ԗڂ̗v�f��������܂���ł���\n" ,iterator);
			}

			scene = 0;

		}
		else if (scene == 4) {
			printf("\n���Ԗڂ̃Z�����폜���܂����H\n");
			scanf_s("%d", &iterator);

			removeCell = list.GetInsertCellAddress(&head, iterator, scene, isThrough_);
			if (isThrough_ == true) {
				printf("\n%d�Ԗڂ̗v�f'%d'���폜���܂���\n", iterator,removeCell->val);
				list.Remove(removeCell);
			}
			else {
				printf("\n%d�Ԗڂ̗v�f��������܂���ł���\n", iterator);
			}

			scene = 0;

		}
		
	}


	return 0;
}



