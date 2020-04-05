#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
//基于数组的顺序栈

// define Status
typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

// define element type
typedef int ElemType;

// define struct of stack
typedef struct SqStack 
{
	ElemType *elem;
	int top;
	int size;			//栈的大小
} SqStack;

//基于数组的顺序栈
Status initStack(SqStack *s,int sizes);//初始化栈
Status isEmptyStack(SqStack *s);//判断栈是否为空
Status getTopStack(SqStack *s,ElemType *e); //得到栈顶元素
Status clearStack(SqStack *s);//清空栈
Status destroyStack(SqStack *s);//销毁栈
Status stackLength(SqStack *s,int *length);//检测栈长度
Status pushStack(SqStack *s,ElemType data);//入栈
Status popStack(SqStack *s);//出栈


#endif 
