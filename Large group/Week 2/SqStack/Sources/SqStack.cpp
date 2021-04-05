#include<iostream>
using namespace std;
#include"SqStack.h"

Status initStack(SqStack* s, int sizes)//��ʼ��ջ
{
	if (!s)
	{
		return ERROR;//��ʼ��ʧ��1
	}
	else
	{
		s->size = sizes;//ָ��ջ�Ĵ�С
		s->elem = (ElemType*)malloc(sizeof(s->size));//��������
		if (!s->elem)
		{
			delete(s);
			return ERROR;//��ʼ��ʧ��
		}
		else
		{
			s->top = -1;//ʹջ��ָ����±�Ϊ-1��ָ��ջ�ף�
			return SUCCESS;
		}
	}
}

Status isEmptyStack(SqStack* s)//�ж�ջ�Ƿ�Ϊ��
{
	//while (s->elem + s->top == NULL)
	//{
	//	if (s->top <= -1)
	//	{
	//		return ERROR;//�ж�Ϊ��ջ
	//		break;
	//	}
	//	s->top--;
	//}
	//if(s->top > -1)
	//{
	//	return SUCCESS;//�жϲ�Ϊ��ջ
	//}
	if (s->top > -1)
	{
		return SUCCESS;//�жϲ�Ϊ��ջ
	}
	else
	{
		return ERROR;//�ж�Ϊ��ջ
	}
}

Status getTopStack(SqStack* s, ElemType* e) //�õ�ջ��Ԫ��
{
	if (s->top == -1)
	{
		cout << "      ��ջ���޷���ȡջ��Ԫ��" << endl;
		return ERROR;//��ջ���޷���ȡջ��Ԫ��
	}
	else
	{
		(*e) = (*s->elem + s->top);//��ջ��Ԫ�ظ���e
		return SUCCESS;
	}
}

Status clearStack(SqStack* s)//���ջ
{
	while(s->top != -1)
	{
		*(s->elem+s->top) = NULL;
		s->top--;
	}//ջ�����±�Ϊջ��
	return SUCCESS;
}

Status destroyStack(SqStack* s)//����ջ
{
	free(s->elem); //�ͷ�ջ������
	return SUCCESS;
}

Status stackLength(SqStack* s, int* length)//���ջ����
{
	//while (*(s->elem + s->top) == NULL)
	//{
	//	s->top--;
	//	if (s->top <= -1)
	//	{
	//		break;//��ջ
	//	}
	//}
	(*length) = s->top + 1;
	return SUCCESS;
}

Status pushStack(SqStack* s, ElemType data)//��ջ
{
	if (s->top == s->size - 1)
	{
		cout << "      ��ջ���޷���ջ" << endl;
		return ERROR;//��ջ���޷���ջ
	}
	else
	{
		*((s->elem)+(s->top + 1)) = data;//������ջ
		s->top++;//ջ����һ
	}
}

Status popStack(SqStack* s, ElemType* data)//��ջ
{
	if (s->top == -1)
	{
		cout << "      ��ջ���޷���ջ" << endl;
		return ERROR;//��ջ���޷���ջ
	}
	else
	{
		(*data) = s->elem[s->top];
		*(s->elem + s->top) = NULL;
		s->top--;
		return SUCCESS;
	}
}

