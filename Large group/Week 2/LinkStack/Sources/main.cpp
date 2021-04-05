#include<iostream>
using namespace std;
#include"LinkStack.h"

int main()
{
	LinkStack s;
	ElemType e, d,  dt;
	int  l , choice, judge;
	while (1)
	{
		cout<<endl<<"           *��ջ*" << endl << endl
			<< "      ��ɽ������²�����" << endl
			<< "       1.����һ����ջ" << endl
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
			judge = initLStack(&s);
			if (judge)
			{
				cout << "      �����ɹ�" << endl;
			}
			else
			{
				cout << "      ����ʧ��" << endl;
			}
			break;
		case(2):
			judge = isEmptyLStack(&s);
			if (judge)
			{
				cout << "      �жϲ�Ϊ��ջ" << endl;
			}
			else
			{
				cout << "      �ж�Ϊ��ջ" << endl;
			}
			break;
		case(3):
			judge = getTopLStack(&s, &e);
			if (judge)
			{
				cout << "      ջ��Ԫ��Ϊ��" << e << endl;
			}
			else
			{
				cout << "      ��ȡʧ��" << endl;
			}
			break;
		case(4):
			judge = clearLStack(&s);
			if (judge)
			{
				cout << "      ��ճɹ�" << endl;
			}
			else
			{
				cout << "      ���ʧ��" << endl;
			}
			break;
		case(5):
			judge = destroyLStack(&s);
			if (judge)
			{
				cout << "      ���ٳɹ�" << endl;
			}
			else
			{
				cout << "      ����ʧ��" << endl;
			}
			break;
		case(6):
			judge = LStackLength(&s, &l);
			if (judge)
			{
				cout << "      ջ�ĳ���Ϊ��" << l << endl;
			}
			else
			{
				cout << "      ��ȡʧ��" << endl;
			}
			break;
		case(7):
			cout << "      ����������ջ�����ݣ�"<<endl<< "       ";
			cin >> d;
			cout << endl;
			judge = pushLStack(&s, d);
			if (judge)
			{
				cout << "      ��ջ�ɹ�" << endl;
			}
			else
			{
				cout << "      ��ջʧ��" << endl;
			}
			break;
		case(8):
			judge = popLStack(&s, &dt);
			if (judge)
			{
				cout << "      ����"<<dt<<"��ջ�ɹ�" << endl;
			}
			else
			{
				cout << "      ��ջʧ��" << endl;
			}
			break;
		}
		cout << "      ";
		system("pause");
		system("cls");
	}
	return 0;
}