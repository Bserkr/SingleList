#pragma once

typedef int Type; // 用Type代替int

// 定义一个结构体，  即链表的节点
typedef struct Node {
	Type _data;
	struct Node* _next;  // 指向下一个节点
}Node;

// 不带头单向循环链表
typedef struct SingleList {
	Node* _head;
}SingleList;

//链表初始化
void singleListInit(SingleList* sl);

// 创建接节点
Node* creatNode(Type val);
// 尾插
void singlelistPushBack(SingleList* sl, Type val);
// 尾删
void singleListPopBack(SingleList* sl);
// 头插
void singleListPushFront(SingleList* sl, Type val);
// 头删
void singleListPopFront(SingleList* sl);
// 插入
void singleListInsertAfter(Node* pos, Type val);
// 删除
void singleListEraseAfer(Node* pos);
// 查找
Node* Find(SingleList* sl,Type val);
// 打印
void singleListPrint(SingleList* sl);
// 清空
void singleListDestroy(SingleList* sl);





