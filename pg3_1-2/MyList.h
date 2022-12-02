#pragma once
#include<iostream>
#include<stdio.h>

template<typename T>
struct CELL{

	T val;
	struct CELL* prev;
	struct CELL* next;


};

template<class T>
class MyList {
public:
	
	void Create(CELL<T>* currentCell, T val)
	{
		CELL<T>* newCell;
		newCell = (CELL<T>*)malloc(sizeof(CELL));
		newCell->val = val;
		newCell->prev = currentCell;
		newCell->next = currentCell->next;

		if (currentCell->next) {
			CELL<T>* nextCell = currentCell->next;
			nextCell->prev = newCell;
		}

		currentCell->next = newCell;
	}

	void Edit(CELL<T>* currentCell, T val)
	{
		currentCell->val = val;

	}


	void Remove(CELL<T>* currentCell)
	{
		currentCell->prev->next = currentCell->next;
		currentCell->next->prev = currentCell->next;

		delete currentCell;

	}

	void Index(CELL<T>* endCell, int& scene)
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
				CELL<T>* printCell;
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



	CELL<T>* GetInsertCellAddress(CELL<T>* endCell, int iterator, int scene, bool& isThrough)
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
};