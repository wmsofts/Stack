#include "../head/LinkStack.h"
#include "../LinkStack/LinkStack.c" 
#include "stdlib.h"
#include "stdio.h" 
#define SIZE 10

int main(){
	LinkStack S;
	int num;
	int ret;
	int *e=NULL; 
	printf("***************  �Զ����Գ���  ***************\n") ;
	//��ʼ��ջ 
	initLStack(&S);
	
	//����1����ջ 
	printf("���ԣ������Զ�������0-9��ջ��\n"); 
	for(num = 0; num < SIZE; num++){
		ret = pushLStack(&S, num);
		if(ret == 0){
			printf("������ջ���ִ���\n");	
			exit(1);
		}
	}	
	printf("��ȷ����ջ��ɡ�\n\n") ; 
	
	//����2���ж�ջ�Ƿ�Ϊ�� 
	printf("���ԣ��ж����ڵ�ջ�Ƿ�Ϊ�ա�\n");
	ret = isEmptyLStack(&S) ;
	if(ret == -1) {
	printf("�����ջΪ�ա�\n\n");
	}
	else printf("�����ջ��Ϊ�ա�\n\n") ;
	
	//����3���õ�ջ��Ԫ��
	getTopLStack(&S,&e); 
	printf("���ԣ�ջ��Ԫ�أ�%d\n",e) ;
	
	//����4�� ջ�� 
	e = NULL;
	LStackLength(&S,&e);
	printf("���ԣ�ջ���ȣ�%d\n",e) ;
    
    //����5����ջ
    printf("\n���ԣ���ջջ����Ԫ�ء�\n");
    e = NULL;
	ret = popLStack(&S,&e);
    if(ret == 1) printf("��ȷ����ջ�ɹ���\n");
	else printf("���󣺳�ջ����"); 
	printf("���ԣ���ջ��Ԫ��Ϊ��%d\n",e); 
	e=NULL; 
	getTopLStack(&S,&e); 
	printf("���ԣ����ڵ�ջ��Ԫ�أ�%d\n",e) ;
	e = NULL;
	LStackLength(&S,&e);
	printf("���ԣ����ڵ�ջ���ȣ�%d\n\n",e) ;
	 
	//����6�����ջ 
	printf("���ԣ����ջ��\n");
	ret = clearLStack(&S);
	if(ret == 1) printf("��ȷ�����ջ�ɹ���\n");
	else printf("�������ջʧ�ܡ�"); 
	e=NULL; 
	getTopLStack(&S,&e); 
	printf("���ԣ����ڵ�ջ��Ԫ�أ�%d\n",e) ;
	e = NULL;
	LStackLength(&S,&e);
	printf("���ԣ����ڵ�ջ���ȣ�%d\n\n",e) ; 
	
	//����7������ջ
	printf("���ԣ�����ջ�����Ƚ�����ִ����ջ���ٲ������١�\n") ;
	for(num = 0; num < SIZE; num++){
	ret = pushLStack(&S, num);
		if(ret == 0){
			printf("������ջ���ִ���\n");	
			exit(1);
		}
	}	
	printf("��ȷ����ջ��ɣ�������ִ�����١�\n") ; 
	ret = destroyLStack(&S);
	if(ret == 1) printf("��ȷ������ջ�ɹ���\n");
	else printf("��������ջʧ�ܡ�"); 

	
	printf("***************  �Զ����Խ���  ***************\n") ;
	getch();
	getch();
	getch();
}
