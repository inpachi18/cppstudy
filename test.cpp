#include <stdio.h>

int main()
{
    long long T,N,Q,i,j,k,Choice,Input1,Input2;
    scanf("%lld",&T);
    for (i=0;i<T;i++)
    {
        scanf("%lld %lld",&N,&Q);
        long long S[N][9999999999999];
        long long Top[N+1];
        for (j=0;j<=N;j++)
        {
            Top[j]=-1;
        }
        for (j=0;j<Q;j++)
        {
            scanf("%lld",&Choice);
            if (Choice==1)
            {
                scanf ("%lld %lld",&Input1,&Input2);
                Top[Input1]++;
                S[Input1][Top[Input1]]=Input2;
            }
            else if (Choice==2)
            {
                scanf ("%lld",&Input1);
                if (Top[Input1]==-1)
                {
                    printf("EMPTY\n");
                }
                else
                {
                    printf("%lld\n",S[Input1][Top[Input1]]);
                    Top[Input1]--;
                }
            }
            else if (Choice==3)
            {
                scanf ("%lld %lld",&Input1,&Input2);
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
