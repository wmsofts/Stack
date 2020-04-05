#include "../head/SqStack.h"
#include "stdlib.h"
#include "stdio.h" 
#define SUCCESS 1
#define ERROR 0

//��ʼ��ջ
Status initStack(SqStack *s,int sizes)
{
	s->elem = (ElemType*)malloc(sizes * sizeof(ElemType));
	if (!s->elem)
		return ERROR;
	s->top = -1;
	s->size = sizes;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack *s)  
{
	//Ҫ�ж�ջ�Ƿ�Ϊ�գ�˳��ջ���ǿ� s->top �ǲ��ǵ��� -1
	return s->top == -1;
}

//�õ�ջ��Ԫ�� 
Status getTopStack(SqStack *s,ElemType *e) 
{
	if (s->top == -1)
		return ERROR;
	*e = s->elem[s->top];//ջ��ָ��ָ��λ��
	return SUCCESS;
}

//���ջ
//��ղ��������٣����ֻ�ǰ�����Ԫ�س�ջ���ѣ�ջ���ǿ��Լ���ʹ�õ� 
Status clearStack(SqStack *s) 
{
	if (!s)
		return ERROR;
	s->top = -1;
	return SUCCESS;
}

//����ջ
Status destroyStack(SqStack *s)
{
	if (!s)
		return ERROR;
	free(s->elem);//��������ڴ�ռ�ȫ��free 
	return SUCCESS;
}

//ջ�� 
Status stackLength(SqStack *s,int *length)  
{
	if (!s)
		return ERROR;
	*length = s->top + 1;//ջ�� 
	return SUCCESS;
}

//��ջ 
Status pushStack(SqStack *s,ElemType data) 
{
	if (!s || s->top == s->size - 1)		//�ж�ջ�Ƿ�����
		return ERROR;
	s->top++;
	s->elem[s->top] = data;
	return SUCCESS;
}

//��ջ 
Status popStack(SqStack *s)  
{
	if (!s || s->top == -1)		//�ж�ջ�Ƿ�Ϊ��
		return ERROR;
	s->top--;
	return SUCCESS;
}



