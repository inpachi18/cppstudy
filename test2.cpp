#include<stdio.h>

#include<string.h>
#include<stdlib.h>
struct score
{
  char num[10];
  char name[10];
  double score[3];
};
int main()
{
  struct score s[1000];
  int i,n;
  double average = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  scanf("%s %s %lf",&s[i].num,&s[i].name,&s[i].score[3]);
  }
  for(i=0;i<n;i++)
  {
    average = average + s[i].score;
  }
  average = average / n;
  printf("%.2f\n",average);
  for(i = 0; i < n; i++)
  {
    if(s[i].score < average)
    {
      printf("%s %s\n",s[i].name,s[i].num);
      
    }
  }
  return 0;
}
