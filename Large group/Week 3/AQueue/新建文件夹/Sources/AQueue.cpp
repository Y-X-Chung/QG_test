#include<iostream>
using namespace std;
#include"AQueue.h"

void InitAQueue(AQueue* Q)//初始化队列
{
	Q->length = 0;//队列长度为0
	Q->front = 0;
	Q->rear = 0;//队列头，尾指针都指向0
	//Q->data = (Aqueue*)malloc(MAXQUEUE);
}

void DestoryAQueue(AQueue* Q)//销毁队列
{
	free(Q->data); //释放队列中存放数据的数组
}

Status IsFullAQueue(const AQueue* Q)//检查队列是否已满
{
	if (Q->length == 10)
		return TRUE;
	else
		return FALSE;
}

Status IsEmptyAQueue(const AQueue* Q)//检查队列是否为空
{
	if (Q->length == 0)
		return TRUE;
	else
		return FALSE;
}

//void judge_h_type(AQueue* Q, void* e, void* h, char datatype[MAXQUEUE])//判断队头元素数据类型
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

Status GetHeadAQueue(AQueue* Q, void** e)//查看队头元素
{
	if (IsEmptyAQueue(Q))
		return FALSE;//队列为空
	else
	{
		*e = Q->data[Q->front];
		return TRUE;
	}
}

int LengthAQueue(AQueue* Q)//确定队列长度
{
	int count = Q->length;
	return count;
}

//void judge_type(AQueue* Q, char type, void* data, char *d)//判断数据类型
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

Status EnAQueue(AQueue* Q, void* data)//入队操作
{
	if (IsFullAQueue(Q))
		return FALSE;//队列已满
	else
	{
		Q->data[Q->rear] = data;
		Q->length++;
		if (Q->rear >= 9)
			Q->rear = 0;
		else
			Q->rear++;//实现循环
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

Status DeAQueue(AQueue* Q)//出队操作
{
	if (IsEmptyAQueue(Q))
		return FALSE;//队列为空
	else
	{
		Q->data[Q->front] = NULL;
		Q->length--;
		if (Q->front >= 9)
			Q->front = 0;
		else
			Q->front++;//实现循环
		return TRUE;
	}
}

void ClearAQueue(AQueue* Q)//清空队列
{
	while (Q->length != 0)
	{
		Q->data[Q->front] = NULL;
		Q->length--;
		if (Q->front >= 9)
			Q->front = 0;
		else
			Q->front++;//实现循环
	}
}

Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q))//遍历函数操作
{
	if (IsEmptyAQueue(Q))
		return FALSE;//队列为空
	else
	{
		for (int p = Q->front; p <= Q->rear; p++)
		{
			foo(Q->data[p]);
		}
	return TRUE;
	}
}

void APrint(void* q)//打印队列
{
	cout <<"       "<< q <<endl;
}



