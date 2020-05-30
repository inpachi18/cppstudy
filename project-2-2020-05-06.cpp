#include<bits/stdc++.h>
const int maxn=1e5+10;
int a[maxn],b[maxn],h;
struct node{
	int data;
	node* l;
	node* r;
};
typedef node* tree;
tree create()//创建二叉树 
{
	tree p=(tree)malloc(sizeof(struct node));
	p->l=NULL;
	p->r=NULL;
	return p;
}
tree build(int mid[],int beh[],int n)//建树 
{
	if(n==0)return NULL;
	tree p;
	int i;
	p=create();
	p->data=beh[n-1];
	for(i=0;i<n;i++)
	{
		if(mid[i]==beh[n-1])//寻找根节点 
		break;
	}
	p->l=build(mid,beh,i);
	p->r=build(mid+i+1,beh+i,n-i-1);
	return p;
}
void H(tree p,int i)//树高 
{
	if(p)
	{
		if(h<i)h=i;
		H(p->l,i+1);
		H(p->r,i+1);
		
	}
}
void level(tree t) //层序遍历
{
	int z=0;
 if(!t)
 return ;
 int front=0,rear=1;
 tree tmp[maxn];
 tmp[front] =t;
 while(front<rear){
 t=tmp[front++];
            if(z==0)
            {
             printf("%d",t->data);
             z=1;
   }
  else
  {
  printf(" %d",t->data);}
  if(t->l)
  tmp[rear++]=t->l;
  if(t->r)
  tmp[rear++]=t->r;
 }}
int main(){
	 int n,p=1;
 	scanf("%d",&n);
 	for(int i=0;i<n;i++)
 	{
 		scanf("%d",&a[i]);
    if(i>0&&a[i]>a[i-1])p=0;
	}
    if(p==1)
	{
		for(int i=0;i<n;i++)
 		{
 			scanf("%d",&b[i]);	
		}
	tree t;
	t=create();
	t=build(a,b,n);
	h=0;
	H(t,1);
	level(t);
	printf("\n");
	printf("%d\n",h);
	}
	else printf("ERROR");
	
 	return 0;
 }
 	

