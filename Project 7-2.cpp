#include <stdio.h>


int set[1000005];

int find(int x){

   return x==set[x]?x:(set[x]=find(set[x]));
}

int main ()
{

int N,M,i,j,Input1,Input2,OddDegrees=0;
scanf ("%d %d",&N,&M);
int MAP[N+1][N+1];
for (i=0;i<=N;i++)
{
    for (j=0;j<=N;j++)
    {
        MAP[i][j]=0;
    }
}

for (i=1;i<1000005;i++)
{
    set[i]=i;
}

for (i=1;i<=M;i++)
{
    scanf ("%d %d",&Input1,&Input2);
    MAP[Input1][Input2]++;
    MAP[Input2][Input1]++;
    int fx=find(Input1),fy=find(Input2);
    set[fx]=fy;
}

int cnt=0;
for(i=1;i<=N;++i)
{
    if (set[i]==i)
    {
        cnt++;
    }
}

if (cnt!=1)
{
    printf("N");
    return 0;
}

for (i=0;i<=N;i++)
{
    for (j=0;j<=N;j++)
    {
        MAP[i][0]=MAP[i][0]+MAP[i][j];
    }
}

for (i=1;i<=N;i++)
{
    if (MAP[i][0]%2==1)
    {
        OddDegrees++;
    }
}

if (OddDegrees==0 || OddDegrees==2)
{
    printf("Y");
}
else
{
    printf("N");
}

return 0;
}