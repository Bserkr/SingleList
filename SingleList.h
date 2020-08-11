#pragma once

typedef int Type; // ��Type����int

// ����һ���ṹ�壬  ������Ľڵ�
typedef struct Node {
	Type _data;
	struct Node* _next;  // ָ����һ���ڵ�
}Node;

// ����ͷ����ѭ������
typedef struct SingleList {
	Node* _head;
}SingleList;

//�����ʼ��
void singleListInit(SingleList* sl);

// �����ӽڵ�
Node* creatNode(Type val);
// β��
void singlelistPushBack(SingleList* sl, Type val);
// βɾ
void singleListPopBack(SingleList* sl);
// ͷ��
void singleListPushFront(SingleList* sl, Type val);
// ͷɾ
void singleListPopFront(SingleList* sl);
// ����
void singleListInsertAfter(Node* pos, Type val);
// ɾ��
void singleListEraseAfer(Node* pos);
// ����
Node* Find(SingleList* sl,Type val);
// ��ӡ
void singleListPrint(SingleList* sl);
// ���
void singleListDestroy(SingleList* sl);





