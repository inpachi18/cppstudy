#include <stdio.h>

struct Stack{
	int Data[300];
	int Top;
}; 

int main()
{
    long long T,N,Q,i,j,k,Choice,Input1,Input2;
    scanf("%d",&T);
    for (i=0;i<T;i++)
    {
        scanf("%d %d",&N,&Q);
        struct Stack S[N+1];
        for (j=0;j<=N;j++)
        {
            S[j].Top=-1;
        }
        for (j=0;j<Q;j++)
        {
            scanf("%d",&Choice);
            if (Choice==1)
            {
                scanf ("%d %d",&Input1,&Input2);
                S[Input1].Top++;
                S[Input1].Data[S[Input1].Top]=Input2;
            }
            else if (Choice==2)
            {
                scanf ("%d",&Input1);
                if (S[Input1].Top==-1)
                {
                    printf("EMPTY\n");
                }
                else
                {
                    printf("%d\n",S[Input1].Data[S[Input1].Top]);
                    S[Input1].Top--;
                }
            }
            else if (Choice==3)
            {
                scanf ("%d %d",&Input1,&Input2);
                for (k=0;k<=S[Input2].Top;k++)
                {
                    S[Input1].Data[S[Input1].Top+k+1]=S[Input2].Data[k];
                }
                S[Input1].Top=S[Input1].Top+S[Input2].Top+1;
                S[Input2].Top=-1;
            }
        }
    }
    return 0;
};
