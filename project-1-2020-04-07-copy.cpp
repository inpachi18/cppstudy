#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int data;
    struct stack* Next;
}*Stack;
Stack create()
{
    Stack P;
    P=(Stack)malloc(sizeof(struct stack));
    P->Next=NULL;
    return P;
};
void Push(Stack P,int X)
{
    Stack t;
    t=(Stack)malloc(sizeof(struct stack));
    t->Next=P->Next;
    P->Next=t;
    t->data=X;
};
void POP(Stack P)
{
    if(P->Next==NULL)
    {
        printf("EMPTY\n");
    }
    else
    {
        printf("%d\n",P->Next->data);
        P->Next=P->Next->Next;
    }
};
int main()
{
    int T,N,Q,OP,Input1,Input2,i,j; 
    scanf("%d",&T);
    while(T)
    {
        scanf("%d %d",&N,&Q);
        Stack S[N+1];
        for(i=1;i<=N;i++)
        {
        	S[i]=create();
		}
        for(j=1;j<=Q;j++)
        {
            scanf("%d",&OP);
            if(OP==1)
            {
                scanf("%d %d",&Input1,&Input2);
                Push(S[Input1],Input2);
            }
            else if(OP==2)
            {
                scanf("%d",&Input1);
                POP(S[Input1]);
            }
            else if(OP==3)
            {
                scanf("%d %d",&Input1,&Input2);
                Stack Temp;
                Temp=S[Input2];
                while(Temp->Next!=NULL)
                {
                	Temp=Temp->Next;
				}
                Temp->Next=S[Input1]->Next;
                S[Input1]->Next=S[Input2]->Next;
                S[Input2]->Next=NULL;
            }
        }
        for(i=1;i<=N;i++)
        {
        	free(S[i]);
		}
        T--;
    } 
    return 0; 
}

