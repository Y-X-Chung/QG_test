#include<iostream>
using namespace std;
#include"SqStack.h"

int main()
{
	SqStack s;
	ElemType e, d, dt;
	int si, l,choice, judge;
	while (1) 
	{
		cout << endl << "         *˳��ջ*" << endl << endl
			<< "      ��ɽ������²�����" << endl
			<< "       1.����һ�����������˳��ջ" << endl
			<< "       2.�ж�ջ�Ƿ�Ϊ��" << endl
			<< "       3.�õ�ջ��Ԫ��" << endl
			<< "       4.���ջ" << endl
			<< "       5.����ջ" << endl
			<< "       6.���ջ����" << endl
			<< "       7.��ջ" << endl
			<< "       8.��ջ" << endl << endl
			<< "      ����������Ҫ�Ĳ�����" << endl
			<< "       ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case(1):
			cout << "      ���������봴����ջ�ĳ��ȣ�" << endl;
			cout << "       ";
			cin >> si;
			cout << endl;
			judge = initStack(&s, si);
			if (judge)
			{
				cout << "      �����ɹ�";
			}
			else
			{
				cout << "      ����ʧ��";
			}
			break;
		case(2):
			judge = isEmptyStack(&s);
			if (judge)
			{
				cout << "      �жϲ�Ϊ��ջ";
			}
			else
			{
				cout << "      �ж�Ϊ��ջ";
			}
			break;
		case(3):
			judge = getTopStack(&s, &e);
			if (judge)
			{
				cout << "      ջ��Ԫ��Ϊ��" << e;
			}
			else
			{
				cout << "      ��ȡʧ��";
			}
			break;
		case(4):
			judge = clearStack(&s);
			if (judge)
			{
				cout << "      ��ճɹ�";
			}
			else
			{
				cout << "      ���ʧ��";
			}
			break;
		case(5):
			judge = destroyStack(&s);
			if (judge)
			{
				cout << "      ���ٳɹ�";
			}
			else
			{
				cout << "      ����ʧ��";
			}
			break;
		case(6):
			judge = stackLength(&s, &l);
			if (judge)
			{
				cout << "      ջ�ĳ���Ϊ��" << l;
			}
			else
			{
				cout << "      ��ȡʧ��";
			}
			break;
		case(7):
			cout << "      ����������ջ�����ݣ�" << endl<< "       ";
			cin >> d;
			cout << endl;
			judge = pushStack(&s, d);
			if (judge)
			{
				cout << "      ��ջ�ɹ�";
			}
			else
			{
				cout << "      ��ջʧ��";
			}
			break;
		case(8):
			judge = popStack(&s, &dt);
			if (judge)
			{
				cout <<"      ����"<<dt<< "��ջ�ɹ�";
			}
			else
			{
				cout << "      ��ջʧ��";
			}
			break;
		}
	cout << endl << "      ";
	system("pause");
	system("cls");
	}
	return 0;
}