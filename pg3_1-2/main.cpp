#include <stdio.h>
#include<string>
#include"MyList.h"

template<typename T>

int main() {

	int iterator;	//イテレータ
	int inputValue;	//入力用
	bool isThrough_ = true;

	//関数用
	CELL<std::string>* insertCell;
	CELL<std::string>* editCell;
	CELL<std::string>* removeCell;

	//リスト本体
	CELL<std::string> head;
	head.next = nullptr;
	head.prev = nullptr;

	int scene = 0;

	MyList<std::string>list;

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
			list.Index(&head, scene);
			scene = 0;
		}
		else if (scene == 2) {
			printf("---------------------------\n");
			printf("\n要素を追加する場所を指定してください。\n");
			scanf_s("%d", &iterator);

			printf("\n挿入する値を入力してください\n");
			scanf_s("%d", &inputValue);

			insertCell = list.GetInsertCellAddress(&head, iterator, scene, isThrough_);
			list.Create(insertCell, inputValue);

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

			editCell = list.GetInsertCellAddress(&head, iterator, scene, isThrough_);

			if (isThrough_ == true) {
				list.Edit(editCell, inputValue);
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

			removeCell = list.GetInsertCellAddress(&head, iterator, scene, isThrough_);
			if (isThrough_ == true) {
				printf("\n%d番目の要素'%d'を削除しました\n", iterator,removeCell->val);
				list.Remove(removeCell);
			}
			else {
				printf("\n%d番目の要素が見つかりませんでした\n", iterator);
			}

			scene = 0;

		}
		
	}


	return 0;
}



