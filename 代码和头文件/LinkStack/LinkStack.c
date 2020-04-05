#include "../head/LinkStack.h"
#include "stdlib.h"
#include "stdio.h"
#define SUCCESS 1
#define ERROR 0 

//初始化栈
Status initLStack(LinkStack *s)
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	//为 s->top 申请内存空间,这个空间是指针的空间，不是栈的空间
	if (!s->top)
		return ERROR;
	s->count = 0;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s)  
{
	//链栈就看 s->count 是不是等于 0
	return s->count == 0;
}

//得到栈顶元素 
Status getTopLStack(LinkStack *s,ElemType *e) 
{
	if(s->count == 0 || !s->top)
		return ERROR;
	*e = s->top->next->data;  //栈顶指针指的位置 
	return SUCCESS;
}

//清空栈
//清空并不是销毁，清空只是把所有元素出栈而已，栈还是可以继续使用的 
Status clearLStack(LinkStack *s) 
{
	LinkStackPtr ptem=NULL;
	LinkStackPtr p = s->top->next;			//p指向栈顶元素
	if (!(s->top))
		return ERROR;
	while (p){						//这里也可以循环调用出栈接口
		ptem = p->next;
		free(p);					//free栈顶元素
		p = ptem;
	}
	s->count = 0;					//计数器归零
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack *s) 
{
	LinkStackPtr ptem, p = s->top->next;
	if (!s->top)
		return ERROR;
	while (s->count != 0){			//或者调用清空接口
		ptem = p->next;
		free(p);				//把申请的内存空间全部free 
		s->top->next = ptem;
		s->count--;
	}
	free(s->top);
	return SUCCESS;
}

//栈长  
Status LStackLength(LinkStack *s,int *length)
{
	if (!s->top)
		return ERROR;
	*length = s->count; //栈长 
	return SUCCESS;
}

//入栈 
Status pushLStack(LinkStack *s,ElemType data)
{
	StackNode *p;
	if(!s->top)
		return ERROR;
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top->next;
	s->top->next = p;
	s->count++;
	return SUCCESS;
}

//出栈 
Status popLStack(LinkStack *s, ElemType *data)
{
	LinkStackPtr ptem, p = s->top->next;
	if(!s->top || s->count == 0)			
		return ERROR;
	*data = p->data;//出栈的元素存储到 data
	ptem = p->next;
	free(p);
	s->top->next = ptem;
	s->count--;
	return SUCCESS;
}




