#include "../head/LinkStack.h"
#include "stdlib.h"
#include "stdio.h"
#define SUCCESS 1
#define ERROR 0 

//��ʼ��ջ
Status initLStack(LinkStack *s)
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	//Ϊ s->top �����ڴ�ռ�,����ռ���ָ��Ŀռ䣬����ջ�Ŀռ�
	if (!s->top)
		return ERROR;
	s->count = 0;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s)  
{
	//��ջ�Ϳ� s->count �ǲ��ǵ��� 0
	return s->count == 0;
}

//�õ�ջ��Ԫ�� 
Status getTopLStack(LinkStack *s,ElemType *e) 
{
	if(s->count == 0 || !s->top)
		return ERROR;
	*e = s->top->next->data;  //ջ��ָ��ָ��λ�� 
	return SUCCESS;
}

//���ջ
//��ղ��������٣����ֻ�ǰ�����Ԫ�س�ջ���ѣ�ջ���ǿ��Լ���ʹ�õ� 
Status clearLStack(LinkStack *s) 
{
	LinkStackPtr ptem=NULL;
	LinkStackPtr p = s->top->next;			//pָ��ջ��Ԫ��
	if (!(s->top))
		return ERROR;
	while (p){						//����Ҳ����ѭ�����ó�ջ�ӿ�
		ptem = p->next;
		free(p);					//freeջ��Ԫ��
		p = ptem;
	}
	s->count = 0;					//����������
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s) 
{
	LinkStackPtr ptem, p = s->top->next;
	if (!s->top)
		return ERROR;
	while (s->count != 0){			//���ߵ�����սӿ�
		ptem = p->next;
		free(p);				//��������ڴ�ռ�ȫ��free 
		s->top->next = ptem;
		s->count--;
	}
	free(s->top);
	return SUCCESS;
}

//ջ��  
Status LStackLength(LinkStack *s,int *length)
{
	if (!s->top)
		return ERROR;
	*length = s->count; //ջ�� 
	return SUCCESS;
}

//��ջ 
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

//��ջ 
Status popLStack(LinkStack *s, ElemType *data)
{
	LinkStackPtr ptem, p = s->top->next;
	if(!s->top || s->count == 0)			
		return ERROR;
	*data = p->data;//��ջ��Ԫ�ش洢�� data
	ptem = p->next;
	free(p);
	s->top->next = ptem;
	s->count--;
	return SUCCESS;
}




