#include<iostream>
using namespace std;
#include"AQueue.h"

char datatype[MAXQUEUE];
void* e = NULL;
int main()
{
	AQueue Q;
	char type;
	void* e = NULL, * d, *h;
	int count = NULL, choice, judge;
	void judge_type(AQueue* Q, char type, void* data , char *d);
	int* data_int ;
	unsigned* data_unsigned ;
	char* data_char ;
	string* data_string ;
	float* data_float ;
	double* data_double ;
	while (1)
	{
		cout << endl << "         *循环队列*" << endl << endl
			<< "      你可进行以下操作：" << endl
			<< "       1.创建一个循环队列" << endl
			<< "       2.销毁队列" << endl
			<< "       3.检查队列是否已满" << endl
			<< "       4.检查队列是否为空" << endl
			<< "       5.查看队头元素" << endl
			<< "       6.确定队列长度" << endl
			<< "       7.入队操作" << endl
			<< "       8.出队操作" << endl 
			<< "       9.清空队列" << endl
			<< "       10.遍历函数操作" << endl
			<< "      请输入你想要的操作：" << endl
			<< "       ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case(1):
			InitAQueue(&Q);
			cout << "      创建成功";
			break;

		case(2):
			DestoryAQueue(&Q);
			cout << "      销毁失败";
			break;

		case(3):
			judge = IsFullAQueue(&Q);
			if (judge)
			{
				cout << "      判断为满队列";
			}
			else
			{
				cout << "      判断不为满队列";
			}
			break;

		case(4):
			judge = IsEmptyAQueue(&Q);
			if (judge)
			{
				cout << "      判断为空队列";
			}
			else
			{
				cout << "      判断不为空队列";
			}
			break;

		case(5):
			judge = GetHeadAQueue(&Q, &e);
			if (judge)
			{
				switch (datatype[Q.front])
				{
				case('1'):
					cout << "      队头元素为：" << *(int*)e;//(*((int*)e));
					break;
				case('2'):
					cout << "      队头元素为：" << *((unsigned*)e);
					break;
				case('3'):
					cout << "      队头元素为：" << *((char*)e);
					break;
				case('4'):
					cout << "      队头元素为：" << *((string*)e);
					break;
				case('5'):
					cout << "      队头元素为：" << *((float*)e);
					break;
				case('6'):
					cout << "      队头元素为：" << *((double*)e);
					break;
				}
			}
			else
			{
				cout << "      查看队头元素失败";
			}
			break;

		case(6):
			count = LengthAQueue(&Q);
			if (count)
			{
				cout << "      队列的长度为：" << count;
			}
			else
			{
				cout << "      获取队列长度失败";
			}
			count = NULL;
			break;

		case(7):
			cout << "      数据类型" << endl
				<< "       1.整型" << endl
				<< "       2.无符号整型" << endl
				<< "       3.字符型" << endl
				<< "       4.字符串" << endl
				<< "       5.单精度型" << endl
				<< "       6.双精度型" << endl
				<< "      请输入数据类型：" << endl << "       ";
			cin >> type;
			cout << endl << "      请输入数据：" << endl << "       ";
//			judge_type(&Q, type, &d, &datatype[Q.front]);
			datatype[Q.front] = type;
			switch (type)
			{
			case('1'):
				data_int = new int;
				cin >> *data_int;
				judge = EnAQueue(&Q, &data_int);
				break;
			case('2'):
				data_unsigned = new unsigned;
				cin >> *data_unsigned;
				judge = EnAQueue(&Q, &data_unsigned);
				break;
			case('3'):
				data_char = new char;
				cin >> *data_char;
				judge = EnAQueue(&Q, &data_char);
				break;
			case('4'):
				data_string = new string;
				cin >> *data_string;
				judge = EnAQueue(&Q, &data_string);
				break;
			case('5'):
				data_float = new float;
				cin >> *data_float;
				judge = EnAQueue(&Q, &data_float);
				break;
			case('6'):
				data_double = new double;
				cin >> *data_double;
				judge = EnAQueue(&Q, &data_double);
				break;
			}
//			judge = EnAQueue(&Q, &d);
			if (judge)
			{
				cout << "      入队成功";
			}
			else
			{
				cout << "      入队失败";
			}
			break;

		case(8):
			judge = DeAQueue(&Q);
			if (judge)
			{
				cout << "      出队成功";
			}
			else
			{
				cout << "      出队失败";
			}
			break;

		case(9):
			ClearAQueue(&Q);
			cout << "      清空成功";
			break;

		case(10):
			judge = TraverseAQueue(&Q, APrint);
			if (judge)
			{
				cout << "      遍历成功";
			}
			else
			{
				cout << "      遍历失败";
			}
			break;
		}

		cout << endl << "      ";
		system("pause");
		system("cls");
	}
	return 0;
}
		
		


//void* my_memcpy(void* dst, const void* src, int size)
//{
//	if (dst == NULL || src == NULL)
//		return;
//	void* ret = dst;
//	char* d = (char*)dst;
//	const char* s = (const char*)src;
//	for (int i = 0;i < size;i++)
//	{
//		d[i] = s[i];
//	}
//	return ret;
//}
//void main()
//{
//	char ca = 'a', cb = 'x';
//	int ia = 12, ib = 23;
//	double da = 12.23, db = 34.34;
//	Student sa = { 2017,"yhping",18 };
//	Student sb = { 2018,"xcving",15 };
//	Swap(&ca, &cb, sizeof(ca));
//	Swap(&da, &db, sizeof(da));
//	Swap(&sa, &sb, sizeof(sa));
//}
//
//
//void Swap(void* a, void* b, int const n)
//{
//	if (a == NULL || b == NULL)
//	{
//		return;
//	}
//	char temp;
//	for (int i = 0;i < n;++i)
//	{
//		temp = ((char*)a)[i];
//		((char*)a)[i] = ((char*)b)[i];
//		((char*)b)[i] = temp;
//	}
//}
