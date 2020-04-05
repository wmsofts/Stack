#include "../head/SqStack.h"
#include "stdlib.h"
#include "stdio.h" 
#define SUCCESS 1
#define ERROR 0

//初始化栈
Status initStack(SqStack *s,int sizes)
{
	s->elem = (ElemType*)malloc(sizes * sizeof(ElemType));
	if (!s->elem)
		return ERROR;
	s->top = -1;
	s->size = sizes;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyStack(SqStack *s)  
{
	//要判断栈是否为空，顺序栈就是看 s->top 是不是等于 -1
	return s->top == -1;
}

//得到栈顶元素 
Status getTopStack(SqStack *s,ElemType *e) 
{
	if (s->top == -1)
		return ERROR;
	*e = s->elem[s->top];//栈顶指针指的位置
	return SUCCESS;
}

//清空栈
//清空并不是销毁，清空只是把所有元素出栈而已，栈还是可以继续使用的 
Status clearStack(SqStack *s) 
{
	if (!s)
		return ERROR;
	s->top = -1;
	return SUCCESS;
}

//销毁栈
Status destroyStack(SqStack *s)
{
	if (!s)
		return ERROR;
	free(s->elem);//把申请的内存空间全部free 
	return SUCCESS;
}

//栈长 
Status stackLength(SqStack *s,int *length)  
{
	if (!s)
		return ERROR;
	*length = s->top + 1;//栈长 
	return SUCCESS;
}

//入栈 
Status pushStack(SqStack *s,ElemType data) 
{
	if (!s || s->top == s->size - 1)		//判断栈是否已满
		return ERROR;
	s->top++;
	s->elem[s->top] = data;
	return SUCCESS;
}

//出栈 
Status popStack(SqStack *s)  
{
	if (!s || s->top == -1)		//判断栈是否为空
		return ERROR;
	s->top--;
	return SUCCESS;
}



