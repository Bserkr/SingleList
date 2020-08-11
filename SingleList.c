#include <stdio.h>
#include <stdlib.h>
#include "SingleList.h"

//�����ʼ��
void singleListInit(SingleList* sl) {
	sl->_head = NULL;
}

// �����ڵ�
Node* creatNode(Type val) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = val;
	node->_next = NULL;
	return node;
}

// β��
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
		}  // ���������βԪ��
		last->_next = node;
	}
}

// βɾ
void singleListPopBack(SingleList* sl) {
	// �ҵ����һ���ڵ㣬��ǰȥ�ڵ�
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

// ͷ��
void singleListPushFront(SingleList* sl, Type val) {
	// Node* node = creatNode(val);      Ҳ���Խ� �������������
	if (sl->_head == NULL) {
		sl->_head = creatNode(val); // ���֮ǰΪ�գ�����ͷָ������������������
	}
	else {
		Node* node = creatNode(val);  // ���֮ǰ�нڵ㣬�´���һ�� node  Nodeָ�� 
		node->_next = sl->_head;   
		sl->_head = node;
	}

}
// ͷɾ
void singleListPopFront(SingleList* sl) {
	if (sl->_head != NULL) {
		Node* cur = sl->_head;
		sl->_head = cur->_next;
		free(cur);
	}
}

// ����
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

// ɾ��
void singleListEraseAfer(Node* pos) {
	Node* posnext;
	if (pos == NULL) {
		return;
	}
// �ҵ�next����һ���ڵ�	
	posnext = pos->_next;
	// ȷ��posnext��Ϊ��
	if (posnext) {
		pos->_next = posnext->_next;
		free(posnext);
	}

}

// ����
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



// ��ӡ
void singleListPrint(SingleList* sl) {
	Node* cur = sl->_head;
	while (cur != NULL) {
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
// ���
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

