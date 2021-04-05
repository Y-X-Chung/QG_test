#include<iostream>
using namespace std;
#include"LinkStack.h"

Status initLStack(LinkStack* s)//��ʼ��ջ
{
	if (!s)
	{
		return ERROR;//��ʼ��ʧ��
	}
	else
	{
		s->top = new StackNode;//ջ��ָ��ָ��ջ��
		s->top->next = NULL;
		s->count = 0;//Ŀǰջ�Ĵ�С
		return SUCCESS;	
	}
}

Status isEmptyLStack(LinkStack* s)//�ж�ջ�Ƿ�Ϊ��
{
	//while (s->top == NULL)
	//{
	//	if (s->count == 0)
	//	{
	//		return ERROR;//�ж�Ϊ��ջ
	//		break;
	//	}
	//	StackNode* p = NULL;
	//	p->next = s->top;
	//	s->top->next = p->next;
	//	s->count--;
	//}
	if (s->count > 0)
	{
		return SUCCESS;//�жϲ�Ϊ��ջ
	}
	else
	{
		return ERROR;//�ж�Ϊ��ջ
	}
}

Status getTopLStack(LinkStack* s, ElemType* e) //�õ�ջ��Ԫ��
{
	if (s->count == 0)
	{
		cout << "      ��ջ���޷���ȡջ��Ԫ��" << endl;
		return ERROR;//��ջ���޷���ȡջ��Ԫ��
	}
	else
	{
		(*e) = s->top->data;//��ջ��Ԫ�ظ���e
		return SUCCESS;
	}
}

Status clearLStack(LinkStack* s)//���ջ
{
	while (s->count != 0)
	{
		StackNode* p = s->top;
		s->top = p->next;
		p->data = NULL;
		s->count--;
	}//ջ�����±�Ϊջ��
	return SUCCESS;
}

Status destroyLStack(LinkStack* s)//����ջ
{
	while (s->count != 0)
	{
		StackNode* p = s->top;
		s->top = p->next;
		delete(p);
		s->count--;
	}//ջ�����±�Ϊջ��
	return SUCCESS;
}

Status LStackLength(LinkStack* s, int* length)//���ջ����
{
	//while (s->top->data == NULL)
	//{
	//	StackNode* p = NULL;
	//	p->next = s->top;
	//	s->top->next = p->next;
	//	s->count--;
	//	if (s->count == 0)
	//	{
	//		break;//��ջ
	//	}
	//}
	(*length) = s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack* s, ElemType data)//��ջ
{
	StackNode* p = new StackNode;
	p->next = s->top;
	p->data = data;//������ջ
	s->top = p;
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack* s, ElemType* data)//��ջ
{
	if (s->count == 0)
	{
		cout << "      ��ջ���޷���ջ" << endl;
		return ERROR;//��ջ���޷���ջ
	}
	else
	{
		(*data) = s->top->data;
		StackNode* p = s->top;
		s->top = p->next;
		delete(p);
		s->count--;
		return SUCCESS;
	}
}