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
CELL* getInsertCellAddress(CELL* endCell, int iterator, int scene, bool &isThrough);



int main() {

	int iterator;	//イテレータ
	int inputValue;	//入力用
	bool isThrough_ = true;

	//関数用
	CELL* insertCell;
	CELL* editCell;
	CELL* removeCell;

	//リスト本体
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	int scene = 0;

	while (true)
	{
		
		if (scene == 0) {
			printf("---------------------------\n");
			printf("操作を入力してください\n");
			printf("1,要素の表示\n");
			printf("2,要素の挿入\n");
			printf("3,要素の編集\n");
			printf("4,要素の削除\n");
			scanf_s("%d", &scene);
			isThrough_ = true;
		}
		else if (scene == 1) {
			index(&head, scene);
			scene = 0;
		}
		else if (scene == 2) {
			printf("---------------------------\n");
			printf("\n要素を追加する場所を指定してください。\n");
			scanf_s("%d", &iterator);

			printf("\n挿入する値を入力してください\n");
			scanf_s("%d", &inputValue);

			insertCell = getInsertCellAddress(&head, iterator, scene, isThrough_);
			create(insertCell, inputValue);

			if (isThrough_ == true) {
				printf("\n要素%dが%d番目に挿入されました\n", inputValue, iterator);
			}
			else {
				printf("\n要素%dが最後尾に挿入されました\n", inputValue);
			}

			scene = 0;
		}
		else if (scene == 3) {
			printf("---------------------------\n");
			printf("\n編集したい要素の番号を指定してください\n");
			scanf_s("%d", &iterator);

			printf("\n%d番目の要素を変更する値を入力してください\n", iterator);
			scanf_s("%d", &inputValue);

			editCell = getInsertCellAddress(&head, iterator, scene, isThrough_);

			if (isThrough_ == true) {
				edit(editCell, inputValue);
				printf("\n%d番目の要素が%dに変更されました\n", iterator, inputValue);
			}
			else {
				printf("\n%d番目の要素が見つかりませんでした\n" ,iterator);
			}

			scene = 0;

		}
		else if (scene == 4) {
			printf("\n何番目のセルを削除しますか？\n");
			scanf_s("%d", &iterator);

			removeCell = getInsertCellAddress(&head, iterator, scene, isThrough_);
			if (isThrough_ == true) {
				printf("\n%d番目の要素'%d'を削除しました\n", iterator,removeCell->val);
				remove(removeCell);
			}
			else {
				printf("\n%d番目の要素が見つかりませんでした\n", iterator);
			}

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
			printf("[要素の表示]\n");
			printf("1,要素の一覧表示\n");
			printf("2,順番を指定して要素を表示\n");
			printf("9,要素検索に戻る\n");
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
			printf("表示したい要素の順番を指定してください\n");
			scanf_s("%d", &numSelect);

			printf("---------------------------\n");
			bool whether = true;
			CELL* printCell;
			printCell = endCell;
			for (int i = 0; i < numSelect; i++)
			{
				if (printCell->next) {
					printCell = printCell->next;
				}
				else {
					if (whether == true) {
						whether = false;
					}
					break;
				}


			}
			if (whether == true) {
				printf("%d :", numSelect);
				printf("%d\n", printCell->val);
			}
			else {
				printf("%d番目の要素が見つかりませんでした\n", numSelect);
			}

			printf("---------------------------\n");
		}
		else if (sceneSelect == 9) {
			scene = 0;
		}
		printf("1,要素の表示に戻る\n");
		printf("2,要素の操作に戻る\n");
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



CELL* getInsertCellAddress(CELL* endCell, int iterator, int scene, bool &isThrough)
{
	

	for (int i = 0; i < iterator; i++) {

		if (endCell->next) {
			endCell = endCell->next;
			isThrough = true;
		}
		else {
			isThrough = false;
			if (i + 1 == iterator) {
				isThrough = true;
			}
			break;
		}

		
	}

	return endCell;
}
