#include"linkedList.h"
#include<iostream>
using namespace std;
Status InitList(LinkedList* L)                               //创建链表
{
	*L = new LNode;
	(*L)->next = NULL;
	return SUCCESS;
}

void DestroyList(LinkedList* L)                               //销毁链表
{
	LNode* p;
	while (*L)
	{
		p = (*L)->next;
		delete(*L);
		L = &p;
	}
}

LNode* InsertList_position(int n, LinkedList L)               //找到插入点p的位置
{
	LinkedList p = L;
	for (int i = 2;i <= n;i++)
	{
		p = p->next;
	}
	return p;
}

Status InsertList(LNode* p, LNode* q)						   //将结点q插入到结点p之后
{
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}

LNode* Deletelist_position(LinkedList L, ElemType e)          //找到删除点p的位置
{
	LinkedList p = L;
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

Status DeleteList(LNode* p, ElemType* e) 						//删掉p的下一个节点，把这个节点的值给e
{
	*e = p->next->data;
	LinkedList q;
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

void TraverseList(LinkedList L, void (*visit)(ElemType e))			//遍历链表
{
	LinkedList p;
	p = L->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	return;
}

Status SearchList(LinkedList L, ElemType e)					         //在链表中查找数据e
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

Status ReverseList(LinkedList* L)
{
	return SUCCESS;
}

Status IsLoopList(LinkedList L)
{
	return SUCCESS;
}

LNode* ReverseEvenList(LinkedList* L)
{
	return NULL;
}

LNode* FindMidNode(LinkedList* L)
{
	return NULL;
}

int main()
{
	LinkedList L = NULL;
	LNode* Node;
	ElemType i, j;
	int n, p, choice;
	while (1) {
		//for (int i = 1; i <= 10; ++i) cout << endl;
		cout << "      请输入你想要的操作：" << endl
			<< "       1.创建一个链表" << endl
			<< "       2.销毁链表" << endl
			<< "       3.插入一个结点" << endl
			<< "       4.删掉一个结点" << endl
			<< "       5.遍历一次链表" << endl
			<< "       6.搜素一个结点" << endl;
		//<< "       7.反转一个链表" << endl
		//<< "       8.查看链表是否成环" << endl
		//<< "       9.奇偶调换" << endl
		//<< "       10.找中间数" << endl;
		cin >> choice;

		if (choice == 1)
		{
			InitList(&L);
			cout << "      创立成功" << endl << endl;
		}

		if (choice == 2)
		{
			DestroyList(&L);
			cout << "      销毁成功" << endl << endl;
		}

		if (choice == 3)
		{
			cout << endl << endl << "      请输入你想插入的数据，以及插入的位置：" << endl;
			cin >> i >> p;
			Node = new LNode;
			Node->data = i;
			InsertList(InsertList_position(p, L), Node);
			cout << "      插入成功" << endl << endl;
		}

		if (choice == 4)
		{
			cout << endl << endl << "      请输入你想删除的结点：" << endl << endl;
			cin >> i;
			DeleteList(Deletelist_position(L, i), &j);
			if (j == i) cout << "删除成功" << endl << endl;
			else cout << "删除失败" << endl << endl;
		}

		if (choice == 5)
		{
			cout << endl << "你可以选择遍历一次链表" << endl;
			TraverseList(L, COUTLIST);
		}

		if (choice == 6)
		{
			cout << endl << endl << "      请输入你想搜素的数据：" << endl;
			cin >> i;
			if (SearchList(L, i))cout << "      存在该数据" << endl << endl;
			else cout << "      该数据不存在" << endl << endl;
		}
	}
}