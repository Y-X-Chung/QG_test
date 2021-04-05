#include"duLinkedList.h"
#include<iostream>
using namespace std;

Status InitList_DuL(DuLinkedList* L)                       //创建链表
{
	(*L) = new DuLNode;
	(*L)->next = NULL;
	return SUCCESS;
}

void DestroyList_DuL(DuLinkedList* L)                         //销毁链表
{
	DuLNode* p;
	while (*L)
	{
		p = (*L)->next;
		delete(*L);
		L = &p;
	}
}

DuLNode* InsertList_position(int n, DuLinkedList L)          //销毁链表
{
	DuLinkedList p = L;
	for (int i = 2;i <= n;i++)
	{
		p = p->next;
	}
	return p;
}
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)             //插入
{
	p->prior->next = q;
	q->prior = p->prior;
	p->prior = q;
	q->next = p;
	return SUCCESS;
}

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	if (p == NULL || q == NULL) return ERROR;
	q->next = p->next;
	p->next = q;
	q->prior = p;
	return SUCCESS;
}

DuLNode* Deletelist_position(DuLinkedList L, ElemType e)          //找到删除点p的位置
{
	DuLinkedList p = L;
	while (p->next)
	{
		if (p->next->data == e)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

//LNode* Deletelist_position(int n,LinkedList L)                  
//{
//	int i = 1;
//	LinkedList p = L;
//	for (int i = 1;i <= n;i++)
//	{
//		p = p->next;
//	}
//	return p;
//}

Status DeleteList(DuLNode* p, ElemType* e) 						//删掉p的下一个节点，把这个节点的值给e
{
	*e = p->next->data;
	DuLinkedList q;
	q = p->next;
	p->next = q->next;
	delete(q);
	return SUCCESS;
}

void COUTLIST(ElemType e)                                          //打印链表
{
	cout << e << " ";
	return;
}

void TraverseList(DuLinkedList L, void (*visit)(ElemType e))			//遍历链表
{
	DuLinkedList p;
	p = L->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	return;
}

Status SearchList(DuLinkedList L, ElemType e)					         //在链表中查找数据e
{
	int n = 0;
	while (L->data != e)
	{
		L = L->next;
		n++;
		if (L == NULL)
		{
			return ERROR;
		}
	}
	return SUCCESS;
}

Status ReverseList(DuLinkedList* L)
{
	return SUCCESS;
}

Status IsLoopList(DuLinkedList L)
{
	return SUCCESS;
}

DuLNode* ReverseEvenList(DuLinkedList* L)
{
	return NULL;
}

DuLNode* FindMidNode(DuLinkedList* L)
{
	return NULL;
}

int main()
{
	DuLinkedList L = NULL;
	DuLNode* Node;
	ElemType i, j;
	int n, p, choice;
	while (1) {
		//for (int i = 1; i <= 10; ++i) cout << endl;
		cout << "      请输入你想要的操作：" << endl
			<< "       1.创建一个链表" << endl
			<< "       2.销毁链表" << endl
			<< "       3.向后插入一个结点" << endl
			<< "       4.向前插入一个结点" << endl
			<< "       5.删掉一个结点" << endl
			<< "       6.遍历一次链表" << endl
			<< "       7.搜素一个结点" << endl;
		//<< "       8.反转一个链表" << endl
		//<< "       9.查看链表是否成环" << endl
		//<< "       10.奇偶调换" << endl
		//<< "       11.找中间数" << endl;
		cin >> choice;

		if (choice == 1)
		{
			InitList_DuL(&L);
			cout << "      创立成功" << endl << endl;
		}

		if (choice == 2)
		{
			DestroyList_DuL(&L);
			cout << "      销毁成功" << endl << endl;
		}

		if (choice == 3)
		{
			cout << endl << endl << "      请输入你想向后插入的数据，以及插入的位置：" << endl;
			cin >> i >> p;
			Node = new DuLNode;
			Node->data = i;
			InsertAfterList_DuL(InsertList_position(p, L), Node);
			cout << "      插入成功" << endl << endl;
		}

		if (choice == 4)
		{
			cout << endl << endl << "      请输入你想向前插入的数据，以及插入的位置：" << endl;
			cin >> i >> p;
			Node = new DuLNode;
			Node->data = i;
			InsertAfterList_DuL(InsertList_position(p, L), Node);
			cout << "      插入成功" << endl << endl;
		}

		if (choice == 5)
		{
			cout << endl << endl << "      请输入你想删除的结点：" << endl << endl;
			cin >> i;
			DeleteList(Deletelist_position(L, i), &j);
			if (j == i) cout << "删除成功" << endl << endl;
			else cout << "删除失败" << endl << endl;
		}

		if (choice == 6)
		{
			cout << endl << "你可以选择遍历一次链表" << endl;
			TraverseList(L, COUTLIST);
		}

		if (choice == 7)
		{
			cout << endl << endl << "      请输入你想搜素的数据：" << endl;
			cin >> i;
			if (SearchList(L, i))cout << "      存在该数据" << endl << endl;
			else cout << "      该数据不存在" << endl << endl;
		}
	}
}