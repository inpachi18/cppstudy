#include<stdio.h>
#include<stdbool.h>					//bool（布尔类型的头文件） 
#include<string.h>
#define maxsize 20				//定义数组大小为20

typedef int elementype;		//int类型别名

typedef struct node{
	elementype data[maxsize];			//数据域 
	elementype top;						//栈顶指针 
}myStack;				

void visit(elementype c)			//访问栈中的元素 
{
	printf("%d ", c);
}

bool initstack(myStack *s)			//初始化栈 
{
	//这里没有给data申请空间建应该是因为数组的大小已经定义完成 
	s -> top = -1;	
	return true;
}

bool stackempty(myStack s)			//判断栈是否为空 
{
	if(s.top == -1)
		return true;
	else 
		return false;
} 

bool ClearStack(myStack *s) 		//将栈清空 
{ 
        s -> top = -1;
        return true;
}

elementype length(myStack s)		//计算栈中元素的个数 
{
	return s.top + 1;
}

bool getTop(myStack s, elementype *e)	//获得栈顶元素 
{
	if(s.top == -1)
		return false;
	else
		*e = s.data[s.top];
	return true;
}

bool push(myStack *s, elementype e)			//元素e入栈 
{
	if(s -> top == maxsize - 1)
		return false;
	else
	{
		s -> top++;				//栈顶指针加一 
		s -> data[s -> top] = e;		//新插入的元素进栈 
		return true;
	 } 
}

void traverse(myStack s)		//遍历栈中元素并进行打印 
{
	int i = 0;
	while(i <= s.top)			 
		visit(s.data[i++]);
	printf("\n");
} 

bool pop(myStack *s, elementype *e)		//栈顶元素出栈 
{
	if(s -> top == -1)
		return false;
	else
	{
		*e = s -> data[s -> top];
		s -> top--;			//栈顶指针减一 
		return true;
	}
}