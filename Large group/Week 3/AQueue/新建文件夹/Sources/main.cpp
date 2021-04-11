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
		cout << endl << "         *ѭ������*" << endl << endl
			<< "      ��ɽ������²�����" << endl
			<< "       1.����һ��ѭ������" << endl
			<< "       2.���ٶ���" << endl
			<< "       3.�������Ƿ�����" << endl
			<< "       4.�������Ƿ�Ϊ��" << endl
			<< "       5.�鿴��ͷԪ��" << endl
			<< "       6.ȷ�����г���" << endl
			<< "       7.��Ӳ���" << endl
			<< "       8.���Ӳ���" << endl 
			<< "       9.��ն���" << endl
			<< "       10.������������" << endl
			<< "      ����������Ҫ�Ĳ�����" << endl
			<< "       ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case(1):
			InitAQueue(&Q);
			cout << "      �����ɹ�";
			break;

		case(2):
			DestoryAQueue(&Q);
			cout << "      ����ʧ��";
			break;

		case(3):
			judge = IsFullAQueue(&Q);
			if (judge)
			{
				cout << "      �ж�Ϊ������";
			}
			else
			{
				cout << "      �жϲ�Ϊ������";
			}
			break;

		case(4):
			judge = IsEmptyAQueue(&Q);
			if (judge)
			{
				cout << "      �ж�Ϊ�ն���";
			}
			else
			{
				cout << "      �жϲ�Ϊ�ն���";
			}
			break;

		case(5):
			judge = GetHeadAQueue(&Q, &e);
			if (judge)
			{
				switch (datatype[Q.front])
				{
				case('1'):
					cout << "      ��ͷԪ��Ϊ��" << *(int*)e;//(*((int*)e));
					break;
				case('2'):
					cout << "      ��ͷԪ��Ϊ��" << *((unsigned*)e);
					break;
				case('3'):
					cout << "      ��ͷԪ��Ϊ��" << *((char*)e);
					break;
				case('4'):
					cout << "      ��ͷԪ��Ϊ��" << *((string*)e);
					break;
				case('5'):
					cout << "      ��ͷԪ��Ϊ��" << *((float*)e);
					break;
				case('6'):
					cout << "      ��ͷԪ��Ϊ��" << *((double*)e);
					break;
				}
			}
			else
			{
				cout << "      �鿴��ͷԪ��ʧ��";
			}
			break;

		case(6):
			count = LengthAQueue(&Q);
			if (count)
			{
				cout << "      ���еĳ���Ϊ��" << count;
			}
			else
			{
				cout << "      ��ȡ���г���ʧ��";
			}
			count = NULL;
			break;

		case(7):
			cout << "      ��������" << endl
				<< "       1.����" << endl
				<< "       2.�޷�������" << endl
				<< "       3.�ַ���" << endl
				<< "       4.�ַ���" << endl
				<< "       5.��������" << endl
				<< "       6.˫������" << endl
				<< "      �������������ͣ�" << endl << "       ";
			cin >> type;
			cout << endl << "      ���������ݣ�" << endl << "       ";
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
				cout << "      ��ӳɹ�";
			}
			else
			{
				cout << "      ���ʧ��";
			}
			break;

		case(8):
			judge = DeAQueue(&Q);
			if (judge)
			{
				cout << "      ���ӳɹ�";
			}
			else
			{
				cout << "      ����ʧ��";
			}
			break;

		case(9):
			ClearAQueue(&Q);
			cout << "      ��ճɹ�";
			break;

		case(10):
			judge = TraverseAQueue(&Q, APrint);
			if (judge)
			{
				cout << "      �����ɹ�";
			}
			else
			{
				cout << "      ����ʧ��";
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
