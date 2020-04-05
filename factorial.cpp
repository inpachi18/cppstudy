#include<stdio.h>

double fact( int n );

 int main(void)
{    
    int i, n;
    double result; 

    scanf("%d", &n);
    for(i = 0; i <= n; i++)
	{
        result = fact(i); 
	printf("%d! = %.0f\n", i, result);
     }

    return 0;
}
double fact(int n)
{
	int i;
	double F=1;
	
	for(i=1;i<=n;i++)
	F=F*i;
	
	return F;
}
