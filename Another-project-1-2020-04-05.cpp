#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define maxsize 1000

typedef int elementype;

typedef struct node{
	elementype data[maxsize];
	elementype top;
}myStack;				

bool initstack(myStack *s)
{
	s -> top = -1;	
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
        for (j=0;j<=N;j++)
        {
        	initstack(&S[j]);
		}
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
                if (S[Input1].top == -1)
                {
                    printf("EMPTY\n");
                }
                else
                {
                    pop(&S[Input1],&Temp);
                    printf("%d\n",Temp);
                }
            }
            else if (Choice==3)
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
