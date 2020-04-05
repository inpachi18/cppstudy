#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,N,Q,i,j,k,Choice,Input1,Input2;
    scanf("%d",&T);
    for (i=0;i<T;i++)
    {
        scanf("%d %d",&N,&Q);
        int S[N][300];
        int Top[N+1];
        for (j=0;j<=N;j++)
        {
            Top[j]=-1;
        }
        for (j=0;j<Q;j++)
        {
            scanf("%d",&Choice);
            if (Choice==1)
            {
                scanf ("%d %d",&Input1,&Input2);
                Top[Input1]++;
                S[Input1][Top[Input1]]=Input2;
            }
            else if (Choice==2)
            {
                scanf ("%d",&Input1);
                if (Top[Input1]==-1)
                {
                    printf("EMPTY\n");
                }
                else
                {
                    printf("%d\n",S[Input1][Top[Input1]]);
                    Top[Input1]--;
                }
            }
            else if (Choice==3)
            {
                scanf ("%d %d",&Input1,&Input2);
                for (k=0;k<=Top[Input2];k++)
                {
                    S[Input1][Top[Input1]+k+1]=S[Input2][k];
                }
                Top[Input1]=Top[Input1]+Top[Input2]+1;
                Top[Input2]=-1;
            }
        }
    }
    return 0;
};
