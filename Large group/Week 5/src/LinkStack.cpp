#include<iostream>
#include"binary_sort_tree.h"
#include"LinkStack.h"
using namespace std;

Status initLStack(LinkStack* s)//��ʼ��ջ
{
	if (!s)
	{
		return failed;//��ʼ��ʧ��
	}
	else
	{
		s->top = new StackNode;//ջ��ָ��ָ��ջ��
		s->top->next = NULL;
		s->count = 0;//Ŀǰջ�Ĵ�С
		return succeed;
	}
}

Status isEmptyLStack(LinkStack* s)//�ж�ջ�Ƿ�Ϊ��
{
	if (s->count > 0)
	{
		return succeed;//�жϲ�Ϊ��ջ
	}
	else
	{
		return failed;//�ж�Ϊ��ջ
	}
}

Status getTopLStack(LinkStack* s, ElemType* e) //�õ�ջ��Ԫ��
{
	if (s->count == 0)
	{
		cout << "      ��ջ���޷���ȡջ��Ԫ��" << endl;
		return failed;//��ջ���޷���ȡջ��Ԫ��
	}
	else
	{
		(*e) = s->top->data;//��ջ��Ԫ�ظ���e
		return succeed;
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
	return succeed;
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
	return succeed;
}

Status LStackLength(LinkStack* s, int* length)//���ջ����
{
	(*length) = s->count;
	return succeed;
}

Status pushLStack(LinkStack* s, ElemType data)//��ջ
{
	StackNode* p = new StackNode;
	p->next = s->top;
	p->data = data;//������ջ
	s->top = p;
	s->count++;
	return succeed;
}

Status popLStack(LinkStack* s/*, ElemType* data*/)//��ջ
{
	if (s->count == 0)
	{
		cout << "      ��ջ���޷���ջ" << endl;
		return failed;//��ջ���޷���ջ
	}
	else
	{
//		(*data) = s->top->data;
		StackNode* p = s->top;
		s->top = p->next;
		delete(p);
		s->count--;
		return succeed;
	}
}