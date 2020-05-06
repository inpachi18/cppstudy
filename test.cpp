#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int main ()
{
    int N,i;
    scanf ("%d",&N);
    int LDR[N+1],LRD[N+1],Left[N+1],Right[N+1],LVL[N+1];
    int root;
    for (i=1;i<=N;i++)
    {
        scanf("%d",&LDR[i]);
    }
    for (i=1;i<=N;i++)
    {
        scanf("%d",&LRD[i]);
    }
    LVL[1]==LRD[N];
    for (i=1;i<=N;i++)
    {
        if (LDR[i]==LRD[N])
        {
            root=i;
            break;
        }
    }
    
}