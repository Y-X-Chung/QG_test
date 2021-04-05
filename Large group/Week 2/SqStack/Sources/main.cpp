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
		cout << endl << "         *顺序栈*" << endl << endl
			<< "      你可进行以下操作：" << endl
			<< "       1.创建一个基于数组的顺序栈" << endl
			<< "       2.判断栈是否为空" << endl
			<< "       3.得到栈顶元素" << endl
			<< "       4.清空栈" << endl
			<< "       5.销毁栈" << endl
			<< "       6.检测栈长度" << endl
			<< "       7.入栈" << endl
			<< "       8.出栈" << endl << endl
			<< "      请输入你想要的操作：" << endl
			<< "       ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case(1):
			cout << "      请输入你想创建的栈的长度：" << endl;
			cout << "       ";
			cin >> si;
			cout << endl;
			judge = initStack(&s, si);
			if (judge)
			{
				cout << "      创建成功";
			}
			else
			{
				cout << "      创建失败";
			}
			break;
		case(2):
			judge = isEmptyStack(&s);
			if (judge)
			{
				cout << "      判断不为空栈";
			}
			else
			{
				cout << "      判断为空栈";
			}
			break;
		case(3):
			judge = getTopStack(&s, &e);
			if (judge)
			{
				cout << "      栈顶元素为：" << e;
			}
			else
			{
				cout << "      获取失败";
			}
			break;
		case(4):
			judge = clearStack(&s);
			if (judge)
			{
				cout << "      清空成功";
			}
			else
			{
				cout << "      清空失败";
			}
			break;
		case(5):
			judge = destroyStack(&s);
			if (judge)
			{
				cout << "      销毁成功";
			}
			else
			{
				cout << "      销毁失败";
			}
			break;
		case(6):
			judge = stackLength(&s, &l);
			if (judge)
			{
				cout << "      栈的长度为：" << l;
			}
			else
			{
				cout << "      获取失败";
			}
			break;
		case(7):
			cout << "      请输入需入栈的数据：" << endl<< "       ";
			cin >> d;
			cout << endl;
			judge = pushStack(&s, d);
			if (judge)
			{
				cout << "      入栈成功";
			}
			else
			{
				cout << "      入栈失败";
			}
			break;
		case(8):
			judge = popStack(&s, &dt);
			if (judge)
			{
				cout <<"      数据"<<dt<< "出栈成功";
			}
			else
			{
				cout << "      出栈失败";
			}
			break;
		}
	cout << endl << "      ";
	system("pause");
	system("cls");
	}
	return 0;
}