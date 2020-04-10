# Stack

顺序栈和链表栈 

for QG Studio

What you see now is Chen Weihong's **2nd** QG Studio training camp assignment. In the process of learning, I refer to the CSDN website.

Including：初始化栈、判断栈是否为空、得到栈顶元素、清空栈、销毁栈、检测栈长度、入栈、出栈。

通过以“堆叠在一起的盘子”为例，形象地认识了栈。在栈的使用中，又再一次感受到指针的魅力。

栈顶指针s->top的使用十分重要，他不仅可以判断栈是否为空、得到栈顶元素，还在入栈、出栈中有重要作用。入栈要判断栈是否为满，出栈要判断栈是否为空。清空栈并不是销毁栈，清空只是把所有元素出栈而已，栈还是可以继续使用的 。销毁栈要把申请的内存空间全部free。清空栈也可以循环调用出栈接口。

栈与栈的应用 https://github.com/wmsofts/Calculator_V2



错误记录：

程序测试发现LinkStack.exe概率性发生闪退。

