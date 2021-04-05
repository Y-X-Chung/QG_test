#include<iostream>
using namespace std;
#include"LinkStack.h"

Status initLStack(LinkStack* s)//初始化栈
{
	if (!s)
	{
		return ERROR;//初始化失败
	}
	else
	{
		s->top = new StackNode;//栈顶指针指向栈底
		s->top->next = NULL;
		s->count = 0;//目前栈的大小
		return SUCCESS;	
	}
}

Status isEmptyLStack(LinkStack* s)//判断栈是否为空
{
	//while (s->top == NULL)
	//{
	//	if (s->count == 0)
	//	{
	//		return ERROR;//判断为空栈
	//		break;
	//	}
	//	StackNode* p = NULL;
	//	p->next = s->top;
	//	s->top->next = p->next;
	//	s->count--;
	//}
	if (s->count > 0)
	{
		return SUCCESS;//判断不为空栈
	}
	else
	{
		return ERROR;//判断为空栈
	}
}

Status getTopLStack(LinkStack* s, ElemType* e) //得到栈顶元素
{
	if (s->count == 0)
	{
		cout << "      空栈，无法获取栈顶元素" << endl;
		return ERROR;//空栈，无法获取栈顶元素
	}
	else
	{
		(*e) = s->top->data;//将栈顶元素赋给e
		return SUCCESS;
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
	return SUCCESS;
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
	return SUCCESS;
}

Status LStackLength(LinkStack* s, int* length)//检测栈长度
{
	//while (s->top->data == NULL)
	//{
	//	StackNode* p = NULL;
	//	p->next = s->top;
	//	s->top->next = p->next;
	//	s->count--;
	//	if (s->count == 0)
	//	{
	//		break;//空栈
	//	}
	//}
	(*length) = s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack* s, ElemType data)//入栈
{
	StackNode* p = new StackNode;
	p->next = s->top;
	p->data = data;//数据入栈
	s->top = p;
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack* s, ElemType* data)//出栈
{
	if (s->count == 0)
	{
		cout << "      空栈，无法出栈" << endl;
		return ERROR;//空栈，无法出栈
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