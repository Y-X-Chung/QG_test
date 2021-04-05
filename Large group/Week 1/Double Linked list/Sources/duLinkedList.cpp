#include"duLinkedList.h"
#include<iostream>
using namespace std;

Status InitList_DuL(DuLinkedList* L)                       //��������
{
	(*L) = new DuLNode;
	(*L)->next = NULL;
	return SUCCESS;
}

void DestroyList_DuL(DuLinkedList* L)                         //��������
{
	DuLNode* p;
	while (*L)
	{
		p = (*L)->next;
		delete(*L);
		L = &p;
	}
}

DuLNode* InsertList_position(int n, DuLinkedList L)          //��������
{
	DuLinkedList p = L;
	for (int i = 2;i <= n;i++)
	{
		p = p->next;
	}
	return p;
}
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)             //����
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

DuLNode* Deletelist_position(DuLinkedList L, ElemType e)          //�ҵ�ɾ����p��λ��
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

Status DeleteList(DuLNode* p, ElemType* e) 						//ɾ��p����һ���ڵ㣬������ڵ��ֵ��e
{
	*e = p->next->data;
	DuLinkedList q;
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

void TraverseList(DuLinkedList L, void (*visit)(ElemType e))			//��������
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

Status SearchList(DuLinkedList L, ElemType e)					         //�������в�������e
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
		cout << "      ����������Ҫ�Ĳ�����" << endl
			<< "       1.����һ������" << endl
			<< "       2.��������" << endl
			<< "       3.������һ�����" << endl
			<< "       4.��ǰ����һ�����" << endl
			<< "       5.ɾ��һ�����" << endl
			<< "       6.����һ������" << endl
			<< "       7.����һ�����" << endl;
		//<< "       8.��תһ������" << endl
		//<< "       9.�鿴�����Ƿ�ɻ�" << endl
		//<< "       10.��ż����" << endl
		//<< "       11.���м���" << endl;
		cin >> choice;

		if (choice == 1)
		{
			InitList_DuL(&L);
			cout << "      �����ɹ�" << endl << endl;
		}

		if (choice == 2)
		{
			DestroyList_DuL(&L);
			cout << "      ���ٳɹ�" << endl << endl;
		}

		if (choice == 3)
		{
			cout << endl << endl << "      ��������������������ݣ��Լ������λ�ã�" << endl;
			cin >> i >> p;
			Node = new DuLNode;
			Node->data = i;
			InsertAfterList_DuL(InsertList_position(p, L), Node);
			cout << "      ����ɹ�" << endl << endl;
		}

		if (choice == 4)
		{
			cout << endl << endl << "      ������������ǰ��������ݣ��Լ������λ�ã�" << endl;
			cin >> i >> p;
			Node = new DuLNode;
			Node->data = i;
			InsertAfterList_DuL(InsertList_position(p, L), Node);
			cout << "      ����ɹ�" << endl << endl;
		}

		if (choice == 5)
		{
			cout << endl << endl << "      ����������ɾ���Ľ�㣺" << endl << endl;
			cin >> i;
			DeleteList(Deletelist_position(L, i), &j);
			if (j == i) cout << "ɾ���ɹ�" << endl << endl;
			else cout << "ɾ��ʧ��" << endl << endl;
		}

		if (choice == 6)
		{
			cout << endl << "�����ѡ�����һ������" << endl;
			TraverseList(L, COUTLIST);
		}

		if (choice == 7)
		{
			cout << endl << endl << "      �������������ص����ݣ�" << endl;
			cin >> i;
			if (SearchList(L, i))cout << "      ���ڸ�����" << endl << endl;
			else cout << "      �����ݲ�����" << endl << endl;
		}
	}
}