#include <stdio.h>
#include <stdlib.h>
#include "SingleList.h"

//链表初始化
void singleListInit(SingleList* sl) {
	sl->_head = NULL;
}

// 创建节点
Node* creatNode(Type val) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = val;
	node->_next = NULL;
	return node;
}

// 尾插
void singlelistPushBack(SingleList* sl, Type val) {

	if (sl->_head == NULL) {
		Node* node = creatNode(val);
		sl->_head = node;
	}
	else {
		Node* node = creatNode(val);
		Node* last = sl->_head;
		while (last->_next) {
			last = last->_next;
		}  // 遍历完就是尾元素
		last->_next = node;
	}
}

// 尾删
void singleListPopBack(SingleList* sl) {
	// 找到最后一个节点，和前去节点
	if (sl->_head) {
		Node* prev = NULL;
		Node* tail = sl->_head;
		while (tail->_next) {
			prev = tail;
			tail = tail->_next;
		}
		if (tail == sl->_head) {
			sl->_head = NULL;
		}
		else {
			prev->_next = NULL;
		}
		free(tail);
	}
}

// 头插
void singleListPushFront(SingleList* sl, Type val) {
	// Node* node = creatNode(val);      也可以将 创建放在外外边
	if (sl->_head == NULL) {
		sl->_head = creatNode(val); // 如果之前为空，就让头指向这个这个创建的数据
	}
	else {
		Node* node = creatNode(val);  // 如果之前有节点，新创建一个 node  Node指针 
		node->_next = sl->_head;   
		sl->_head = node;
	}

}
// 头删
void singleListPopFront(SingleList* sl) {
	if (sl->_head != NULL) {
		Node* cur = sl->_head;
		sl->_head = cur->_next;
		free(cur);
	}
}

// 插入
void singleListInsertAfter(Node* pos, Type val) {
	Node * Newnode = creatNode(val);
	if (pos->_next == NULL) {
		pos->_next = Newnode;
		Newnode->_next = NULL;
	}
	if (pos->_next){
		Newnode->_next = pos->_next;
		pos->_next = Newnode;
		
	}
}

// 删除
void singleListEraseAfer(Node* pos) {
	Node* posnext;
	if (pos == NULL) {
		return;
	}
// 找到next的下一个节点	
	posnext = pos->_next;
	// 确保posnext不为空
	if (posnext) {
		pos->_next = posnext->_next;
		free(posnext);
	}

}

// 查找
Node* Find(SingleList*sl,Type val) {
	Node* temp= sl->_head;
	while(temp->_next){
		if (temp->_data == val) {
			return temp;
		}		
		temp = temp->_next;
	}	
	return NULL;
}



// 打印
void singleListPrint(SingleList* sl) {
	Node* cur = sl->_head;
	while (cur != NULL) {
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
// 清空
void singleListDestroy(SingleList* sl) {
	Node* cur = sl->_head;
	Node* next;
	while (cur) {
		next = cur->_next;
		free(cur);
		cur = next->_next;
	}
}


/*
Node* FindKthon(SingleList*sl, int k) {
	Node* fast, *slow;
	fast = sl->_head;
	slow = sl->_head;
	for (int i = 0; i < k; i++) {
		fast = fast->_next;
	}
	while (fast!= NULL) {
		fast = fast->_next;
		slow = slow->_next;

	}
	return slow;
}
*/

