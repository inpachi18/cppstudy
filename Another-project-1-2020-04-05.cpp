#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define maxsize 1000

typedef int elementype;

typedef struct node{
	elementype data[maxsize];
	elementype top;
}myStack;				

void visit(elementype c)
{
	printf("%d ", c);
}

bool initstack(myStack *s)
{
	s -> top = -1;	
	return true;
}

bool stackempty(myStack s)
{
	if(s.top == -1)
		return true;
	else 
		return false;
} 

bool ClearStack(myStack *s)
{ 
        s -> top = -1;
        return true;
}

elementype length(myStack s)
{
	return s.top + 1;
}

bool getTop(myStack s, elementype *e)
{
	if(s.top == -1)
		return false;
	else
		*e = s.data[s.top];
	return true;
}

bool push(myStack *s, elementype e)
{
	if(s -> top == maxsize - 1)
		return false;
	else
	{
		s -> top++;
		s -> data[s -> top] = e;
		return true;
	 } 
}

void traverse(myStack s)
{
	int i = 0;
	while(i <= s.top)			 
		visit(s.data[i++]);
	printf("\n");
} 

bool pop(myStack *s, elementype *e)
{
	if(s -> top == -1)
		return false;
	else
	{
		*e = s -> data[s -> top];
		s -> top--;	
		return true;
	}
}

int main()
{
    int T,N,Q,i,j,k,Choice,Input1,Input2,Temp;
    scanf("%d",&T);
    for (i=0;i<T;i++)
    {
        scanf("%d %d",&N,&Q);
        myStack S[N+1];
        for (j=0;j<Q;j++)
        {
            scanf("%d",&Choice);
            if (Choice==1)
            {
                scanf ("%d %d",&Input1,&Input2);
                push(&S[Input1],Input2);
            }
            else if (Choice==2)
            {
                scanf ("%d",&Input1);
                if (stackempty(S[Input1]))
                {
                    printf("EMPTY\n");
                }
                else
                {
                    pop(&S[Input1],&Temp);
                    printf("%d\n",Temp);
                }
            }
            else if (Choice==2)
            {
                scanf ("%d %d",&Input1,&Input2);
                while (S[Input2].top > -1)
                {
                    pop(&S[Input2],&Temp);
                    push(&S[0],Temp);
                }
                while (S[0].top > -1)
                {
                    pop(&S[0],&Temp);
                    push(&S[Input1],Temp);
                }
            }
        }
    }
    return 0;
};
