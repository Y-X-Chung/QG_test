#include<iostream>
#include<math.h>
#include<ctime>
#include"qgsort.h"
using namespace std;

int main()
{
	int si, m = 0, choice, c, * t = new int[200000], * a = new int;
	int b = 1, d = 1000;// ����100-300֮��������
	while (1)
	{
		cout << endl << "         *�����㷨*" << endl << endl
			<< "      �����ѡ�����²�����" << endl
			<< "       1.����һ������" << endl
			<< "       2.����" << endl
			<< "       3.�����������(10000,50000,200000)��������ʱ" << endl
			<< "       4.�������С����(100����*100k��)��������ʱ" << endl<<endl
			<< "      ����������Ҫ�Ĳ�����" << endl
			<< "       ";
		cin >> c;
		cout << endl;

		switch (c)
		{
		case(1):
			cout << "      ���������봴��������ĳ��ȣ�" << endl;
			cout << "       ";
			cin >> si;
			cout << endl;
//			int* a = (int*)malloc(si - 1);
			for (int i = 0; i <= si - 1;i++)
			{
				cout << "      �������" << i + 1 << "����" << endl << "      ";
				cin >> a[i];
			}
			cout << "      �����ɹ�";
			break;

		case(2):
			cout << endl << "         *����*" << endl << endl
				<< "      �����ѡ���������򷽷���" << endl
				<< "       1.���������㷨" << endl
				<< "       2.�鲢�����㷨" << endl
				<< "       3.���������㷨���ݹ�棩" << endl
//				<< "       4.���������㷨���ǵݹ�棩" << endl
				<< "       5.���������㷨" << endl
				<< "       6.�������������㷨" << endl
//				<< "       7.��ɫ�����㷨" << endl
				<< "       8.�˳�" << endl << endl
				<< "      ����������Ҫ�Ĳ�����" << endl
				<< "       ";
			cin >> choice;
			cout << endl;

			switch (choice)
			{
			case(1):
				insertSort(a, si);
				cout << "      ��������������Ϊ��";
				for (int i = 0; i <= si - 1;i++)
				{
					cout << " " << a[i];
				}
				break;

			case(2):
				MergeSort(a, 0, si - 1, t);
				cout << "      �鲢����������Ϊ��";
				for (int i = 0; i <= si - 1;i++)
				{
					cout << " " << a[i];
				}
				break;

			case(3):
				QuickSort_Recursion(a, 0, si - 1);
				cout << "      ������Ϊ��";
				for (int i = 0; i <= si - 1;i++)
				{
					cout << " " << a[i];
				}
				break;

				/*case(4):
					cout << "      ���������봴��������ĳ��ȣ�" << endl;
					cout << "       ";
					cin >> si;
					cout << endl;
					int* a = (int*)malloc(si - 1), * t;
					for (int i = 0; i <= si - 1;i++)
					{
						cout << "      �������" << i + 1 << "����" << endl << "      ";
						cin >> a[i];
					}
					CountSort(a, si - 1, m);
					cout << "      ������Ϊ��";
					for (int i = 0; i <= si - 1;i++)
					{
						cout << " " << a[i];
					}
					break;*/

			case(5):
				CountSort(a, si - 1, m);
				cout << "      ������Ϊ��";
				for (int i = 0; i <= si - 1;i++)
				{
					cout << " " << a[i];
				}
				break;

			case(6):
				RadixCountSort(a, si - 1);
				cout << "      ������Ϊ��";
				for (int i = 0; i <= si - 1;i++)
				{
					cout << " " << a[i];
				}
				break;

			case(8):
				break;

				/*	case(7):
						cout << "      ���������봴��������ĳ��ȣ�" << endl;
						cout << "       ";
						cin >> si;
						cout << endl;
						int* a = (int*)malloc(si - 1), * t;
						for (int i = 0; i <= si - 1;i++)
						{
							cout << "      �������" << i + 1 << "����" << endl << "      ";
							cin >> a[i];
						}
						RadixCountSort(a, si - 1);
						cout << "      ������Ϊ��";
						for (int i = 0; i <= si - 1;i++)
						{
							cout << " " << a[i];
						}
						break;


					case(8):
				RadixCountSort(a, si - 1);
				cout << "      ������Ϊ��";
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
			cout << "      ��������Ϊ��" << double(finish1 - start1) << "ms  "<< double(finish2 - start2) << "ms  "<< double(finish3 - start3) << "ms"<<endl;
			
			start1 = clock();
			MergeSort(num1, 0, 9999, t);
			finish1 = clock();
			start2 = clock();
			MergeSort(num2, 0, 49999, t);
			finish2 = clock();
			start3 = clock();
			MergeSort(num3, 0, 199999, t);
			finish3 = clock();
			cout << "      �鲢����Ϊ��" << double(finish1 - start1) << "ms  " << double(finish2 - start2) << "ms  " << double(finish3 - start3) << "ms" << endl;

			start1 = clock();
			QuickSort_Recursion(num1, 0, 9999);
			finish1 = clock();
			start2 = clock();
			QuickSort_Recursion(num2, 0, 49999);
			finish2 = clock();
			start3 = clock();
			QuickSort_Recursion(num3, 0, 199999);
			finish3 = clock();
			cout << "      ��������Ϊ��" << double(finish1 - start1) << "ms  " << double(finish2 - start2) << "ms  " << double(finish3 - start3) << "ms" << endl;

			/*start1 = clock();
			insertSort(num1, 9999);
			finish1 = clock();
			start2 = clock();
			insertSort(num2, 49999);
			finish2 = clock();
			start3 = clock();
			insertSort(num3, 199999);
			finish3 = clock();
			cout << "      ��������Ϊ��" << double(finish1 - start1) << "ms  " << double(finish2 - start2) << "ms  " << double(finish3 - start3) << "ms" << endl;*/

			start1 = clock();
			CountSort(num1, 9999, m);
			finish1 = clock();
			start2 = clock();
			CountSort(num2, 49999, m);
			finish2 = clock();
			start3 = clock();
			CountSort(num3, 199999, m);
			finish3 = clock();
			cout << "      ��������Ϊ��" << double(finish1 - start1) << "ms  " << double(finish2 - start2) << "ms  " << double(finish3 - start3) << "ms" << endl;

			start1 = clock();
			RadixCountSort(num1, 9999);
			finish1 = clock();
			start2 = clock();
			RadixCountSort(num2, 49999);
			finish2 = clock();
			start3 = clock();
			RadixCountSort(num3, 199999);
			finish3 = clock();
			cout << "      ������������Ϊ��" << double(finish1 - start1) << "ms  " << double(finish2 - start2) << "ms  " << double(finish3 - start3) << "ms" << endl;

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
			cout << "      ��������Ϊ��" << double(finish1 - start1) << "ms  " << double(finish2 - start2) << "ms  " << double(finish3 - start3) << "ms" << endl;*/


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
			cout << "      ��������Ϊ��" << double(finish - start) << "ms";

			start = clock();
			for (double i = 0; i < 100000;i++)
			{
				MergeSort(num, 0, 99, t);
			}
			finish = clock();
			cout << "      �鲢����Ϊ��" << double(finish - start) << "ms";

			start = clock();
			for (double i = 0; i < 100000;i++)
			{
				QuickSort_Recursion(num, 0, 99);
			}
			finish = clock();
			cout << "      ��������Ϊ��" << double(finish - start) << "ms";

			start = clock();
			for (double i = 0; i < 100000;i++)
			{
				CountSort(num, 99, m);
			}
			finish = clock();
			cout << "      ��������Ϊ��" << double(finish - start) << "ms";

			start = clock();
			for (double i = 0; i < 100000;i++)
			{
				RadixCountSort(num, 99);
			}
			finish = clock();
			cout << "      ������������Ϊ��" << double(finish - start) << "ms";

			/*start = clock();
			for (double i = 0; i < 100000;i++)
			{
				insertSort(num, 9999);
			}
			finish = clock();
			cout << "      ��������Ϊ��" << double(finish - start) << "ms";

			start = clock();
			for (double i = 0; i < 100000;i++)
			{
				insertSort(num, 9999);
			}
			finish = clock();
			cout << "      ��������Ϊ��" << double(finish - start) << "ms";*/
		}
		cout << endl << "      ";
		//system("pause");
		//system("cls");
	}
	return 0;
}