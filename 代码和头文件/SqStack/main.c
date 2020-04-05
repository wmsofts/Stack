#include "../head/SqStack.h"
#include "../SqStack/SqStack.c" 
#include "stdlib.h"
#include "stdio.h" 
#define SIZE 10

int main(){
	SqStack S;
	int num;
	int ret;
	printf("***************  �Զ����Գ���  ***************\n") ;
	//��ʼ��ջ 
	initStack(&S,SIZE);
	
	//����1����ջ 
	printf("���ԣ������Զ�������0-9��ջ��\n"); 
	for(num = 0; num < SIZE; num++){
		ret = pushStack(&S, num);
		if(ret == 0){
			printf("������ջ���ִ���\n");	
			exit(1);
		}
	}	
	printf("��ȷ����ջ��ɡ�\n\n") ; 
	
	//����2���ж�ջ�Ƿ�Ϊ�� 
	printf("���ԣ��ж����ڵ�ջ�Ƿ�Ϊ�ա�\n");
	ret = isEmptyStack(&S) ;
	if(ret == -1) {
	printf("�����ջΪ�ա�\n\n");
	}
	else printf("�����ջ��Ϊ�ա�\n\n") ;
	
	//����3���õ�ջ��Ԫ��
	int *e=NULL; 
	getTopStack(&S,&e); 
	printf("���ԣ�ջ��Ԫ�أ�%d\n",e) ;
	
	//����4�� ջ�� 
	e = NULL;
	stackLength(&S,&e);
	printf("���ԣ�ջ���ȣ�%d\n",e) ;
    
    //����5����ջ
    printf("\n���ԣ���ջջ����Ԫ�ء�\n");
	ret = popStack(&S);
    if(ret == 1) printf("��ȷ����ջ�ɹ���\n");
	else printf("���󣺳�ջ����"); 
	e=NULL; 
	getTopStack(&S,&e); 
	printf("���ԣ����ڵ�ջ��Ԫ�أ�%d\n",e) ;
	e = NULL;
	stackLength(&S,&e);
	printf("���ԣ����ڵ�ջ���ȣ�%d\n\n",e) ;
	
	//����6�����ջ
	printf("���ԣ����ջ��\n");
	ret = clearStack(&S) ;
	if(ret == 1) printf("��ȷ�����ջ�ɹ���\n");
	else printf("�������ջʧ�ܡ�"); 
	e=NULL; 
	getTopStack(&S,&e); 
	printf("���ԣ����ڵ�ջ��Ԫ�أ�%d\n",e) ;
	e = NULL;
	stackLength(&S,&e);
	printf("���ԣ����ڵ�ջ���ȣ�%d\n\n",e) ;
	
	//����7������ջ
	printf("���ԣ�����ջ�����Ƚ�����ִ����ջ���ٲ������١�\n") ;
	for(num = 0; num < SIZE; num++){
	ret = pushStack(&S, num);
		if(ret == 0){
			printf("������ջ���ִ���\n");	
			exit(1);
		}
	}	
	printf("��ȷ����ջ��ɣ�������ִ�����١�\n") ; 
	ret = destroyStack(&S);
	if(ret == 1) printf("��ȷ������ջ�ɹ���\n");
	else printf("��������ջʧ�ܡ�"); 

	
	printf("***************  �Զ����Խ���  ***************\n") ;
	
	getch();
	getch();
}
