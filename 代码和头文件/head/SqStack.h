#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
//���������˳��ջ

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
	int size;			//ջ�Ĵ�С
} SqStack;

//���������˳��ջ
Status initStack(SqStack *s,int sizes);//��ʼ��ջ
Status isEmptyStack(SqStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopStack(SqStack *s,ElemType *e); //�õ�ջ��Ԫ��
Status clearStack(SqStack *s);//���ջ
Status destroyStack(SqStack *s);//����ջ
Status stackLength(SqStack *s,int *length);//���ջ����
Status pushStack(SqStack *s,ElemType data);//��ջ
Status popStack(SqStack *s);//��ջ


#endif 
