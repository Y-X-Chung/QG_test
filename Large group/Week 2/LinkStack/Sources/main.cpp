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
		cout<<endl<<"           *链栈*" << endl << endl
			<< "      你可进行以下操作：" << endl
			<< "       1.创建一个链栈" << endl
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
			judge = initLStack(&s);
			if (judge)
			{
				cout << "      创建成功" << endl;
			}
			else
			{
				cout << "      创建失败" << endl;
			}
			break;
		case(2):
			judge = isEmptyLStack(&s);
			if (judge)
			{
				cout << "      判断不为空栈" << endl;
			}
			else
			{
				cout << "      判断为空栈" << endl;
			}
			break;
		case(3):
			judge = getTopLStack(&s, &e);
			if (judge)
			{
				cout << "      栈顶元素为：" << e << endl;
			}
			else
			{
				cout << "      获取失败" << endl;
			}
			break;
		case(4):
			judge = clearLStack(&s);
			if (judge)
			{
				cout << "      清空成功" << endl;
			}
			else
			{
				cout << "      清空失败" << endl;
			}
			break;
		case(5):
			judge = destroyLStack(&s);
			if (judge)
			{
				cout << "      销毁成功" << endl;
			}
			else
			{
				cout << "      销毁失败" << endl;
			}
			break;
		case(6):
			judge = LStackLength(&s, &l);
			if (judge)
			{
				cout << "      栈的长度为：" << l << endl;
			}
			else
			{
				cout << "      获取失败" << endl;
			}
			break;
		case(7):
			cout << "      请输入需入栈的数据："<<endl<< "       ";
			cin >> d;
			cout << endl;
			judge = pushLStack(&s, d);
			if (judge)
			{
				cout << "      入栈成功" << endl;
			}
			else
			{
				cout << "      入栈失败" << endl;
			}
			break;
		case(8):
			judge = popLStack(&s, &dt);
			if (judge)
			{
				cout << "      数据"<<dt<<"出栈成功" << endl;
			}
			else
			{
				cout << "      出栈失败" << endl;
			}
			break;
		}
		cout << "      ";
		system("pause");
		system("cls");
	}
	return 0;
}