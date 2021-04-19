#include<iostream>
#include<math.h>
#include<ctime>
#include"qgsort.h"
using namespace std;

int main()
{
	int si, m = 0, choice, c, * t = new int[200000], * a = new int;
	int b = 1, d = 1000;// 生成100-300之间的随机数
	while (1)
	{
		cout << endl << "         *排序算法*" << endl << endl
			<< "      你可以选择以下操作：" << endl
			<< "       1.创建一个数组" << endl
			<< "       2.排序" << endl
			<< "       3.计算大数据量(10000,50000,200000)下排序用时" << endl
			<< "       4.计算大量小数组(100数据*100k次)下排序用时" << endl<<endl
			<< "      请输入你想要的操作：" << endl
			<< "       ";
		cin >> c;
		cout << endl;

		switch (c)
		{
		case(1):
			cout << "      请输入你想创建的数组的长度：" << endl;
			cout << "       ";
			cin >> si;
			cout << endl;
//			int* a = (int*)malloc(si - 1);
			for (int i = 0; i <= si - 1;i++)
			{
				cout << "      请输入第" << i + 1 << "个数" << endl << "      ";
				cin >> a[i];
			}
			cout << "      创建成功";
			break;

		case(2):
			cout << endl << "         *排序*" << endl << endl
				<< "      你可以选择以下排序方法：" << endl
				<< "       1.插入排序算法" << endl
				<< "       2.归并排序算法" << endl
				<< "       3.快速排序算法（递归版）" << endl
//				<< "       4.快速排序算法（非递归版）" << endl
				<< "       5.计数排序算法" << endl
				<< "       6.基数计数排序算法" << endl
//				<< "       7.颜色排序算法" << endl
				<< "       8.退出" << endl << endl
				<< "      请输入你想要的操作：" << endl
				<< "       ";
			cin >> choice;
			cout << endl;

			switch (choice)
			{
			case(1):
				insertSort(a, si);
				cout << "      插入排序输出结果为：";
				for (int i = 0; i <= si - 1;i++)
				{
					cout << " " << a[i];
				}
				break;

			case(2):
				MergeSort(a, 0, si - 1, t);
				cout << "      归并排序输出结果为：";
				for (int i = 0; i <= si - 1;i++)
				{
					cout << " " << a[i];
				}
				break;

			case(3):
				QuickSort_Recursion(a, 0, si - 1);
				cout << "      输出结果为：";
				for (int i = 0; i <= si - 1;i++)
				{
					cout << " " << a[i];
				}
				break;

				/*case(4):
					cout << "      请输入你想创建的数组的长度：" << endl;
					cout << "       ";
					cin >> si;
					cout << endl;
					int* a = (int*)malloc(si - 1), * t;
					for (int i = 0; i <= si - 1;i++)
					{
						cout << "      请输入第" << i + 1 << "个数" << endl << "      ";
						cin >> a[i];
					}
					CountSort(a, si - 1, m);
					cout << "      输出结果为：";
					for (int i = 0; i <= si - 1;i++)
					{
						cout << " " << a[i];
					}
					break;*/

			case(5):
				CountSort(a, si - 1, m);
				cout << "      输出结果为：";
				for (int i = 0; i <= si - 1;i++)
				{
					cout << " " << a[i];
				}
				break;

			case(6):
				RadixCountSort(a, si - 1);
				cout << "      输出结果为：";
				for (int i = 0; i <= si - 1;i++)
				{
					cout << " " << a[i];
				}
				break;

			case(8):
				break;

				/*	case(7):
						cout << "      请输入你想创建的数组的长度：" << endl;
						cout << "       ";
						cin >> si;
						cout << endl;
						int* a = (int*)malloc(si - 1), * t;
						for (int i = 0; i <= si - 1;i++)
						{
							cout << "      请输入第" << i + 1 << "个数" << endl << "      ";
							cin >> a[i];
						}
						RadixCountSort(a, si - 1);
						cout << "      输出结果为：";
						for (int i = 0; i <= si - 1;i++)
						{
							cout << " " << a[i];
						}
						break;


					case(8):
				RadixCountSort(a, si - 1);
				cout << "      输出结果为：";
				for (int i = 0; i <= si - 1;i++)
				{
					cout << " " << a[i];
				}
				break;*/
			}

		case(3):
			clock_t start1, finish1, start2, finish2, start3, finish3;
			int* num1, *num2, *num3;
			num1 = new int[10000];
			num2 = new int[50000];
			num3 = new int[200000];
			for (int i = 0;i < 10000;i++)
				num1[i] = rand() % (int)(d - b + 1) + b;
			for (int i = 0;i < 50000;i++)
				num2[i] = rand() % (int)(d - b + 1) + b;
			for (int i = 0;i < 200000;i++)
				num3[i] = rand() % (int)(d - b + 1) + b;

			start1 = clock();
			insertSort(num1, 9999);
			finish1 = clock();
			start2 = clock();
			insertSort(num2, 49999);
			finish2 = clock();
			start3 = clock();
			insertSort(num3, 199999);
			finish3 = clock();
			cout << "      插入排序为：" << double(finish1 - start1) << "ms  "<< double(finish2 - start2) << "ms  "<< double(finish3 - start3) << "ms"<<endl;
			
			start1 = clock();
			MergeSort(num1, 0, 9999, t);
			finish1 = clock();
			start2 = clock();
			MergeSort(num2, 0, 49999, t);
			finish2 = clock();
			start3 = clock();
			MergeSort(num3, 0, 199999, t);
			finish3 = clock();
			cout << "      归并排序为：" << double(finish1 - start1) << "ms  " << double(finish2 - start2) << "ms  " << double(finish3 - start3) << "ms" << endl;

			start1 = clock();
			QuickSort_Recursion(num1, 0, 9999);
			finish1 = clock();
			start2 = clock();
			QuickSort_Recursion(num2, 0, 49999);
			finish2 = clock();
			start3 = clock();
			QuickSort_Recursion(num3, 0, 199999);
			finish3 = clock();
			cout << "      快速排序为：" << double(finish1 - start1) << "ms  " << double(finish2 - start2) << "ms  " << double(finish3 - start3) << "ms" << endl;

			/*start1 = clock();
			insertSort(num1, 9999);
			finish1 = clock();
			start2 = clock();
			insertSort(num2, 49999);
			finish2 = clock();
			start3 = clock();
			insertSort(num3, 199999);
			finish3 = clock();
			cout << "      插入排序为：" << double(finish1 - start1) << "ms  " << double(finish2 - start2) << "ms  " << double(finish3 - start3) << "ms" << endl;*/

			start1 = clock();
			CountSort(num1, 9999, m);
			finish1 = clock();
			start2 = clock();
			CountSort(num2, 49999, m);
			finish2 = clock();
			start3 = clock();
			CountSort(num3, 199999, m);
			finish3 = clock();
			cout << "      计数排序为：" << double(finish1 - start1) << "ms  " << double(finish2 - start2) << "ms  " << double(finish3 - start3) << "ms" << endl;

			start1 = clock();
			RadixCountSort(num1, 9999);
			finish1 = clock();
			start2 = clock();
			RadixCountSort(num2, 49999);
			finish2 = clock();
			start3 = clock();
			RadixCountSort(num3, 199999);
			finish3 = clock();
			cout << "      基数计数排序为：" << double(finish1 - start1) << "ms  " << double(finish2 - start2) << "ms  " << double(finish3 - start3) << "ms" << endl;

			break;

			/*start1 = clock();
			insertSort(num1, 9999);
			finish1 = clock();
			start2 = clock();
			insertSort(num2, 49999);
			finish2 = clock();
			start3 = clock();
			insertSort(num3, 199999);
			finish3 = clock();
			cout << "      插入排序为：" << double(finish1 - start1) << "ms  " << double(finish2 - start2) << "ms  " << double(finish3 - start3) << "ms" << endl;*/


		case(4):
			clock_t start, finish;
			int* num;
			num = new int[100];
			for (int j = 0;j < 100;j++)
				num[j] = rand() % (int)(d - b + 1) + b;

			start = clock();
			for (double i = 0; i < 100000;i++)
			{
				insertSort(num, 99);
			}
			finish = clock();
			cout << "      插入排序为：" << double(finish - start) << "ms";

			start = clock();
			for (double i = 0; i < 100000;i++)
			{
				MergeSort(num, 0, 99, t);
			}
			finish = clock();
			cout << "      归并排序为：" << double(finish - start) << "ms";

			start = clock();
			for (double i = 0; i < 100000;i++)
			{
				QuickSort_Recursion(num, 0, 99);
			}
			finish = clock();
			cout << "      快速排序为：" << double(finish - start) << "ms";

			start = clock();
			for (double i = 0; i < 100000;i++)
			{
				CountSort(num, 99, m);
			}
			finish = clock();
			cout << "      计数排序为：" << double(finish - start) << "ms";

			start = clock();
			for (double i = 0; i < 100000;i++)
			{
				RadixCountSort(num, 99);
			}
			finish = clock();
			cout << "      基数计数排序为：" << double(finish - start) << "ms";

			/*start = clock();
			for (double i = 0; i < 100000;i++)
			{
				insertSort(num, 9999);
			}
			finish = clock();
			cout << "      插入排序为：" << double(finish - start) << "ms";

			start = clock();
			for (double i = 0; i < 100000;i++)
			{
				insertSort(num, 9999);
			}
			finish = clock();
			cout << "      插入排序为：" << double(finish - start) << "ms";*/
		}
		cout << endl << "      ";
		//system("pause");
		//system("cls");
	}
	return 0;
}