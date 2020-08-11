#include <stdio.h>
#include <stdlib.h>
#include "SingleList.h"

void test() {
	SingleList sl;
	singleListInit(&sl);
	singleListPushFront(&sl, 1);
	singleListPushFront(&sl, 2);
	singleListPushFront(&sl, 3);
	singleListPushFront(&sl, 4);
	singleListPushFront(&sl, 5);
	singleListPushFront(&sl, 6);
	singleListPrint(&sl);
	singleListPopFront(&sl);
	singleListPrint(&sl);
	Node* pos1 = Find(&sl, 3);
	singleListInsertAfter(pos1, 50);
	singleListPrint(&sl);
	Node* pos2 = Find(&sl, 5);
	singleListEraseAfer(pos2);
	singleListPrint(&sl);

}

int main() {

	test();
	system("pause");
	return 0;
}