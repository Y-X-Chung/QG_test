#include<iostream>
#include"binary_sort_tree.h"
#include"LinkStack.h"
using namespace std;

Status initLStack(LinkStack* s)//初始化栈
{
	if (!s)
	{
		return failed;//初始化失败
	}
	else
	{
		s->top = new StackNode;//栈顶指针指向栈底
		s->top->next = NULL;
		s->count = 0;//目前栈的大小
		return succeed;
	}
}

Status isEmptyLStack(LinkStack* s)//判断栈是否为空
{
	if (s->count > 0)
	{
		return succeed;//判断不为空栈
	}
	else
	{
		return failed;//判断为空栈
	}
}

Status getTopLStack(LinkStack* s, ElemType* e) //得到栈顶元素
{
	if (s->count == 0)
	{
		cout << "      空栈，无法获取栈顶元素" << endl;
		return failed;//空栈，无法获取栈顶元素
	}
	else
	{
		(*e) = s->top->data;//将栈顶元素赋给e
		return succeed;
	}
}

Status clearLStack(LinkStack* s)//清空栈
{
	while (s->count != 0)
	{
		StackNode* p = s->top;
		s->top = p->next;
		p->data = NULL;
		s->count--;
	}//栈顶重新变为栈底
	return succeed;
}

Status destroyLStack(LinkStack* s)//销毁栈
{
	while (s->count != 0)
	{
		StackNode* p = s->top;
		s->top = p->next;
		delete(p);
		s->count--;
	}//栈顶重新变为栈底
	return succeed;
}

Status LStackLength(LinkStack* s, int* length)//检测栈长度
{
	(*length) = s->count;
	return succeed;
}

Status pushLStack(LinkStack* s, ElemType data)//入栈
{
	StackNode* p = new StackNode;
	p->next = s->top;
	p->data = data;//数据入栈
	s->top = p;
	s->count++;
	return succeed;
}

Status popLStack(LinkStack* s/*, ElemType* data*/)//出栈
{
	if (s->count == 0)
	{
		cout << "      空栈，无法出栈" << endl;
		return failed;//空栈，无法出栈
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