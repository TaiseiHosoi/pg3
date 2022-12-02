#include <stdio.h>
#include<stdlib.h>
#include <list>
#include <iostream>

typedef struct cell {
	int val;
	struct cell* prev;
	struct cell* next;


}CELL;

void create(CELL* currentCell, int val);
void edit(CELL* currentCell, int val);
void remove(CELL* currentCell);
void index(CELL* endCell, int& scene);
CELL* getInsertCellAddress(CELL* endCell, int iterator, int scene);



int main() {

	int iterator;	//�C�e���[�^
	int inputValue;	//���͗p

	//�֐��p
	CELL* insertCell;
	CELL* editCell;
	CELL* removeCell;

	//���X�g�{��
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	int scene = 0;



	while (true)
	{
		if (scene == 0) {
			printf("---------------------------\n");
			printf("�������͂��Ă�������\n");
			printf("1,�v�f�̕\��\n");
			printf("2,�v�f�̑}��\n");
			printf("3,�v�f�̕ҏW\n");
			printf("4,�v�f�̍폜\n");
			printf("5,�v�f�̕��ёւ�\n");
			scanf_s("%d", &scene);
		}
		else if (scene == 1) {
			index(&head, scene);
			scene = 0;
		}
		else if (scene == 2) {
			printf("---------------------------\n");
			printf("\n���Ԗڂ̃Z���̌��ɑ}�����܂����H\n");
			scanf_s("%d", &iterator);

			printf("\n�}������l����͂��Ă�������\n");
			scanf_s("%d", &inputValue);

			insertCell = getInsertCellAddress(&head, iterator,scene);
			create(insertCell, inputValue);

			scene = 0;
		}
		else if (scene == 3) {
			printf("---------------------------\n");
			printf("\n���Ԗڂ̃Z����ҏW���܂����H\n");
			scanf_s("%d", &iterator);

			printf("\n�}������l����͂��Ă�������\n");
			scanf_s("%d", &inputValue);

			editCell = getInsertCellAddress(&head, iterator,scene);
			edit(editCell, inputValue);

			scene = 0;

		}
		else if (scene == 4) {
			printf("\n���Ԗڂ̃Z�����폜���܂����H\n");
			scanf_s("%d", &iterator);

			removeCell = getInsertCellAddress(&head, iterator,scene);
			remove(removeCell);

			scene = 0;

		}
	}


	return 0;
}


void create(CELL* currentCell, int val)
{
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next) {
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	currentCell->next = newCell;
}

void edit(CELL* currentCell, int val)
{
	currentCell->val = val;

}


void remove(CELL* currentCell)
{
	currentCell->prev->next = currentCell->next;
	currentCell->next->prev = currentCell->next;

	delete currentCell;

}

void index(CELL* endCell, int& scene)
{
	
	int sceneSelect = 0;

	while (true)
	{
		int no = 1;
		if (sceneSelect == 0) {
			printf("[�v�f�̕\��]\n");
			printf("1,�v�f�̈ꗗ�\��\n");
			printf("2,���Ԃ��w�肵�ėv�f��\��\n");
			printf("9,�v�f�����ɖ߂�\n");
			scanf_s("%d", &sceneSelect);
		}
		if (sceneSelect == 1) {
			printf("---------------------------\n");

			while (endCell->next != nullptr)
			{
				endCell = endCell->next;
				printf("%d :", no);
				printf("%d\n", endCell->val);

				no++;
			}
			printf("---------------------------\n");
		}
		else if (sceneSelect == 2) {
			int numSelect;
			printf("�\�����������Ԃ���͂��Ă�������\n");
			scanf_s("%d", &numSelect);

			printf("---------------------------\n");
			bool whether = true;
			for (int i = 1; i < numSelect-1; i++) 
			{
				if (endCell->next) {
					endCell = endCell->next;
				}
				else {
					
					break;
				}
				
				
			}
			if (whether == true) {
				printf("%d :", numSelect);
				printf("%d\n", endCell->val);
			}
			
			printf("---------------------------\n");
		}
		else if (sceneSelect == 9) {
			scene = 0;
		}
		printf("1,�v�f�̕\���ɖ߂�\n");
		printf("2,�v�f�̑���ɖ߂�\n");
		int val;
		scanf_s("%d", &val);
		if (val == 1) {
			sceneSelect = 0;
		}
		else if (val == 2) {
			scene = 0;
			break;
		}
	}

}



CELL* getInsertCellAddress(CELL* endCell, int iterator,int scene)
{
	for (int i = 0; i < iterator; i++) {
		if (endCell->next) {
			endCell = endCell->next;
		}
		else {
			if (scene == 3 || scene == 4) {
				printf("�T���Ă���v�f��������܂���\n");
			}
			break;
		}
	}
	return endCell;
}
