#include<iostream>
using namespace std;
#include"SqStack.h"

Status initStack(SqStack* s, int sizes)//初始化栈
{
	if (!s)
	{
		return ERROR;//初始化失败1
	}
	else
	{
		s->size = sizes;//指定栈的大小
		s->elem = (ElemType*)malloc(sizeof(s->size));//构造数组
		if (!s->elem)
		{
			delete(s);
			return ERROR;//初始化失败
		}
		else
		{
			s->top = -1;//使栈顶指针的下标为-1（指向栈底）
			return SUCCESS;
		}
	}
}

Status isEmptyStack(SqStack* s)//判断栈是否为空
{
	//while (s->elem + s->top == NULL)
	//{
	//	if (s->top <= -1)
	//	{
	//		return ERROR;//判断为空栈
	//		break;
	//	}
	//	s->top--;
	//}
	//if(s->top > -1)
	//{
	//	return SUCCESS;//判断不为空栈
	//}
	if (s->top > -1)
	{
		return SUCCESS;//判断不为空栈
	}
	else
	{
		return ERROR;//判断为空栈
	}
}

Status getTopStack(SqStack* s, ElemType* e) //得到栈顶元素
{
	if (s->top == -1)
	{
		cout << "      空栈，无法获取栈顶元素" << endl;
		return ERROR;//空栈，无法获取栈顶元素
	}
	else
	{
		(*e) = (*s->elem + s->top);//将栈顶元素赋给e
		return SUCCESS;
	}
}

Status clearStack(SqStack* s)//清空栈
{
	while(s->top != -1)
	{
		*(s->elem+s->top) = NULL;
		s->top--;
	}//栈顶重新变为栈底
	return SUCCESS;
}

Status destroyStack(SqStack* s)//销毁栈
{
	free(s->elem); //释放栈的数组
	return SUCCESS;
}

Status stackLength(SqStack* s, int* length)//检测栈长度
{
	//while (*(s->elem + s->top) == NULL)
	//{
	//	s->top--;
	//	if (s->top <= -1)
	//	{
	//		break;//空栈
	//	}
	//}
	(*length) = s->top + 1;
	return SUCCESS;
}

Status pushStack(SqStack* s, ElemType data)//入栈
{
	if (s->top == s->size - 1)
	{
		cout << "      满栈，无法入栈" << endl;
		return ERROR;//满栈，无法入栈
	}
	else
	{
		*((s->elem)+(s->top + 1)) = data;//数据入栈
		s->top++;//栈顶加一
	}
}

Status popStack(SqStack* s, ElemType* data)//出栈
{
	if (s->top == -1)
	{
		cout << "      空栈，无法出栈" << endl;
		return ERROR;//空栈，无法出栈
	}
	else
	{
		(*data) = s->elem[s->top];
		*(s->elem + s->top) = NULL;
		s->top--;
		return SUCCESS;
	}
}

