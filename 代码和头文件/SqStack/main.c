#include "../head/SqStack.h"
#include "../SqStack/SqStack.c" 
#include "stdlib.h"
#include "stdio.h" 
#define SIZE 10

int main(){
	SqStack S;
	int num;
	int ret;
	printf("***************  自动测试程序  ***************\n") ;
	//初始化栈 
	initStack(&S,SIZE);
	
	//测试1：入栈 
	printf("测试：程序将自动把数字0-9入栈。\n"); 
	for(num = 0; num < SIZE; num++){
		ret = pushStack(&S, num);
		if(ret == 0){
			printf("错误：入栈出现错误。\n");	
			exit(1);
		}
	}	
	printf("正确：入栈完成。\n\n") ; 
	
	//测试2：判断栈是否为空 
	printf("测试：判断现在的栈是否为空。\n");
	ret = isEmptyStack(&S) ;
	if(ret == -1) {
	printf("结果：栈为空。\n\n");
	}
	else printf("结果：栈不为空。\n\n") ;
	
	//测试3：得到栈顶元素
	int *e=NULL; 
	getTopStack(&S,&e); 
	printf("测试：栈顶元素：%d\n",e) ;
	
	//测试4： 栈长 
	e = NULL;
	stackLength(&S,&e);
	printf("测试：栈长度：%d\n",e) ;
    
    //测试5：出栈
    printf("\n测试：出栈栈顶的元素。\n");
	ret = popStack(&S);
    if(ret == 1) printf("正确：出栈成功。\n");
	else printf("错误：出栈错误。"); 
	e=NULL; 
	getTopStack(&S,&e); 
	printf("测试：现在的栈顶元素：%d\n",e) ;
	e = NULL;
	stackLength(&S,&e);
	printf("测试：现在的栈长度：%d\n\n",e) ;
	
	//测试6：清空栈
	printf("测试：清空栈。\n");
	ret = clearStack(&S) ;
	if(ret == 1) printf("正确：清空栈成功。\n");
	else printf("错误：清空栈失败。"); 
	e=NULL; 
	getTopStack(&S,&e); 
	printf("测试：现在的栈顶元素：%d\n",e) ;
	e = NULL;
	stackLength(&S,&e);
	printf("测试：现在的栈长度：%d\n\n",e) ;
	
	//测试7：销毁栈
	printf("测试：销毁栈。首先将重新执行入栈，再测试销毁。\n") ;
	for(num = 0; num < SIZE; num++){
	ret = pushStack(&S, num);
		if(ret == 0){
			printf("错误：入栈出现错误。\n");	
			exit(1);
		}
	}	
	printf("正确：入栈完成，接下来执行销毁。\n") ; 
	ret = destroyStack(&S);
	if(ret == 1) printf("正确：销毁栈成功。\n");
	else printf("错误：销毁栈失败。"); 

	
	printf("***************  自动测试结束  ***************\n") ;
	
	getch();
	getch();
}
