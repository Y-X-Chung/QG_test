#include"linkedList.h"
#include<iostream>
using namespace std;
Status InitList(LinkedList* L)                               //��������
{
	*L = new LNode;
	(*L)->next = NULL;
	return SUCCESS;
}

void DestroyList(LinkedList* L)                               //��������
{
	LNode* p;
	while (*L)
	{
		p = (*L)->next;
		delete(*L);
		L = &p;
	}
}

LNode* InsertList_position(int n, LinkedList L)               //�ҵ������p��λ��
{
	LinkedList p = L;
	for (int i = 2;i <= n;i++)
	{
		p = p->next;
	}
	return p;
}

Status InsertList(LNode* p, LNode* q)						   //�����q���뵽���p֮��
{
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}

LNode* Deletelist_position(LinkedList L, ElemType e)          //�ҵ�ɾ����p��λ��
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

Status DeleteList(LNode* p, ElemType* e) 						//ɾ��p����һ���ڵ㣬������ڵ��ֵ��e
{
	*e = p->next->data;
	LinkedList q;
	q = p->next;
	p->next = q->next;
	delete(q);
	return SUCCESS;
}

void COUTLIST(ElemType e)                                          //��ӡ����
{
	cout << e << " ";
	return;
}

void TraverseList(LinkedList L, void (*visit)(ElemType e))			//��������
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

Status SearchList(LinkedList L, ElemType e)					         //�������в�������e
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
		cout << "      ����������Ҫ�Ĳ�����" << endl
			<< "       1.����һ������" << endl
			<< "       2.��������" << endl
			<< "       3.����һ�����" << endl
			<< "       4.ɾ��һ�����" << endl
			<< "       5.����һ������" << endl
			<< "       6.����һ�����" << endl;
		//<< "       7.��תһ������" << endl
		//<< "       8.�鿴�����Ƿ�ɻ�" << endl
		//<< "       9.��ż����" << endl
		//<< "       10.���м���" << endl;
		cin >> choice;

		if (choice == 1)
		{
			InitList(&L);
			cout << "      �����ɹ�" << endl << endl;
		}

		if (choice == 2)
		{
			DestroyList(&L);
			cout << "      ���ٳɹ�" << endl << endl;
		}

		if (choice == 3)
		{
			cout << endl << endl << "      �����������������ݣ��Լ������λ�ã�" << endl;
			cin >> i >> p;
			Node = new LNode;
			Node->data = i;
			InsertList(InsertList_position(p, L), Node);
			cout << "      ����ɹ�" << endl << endl;
		}

		if (choice == 4)
		{
			cout << endl << endl << "      ����������ɾ���Ľ�㣺" << endl << endl;
			cin >> i;
			DeleteList(Deletelist_position(L, i), &j);
			if (j == i) cout << "ɾ���ɹ�" << endl << endl;
			else cout << "ɾ��ʧ��" << endl << endl;
		}

		if (choice == 5)
		{
			cout << endl << "�����ѡ�����һ������" << endl;
			TraverseList(L, COUTLIST);
		}

		if (choice == 6)
		{
			cout << endl << endl << "      �������������ص����ݣ�" << endl;
			cin >> i;
			if (SearchList(L, i))cout << "      ���ڸ�����" << endl << endl;
			else cout << "      �����ݲ�����" << endl << endl;
		}
	}
}