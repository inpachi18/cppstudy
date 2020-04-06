#include<stdio.h>
#include<stdlib.h>
struct SNode{
    int Data;
    struct SNode *Next;
};
typedef struct SNode *Stack;
Stack CreateStack(){//创建 
	Stack S;
	S=(Stack)malloc(sizeof(struct SNode));
	S->Next=NULL;
	return S;
}
void Push(Stack S,int x){//压入 
	Stack M;
	M=(Stack)malloc(sizeof(struct SNode));
	M->Data=x;
	M->Next=S->Next;
	S->Next=M;
}
int Pop(Stack S){//弹出 
	Stack N;
	int Top;
	if(S->Next==NULL){
		return 0;
	}
	else{ 
		N=S->Next;
		Top=N->Data;
		S->Next=N->Next;
		free(N);
		return Top;
	}	
}

int main()
{
    int T,N,Q,i,j,k,Choice,Input1,Input2,Temp;
    scanf("%d",&T);
    for (i=0;i<T;i++)
    {
        scanf("%d %d",&N,&Q);
        Stack S[N+1];
        for (j=0;j<=N;j++)
        {
        	S[N]=CreateStack();
		}
        for (j=0;j<Q;j++)
        {
            scanf("%d",&Choice);
            if (Choice==1)
            {
                scanf ("%d %d",&Input1,&Input2);
                Push(S[Input1],Input2);
            }
            else if (Choice==2)
            {
                scanf ("%d",&Input1);
                Temp=Pop(S[Input1]);
                if (!Temp)
                {
                    printf("EMPTY\n");
                }
                else
                {
                    printf("%d\n",Temp);
                }
            }
            else if (Choice==3)
            {
                scanf ("%d %d",&Input1,&Input2);
                Temp=Pop(S[Input2]);
                while (!Temp)
                {
                    Push(S[0],Temp);
                    Temp=Pop(S[Input2]);
                }
                Temp=Pop(S[0]);
                while (!Temp)
                {
                    Push(S[Input1],Temp);
                    Temp=Pop(S[0]);
                }
            }
        }
        for(i=0;i<=N;i++){
			free(S[i]);
		}
    }
    return 0;
};
