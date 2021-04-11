#include<iostream>
using namespace std;
#include"AQueue.h"

void InitAQueue(AQueue* Q)//��ʼ������
{
	Q->length = 0;//���г���Ϊ0
	Q->front = 0;
	Q->rear = 0;//����ͷ��βָ�붼ָ��0
	//Q->data = (Aqueue*)malloc(MAXQUEUE);
}

void DestoryAQueue(AQueue* Q)//���ٶ���
{
	free(Q->data); //�ͷŶ����д�����ݵ�����
}

Status IsFullAQueue(const AQueue* Q)//�������Ƿ�����
{
	if (Q->length == 10)
		return TRUE;
	else
		return FALSE;
}

Status IsEmptyAQueue(const AQueue* Q)//�������Ƿ�Ϊ��
{
	if (Q->length == 0)
		return TRUE;
	else
		return FALSE;
}

//void judge_h_type(AQueue* Q, void* e, void* h, char datatype[MAXQUEUE])//�ж϶�ͷԪ����������
//{
//	switch (datatype[Q->front])
//	{
//	case('1'):
//		//		cout<<*((int *) e);
//		(int*)e;
//		break;
//	case('2'):
//		//		cout << *((unsigned*)e);
//		(unsigned*)e;
//		break;
//	case('3'):
//		//		cout << *((char*)e);
//		(char*)e;
//		break;
//	case('4'):
//		//		cout << *((string*)e);
//		(string*)e;
//		break;
//	case('5'):
//		//		cout << *((float*)e);
//		(float*)e;
//		break;
//	case('6'):
//		//		cout << *((double*)e);
//		(double*)e;
//		break;
//	}
//}

Status GetHeadAQueue(AQueue* Q, void** e)//�鿴��ͷԪ��
{
	if (IsEmptyAQueue(Q))
		return FALSE;//����Ϊ��
	else
	{
		*e = Q->data[Q->front];
		return TRUE;
	}
}

int LengthAQueue(AQueue* Q)//ȷ�����г���
{
	int count = Q->length;
	return count;
}

//void judge_type(AQueue* Q, char type, void* data, char *d)//�ж���������
//{
//	int* data_int = NULL;
//	unsigned* data_unsigned = NULL;
//	char* data_char = NULL;
//	string* data_string = NULL;
//	float* data_float = NULL;
//	double* data_double = NULL;
//	(*d) = type;
//	switch (type)
//	{
//	case('1'):
//		data_int = new int ;
//		cin >> *data_int;
//		data = data_int;
//		break;
//	case('2'):
//		data_unsigned = new unsigned;
//		cin >> *data_unsigned;
//		data = data_unsigned;
//		break;
//	case('3'):
//		data_char = new char;
//		cin >> *data_char;
//		data = data_char;
//		break;
//	case('4'):
//		data_string = new string;
//		cin >> *data_string;
//		data = data_string;
//		break;
//	case('5'):
//		data_float = new float;
//		cin >> *data_float;
//		data = data_float;
//		break;
//	case('6'):
//		data_double = new double;
//		cin >> *data_double;
//		data = data_double;
//		break;
//	}
//}

Status EnAQueue(AQueue* Q, void* data)//��Ӳ���
{
	if (IsFullAQueue(Q))
		return FALSE;//��������
	else
	{
		Q->data[Q->rear] = data;
		Q->length++;
		if (Q->rear >= 9)
			Q->rear = 0;
		else
			Q->rear++;//ʵ��ѭ��
		return TRUE;
	}
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

Status DeAQueue(AQueue* Q)//���Ӳ���
{
	if (IsEmptyAQueue(Q))
		return FALSE;//����Ϊ��
	else
	{
		Q->data[Q->front] = NULL;
		Q->length--;
		if (Q->front >= 9)
			Q->front = 0;
		else
			Q->front++;//ʵ��ѭ��
		return TRUE;
	}
}

void ClearAQueue(AQueue* Q)//��ն���
{
	while (Q->length != 0)
	{
		Q->data[Q->front] = NULL;
		Q->length--;
		if (Q->front >= 9)
			Q->front = 0;
		else
			Q->front++;//ʵ��ѭ��
	}
}

Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q))//������������
{
	if (IsEmptyAQueue(Q))
		return FALSE;//����Ϊ��
	else
	{
		for (int p = Q->front; p <= Q->rear; p++)
		{
			foo(Q->data[p]);
		}
	return TRUE;
	}
}

void APrint(void* q)//��ӡ����
{
	cout <<"       "<< q <<endl;
}



