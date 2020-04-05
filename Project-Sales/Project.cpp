#include<bits/stdc++.h>

struct salesperson{
	char number[10];
	char name[80];
	char sex[10];
	char edu[40];
	double SUM;
};
struct commodity{
	char number[5];
	char name[40];
	int count;
	double prize;
};
struct Sell_Record{
	char NoS[5];
	char NoC[5];
	int Rec;
};
struct Charge_Record{
	char NoC[5];
	int Rec;
};

void mainmenu();
void salesperson();
void S_search();
void S_change();
void S_delete();
void S_add();
void S_rank();
void C_search();
void C_change();
void C_delete();
void C_add();
void C_rank();
void commodity();
void record();
void R_add();
void cls(){
	system("cls");
};

int main(){
	mainmenu();
	return 0;
}
void mainmenu(){
	int i;
	printf("#################################################\n");
	printf("#                                               #\n"); 
	printf("#             试做型存储销售管理系统            #\n");
	printf("#                                               #\n");
	printf("#       1、销售员相关菜单                       #\n");
	printf("#       2、商品库存相关菜单                     #\n");
	printf("#       3、销售记录相关菜单                     #\n");
	printf("#       0、退出系统                             #\n");
	printf("#                                               #\n");
	printf("#################################################\n");
	printf("请输入指令前的序号:");
	scanf ("%d",&i);
	switch (i){
		case 1:cls();salesperson(); break;
		case 2:cls();commodity(); break;
		case 3:cls();record(); break;
		case 0:exit(0); break;
		default:cls();printf("输入的好像不对呢...重新输入一遍看看吧。\n");mainmenu();
	}
}
void salesperson(){
	int i;
	printf("#################################################\n");
	printf("#                                               #\n"); 
	printf("#                   销售员菜单                  #\n");
	printf("#                                               #\n");
	printf("#       1、查询销售员信息                       #\n");
	printf("#       2、修改销售员信息                       #\n");
	printf("#       3、删除销售员信息                       #\n");
	printf("#       4、新增销售员信息                       #\n");
	printf("#       5、销售员排序并输出                     #\n");
	printf("#       0、返回上级菜单                         #\n");
	printf("#                                               #\n");
	printf("#################################################\n");
	printf("请输入指令前的序号:");
	scanf ("%d",&i);
	switch (i){
		case 1:cls();S_search(); break;
		case 2:cls();S_change(); break;
		case 3:cls();S_delete(); break;
		case 4:cls();S_add(); break;
		case 5:cls();S_rank();break; 
		case 0:cls();mainmenu(); break;
		default:cls();printf("输入的好像不对呢...重新输入一遍看看吧。\n");salesperson();
	}
}
void S_search(){
	FILE *fp;
	int Persons,i;
	char temp;
	if ((fp=fopen("Salespersons.txt","r"))==NULL){
		cls();
		printf("好像出错了...回到上级菜单。\n");
		salesperson(); 
	}
	fscanf (fp,"%d",&Persons);
	printf("总共有%d位员工，下面是他们的信息：\n",Persons);
	struct salesperson S[Persons];
	for (i=0;i<Persons;i++){
		fscanf(fp,"%s %s %s %s %lf",S[i].number,S[i].name,S[i].sex,S[i].edu,&S[i].SUM);
		printf("%s %s %s %s %.1lf\n",S[i].number,S[i].name,S[i].sex,S[i].edu,S[i].SUM);
	}
	fclose(fp);
	system("pause");
	cls();
	salesperson();
}
void S_change(){
	FILE *fp;
	int Persons,i,t=-1;
	char temp;
	if ((fp=fopen("Salespersons.txt","r"))==NULL){
		cls();
		printf("好像出错了...回到上级菜单。\n");
		salesperson(); 
	}
	fscanf (fp,"%d",&Persons);
	printf("总共有%d位员工，下面是他们的信息：\n",Persons);
	struct salesperson S[Persons];
	for (i=0;i<Persons;i++){
		fscanf(fp,"%s %s %s %s %lf",S[i].number,S[i].name,S[i].sex,S[i].edu,&S[i].SUM);
		printf("%s %s %s %s %.1lf\n",S[i].number,S[i].name,S[i].sex,S[i].edu,S[i].SUM);
	}
	fclose(fp);
	struct salesperson change;
	printf("请按 编号 姓名 性别 学历 总销售额 的格式输入需要修改的销售员信息：\n");
	scanf("%s %s %s %s %lf",change.number,change.name,change.sex,change.edu,&change.SUM);
	for (i=0;i<Persons;i++){
		if ((S[i].number[3]==change.number[3]) && (S[i].number[2]==change.number[2])){
			t=i;
		}
	}
	if (t==-1){
		printf("没有找到这个销售员呢...重新输入试试看？\n");
		S_change(); 
	}
	fp=fopen("Salespersons.txt","w");
	fprintf(fp,"%d",Persons);
	for(i=0;i<Persons;i++){
		if (t==i){
			fprintf(fp,"\n%s %s %s %s %.1lf",change.number,change.name,change.sex,change.edu,change.SUM);
		}else {
			fprintf(fp,"\n%s %s %s %s %.1lf",S[i].number,S[i].name,S[i].sex,S[i].edu,S[i].SUM);
		}
	}
	fclose(fp); 
	printf("修改完毕，返回上级菜单\n");
	system("pause");
	cls();
	salesperson(); 
}
void S_delete(){
	FILE *fp;
	int Persons,i,t=-1;
	char del[5];
	if ((fp=fopen("Salespersons.txt","r"))==NULL){
		cls();
		printf("好像出错了...回到上级菜单。\n");
		salesperson(); 
	}
	fscanf (fp,"%d",&Persons);
	printf("总共有%d位员工，下面是他们的信息：\n",Persons);
	struct salesperson S[Persons];
	for (i=0;i<Persons;i++){
		fscanf(fp,"%s %s %s %s %lf",S[i].number,S[i].name,S[i].sex,S[i].edu,&S[i].SUM);
		printf("%s %s %s %s %.1lf\n",S[i].number,S[i].name,S[i].sex,S[i].edu,S[i].SUM);
	}
	fclose(fp);
	printf("请输入要删除的销售员编号：\n");
	scanf("%s",del);
		for (i=0;i<Persons;i++){
		if ((S[i].number[2]==del[2]) && (S[i].number[3]==del[3])){
			t=i;
			break;
		}
	}
	if (t==-1){
		printf("没有找到这个销售员呢...重新输入试试看？\n");
		S_delete(); 
	}
	fp=fopen("Salespersons.txt","w");
	fprintf(fp,"%d",Persons-1);
	for(i=0;i<Persons;i++){
		if (t==i) {
			continue;
		}
		fprintf(fp,"\n%s %s %s %s %.1lf",S[i].number,S[i].name,S[i].sex,S[i].edu,S[i].SUM);
	}
	fclose(fp); 
	printf("删除完毕，返回上级菜单\n");
	system("pause");
	cls();
	salesperson();
}
void S_add(){
	FILE *fp;
	int Salesperson,i;
	if ((fp=fopen("Salespersons.txt","r"))==NULL){
		cls();
		printf("好像出错了...回到上级菜单。\n");
		salesperson(); 
	}
	fscanf (fp,"%d",&Salesperson);
	struct salesperson S[Salesperson];
	for (i=0;i<Salesperson;i++){
		fscanf(fp,"%s %s %s %s %lf",S[i].number,S[i].name,S[i].sex,S[i].edu,&S[i].SUM);	}
	fclose(fp);
	struct salesperson add;
	printf("请按 编号 姓名 性别 学历 总销售额 的格式输入销售员信息：\n");
	scanf("%s %s %d %lf",add.number,add.name,add.sex,add.edu,add.SUM);
	for (i=0;i<Salesperson;i++){
		if ((S[i].number[2]==add.number[2]) && (S[i].number[3]==add.number[3])){
			cls();
			printf("错误！和编号为%s的销售员编号相同！请重新输入\n",S[i].number);
			S_add(); 
		} 
		else if (add.number[0] != 'E'){
			printf("编号格式错误！请重新输入\n");
			C_add(); 
		}
	}
	fp=fopen("Salespersons.txt","a+");
	fprintf(fp,"\n%s %s %s %s %.1lf",add.number,add.name,add.sex,add.edu,add.SUM);
	fclose(fp);
	fp=fopen("Salespersons.txt","r+");
	Salesperson++;
	fprintf(fp,"%d\n",Salesperson);
	fclose(fp);
	printf("写入完毕,返回上级菜单");
	system("pause");
	cls();
	salesperson(); 
}
void S_rank(){
	FILE *fp;
	int Persons,i,j;
	if ((fp=fopen("Salespersons.txt","r+"))==NULL){
		cls();
		printf("好像出错了...回到上级菜单。\n");
		salesperson(); 
	}
	fscanf (fp,"%d",&Persons);
	printf("总共有%d位员工，下面是他们的信息：\n",Persons);
	struct salesperson S[Persons],temp;
	for (i=0;i<Persons;i++){
		fscanf(fp,"%s %s %s %s %lf",S[i].number,S[i].name,S[i].sex,S[i].edu,&S[i].SUM);
		printf("%s %s %s %s %.1lf\n",S[i].number,S[i].name,S[i].sex,S[i].edu,S[i].SUM);
	}
	fclose(fp);
	printf("下面是按总销售额排序的结果\n");
	for (i=0;i<Persons-1;i++){
	for (j=i+1;j<Persons;j++){
		if (S[i].SUM<S[j].SUM){
			temp=S[i];S[i]=S[j];S[j]=temp;
		}
	}
	}
	for (i=0;i<Persons;i++){
		printf("%s %s %s %s %.1lf\n",S[i].number,S[i].name,S[i].sex,S[i].edu,S[i].SUM);
	}
	printf("排序完毕\n");
	system("pause");
	cls();
	salesperson();
} 
void commodity(){
	int i;
	printf("#################################################\n");
	printf("#                                               #\n"); 
	printf("#                   商品菜单                    #\n");
	printf("#                                               #\n");
	printf("#       1、查询商品信息                         #\n");
	printf("#       2、修改商品信息                         #\n");
	printf("#       3、删除商品信息                         #\n");
	printf("#       4、新增商品信息                         #\n");
	printf("#       5、商品排序并输出                       #\n");
	printf("#       0、返回上级菜单                         #\n");
	printf("#                                               #\n");
	printf("#################################################\n");
	printf("请输入指令前的序号:");
	scanf ("%d",&i);
	switch (i){
		case 1:cls();C_search(); break;
		case 2:cls();C_change(); break;
		case 3:cls();C_delete(); break;
		case 4:cls();C_add(); break;
		case 5:cls();C_rank();break;
		case 0:cls();mainmenu(); break;
		default:cls();printf("输入的好像不对呢...重新输入一遍看看吧。\n");commodity();
	}
}
void C_search(){
	FILE *fp;
	int Commodity,i;
	if ((fp=fopen("Commodity.txt","r"))==NULL){
		cls();
		printf("好像出错了...回到上级菜单。\n");
		commodity(); 
	}
	fscanf (fp,"%d",&Commodity);
	printf("总共有%d件商品，下面是它们的信息：\n",Commodity);
	struct commodity S[Commodity];
	for (i=0;i<Commodity;i++){
		fscanf(fp,"%s %s %d %lf",S[i].number,S[i].name,&S[i].count,&S[i].prize);
		printf("%s %s %d %.1lf\n",S[i].number,S[i].name,S[i].count,S[i].prize);
	}
	fclose(fp);
	system("pause");
	cls(); 
	commodity();
}
void C_change(){
	FILE *fp;
	int Commodity,i,t=-1;
	if ((fp=fopen("Commodity.txt","r"))==NULL){
		cls();
		printf("好像出错了...回到上级菜单。\n");
		commodity(); 
	}
	fscanf (fp,"%d",&Commodity);
	printf("总共有%d件商品，下面是它们的信息：\n",Commodity);
	struct commodity S[Commodity];
	for (i=0;i<Commodity;i++){
		fscanf(fp,"%s %s %d %lf",S[i].number,S[i].name,&S[i].count,&S[i].prize);
		printf("%s %s %d %.1lf\n",S[i].number,S[i].name,S[i].count,S[i].prize);
	}
	fclose(fp);
	struct commodity change;
	printf("请按 编号 名称 存量 价格 的格式输入要修改的商品信息：\n");
	scanf("%s %s %d %lf",change.number,change.name,&change.count,&change.prize);
		for (i=0;i<Commodity;i++){
		if ((S[i].number[2]==change.number[2]) && (S[i].number[3]==change.number[3])){
			t=i;
		}
	}
	if (t==-1){
		printf("没有找到这个商品呢...重新输入试试看？\n");
		C_change(); 
	}
	fp=fopen("Commodity.txt","w");
	fprintf(fp,"%d",Commodity);
	for(i=0;i<Commodity;i++){
		if (t==i){
			fprintf(fp,"\n%s %s %d %lf",change.number,change.name,change.count,change.prize);
		}
		else {
			fprintf(fp,"\n%s %s %d %.1lf",S[i].number,S[i].name,S[i].count,S[i].prize);
		}
		
	}
	fclose(fp); 
	printf("修改完毕，返回上级菜单\n");
	system("pause");
	cls();
	commodity(); 
}
void C_delete(){
		FILE *fp;
	int Commodity,i,t=-1;
	char del[5];
	if ((fp=fopen("Commodity.txt","r"))==NULL){
		cls();
		printf("好像出错了...回到上级菜单。\n");
		commodity(); 
	}
	fscanf (fp,"%d",&Commodity);
	printf("总共有%d件商品，下面是它们的信息：\n",Commodity);
	struct commodity S[Commodity];
	for (i=0;i<Commodity;i++){
		fscanf(fp,"%s %s %d %lf",S[i].number,S[i].name,&S[i].count,&S[i].prize);
		printf("%s %s %d %.1lf\n",S[i].number,S[i].name,S[i].count,S[i].prize);
	}
	fclose(fp);
	printf("请输入要删除的商品编号：\n");
	scanf("%s",del);
		for (i=0;i<Commodity;i++){
		if ((S[i].number[2]==del[2]) && (S[i].number[3]==del[3])){
			t=i;
			break;
		}
	}
	if (t==-1){
		printf("没有找到这个商品呢...重新输入试试看？\n");
		C_delete(); 
	}
	fp=fopen("Commodity.txt","w");
	fprintf(fp,"%d",Commodity-1);
	for(i=0;i<Commodity;i++){
		if (t==i) {
			continue;
		}
		fprintf(fp,"\n%s %s %d %.1lf",S[i].number,S[i].name,S[i].count,S[i].prize);
	}
	fclose(fp); 
	printf("删除完毕，返回上级菜单\n");
	system("pause");
	cls();
	commodity();
}
void C_add(){
	FILE *fp;
	int Commodity,i;
	if ((fp=fopen("Commodity.txt","r"))==NULL){
		cls();
		printf("好像出错了...回到上级菜单。\n");
		commodity(); 
	}
	fscanf (fp,"%d",&Commodity);
	struct commodity S[Commodity];
	for (i=0;i<Commodity;i++){
		fscanf(fp,"%s %s %d %lf",S[i].number,S[i].name,&S[i].count,&S[i].prize);
	}
	fclose(fp);
	struct commodity add;
	printf("请按 编号 名称 存量 价格 的格式输入商品信息：\n");
	scanf("%s %s %d %lf",add.number,add.name,&add.count,&add.prize);
	for (i=0;i<Commodity;i++){
		if ((S[i].number[2]==add.number[2]) && (S[i].number[3]==add.number[3])){
			cls();
			printf("错误！和编号为%s的商品编号相同！请重新输入\n",S[i].number);
			C_add(); 
		} 
		else if (add.number[0] != 'P'){
			printf("编号格式错误！请重新输入\n");
			C_add(); 
		}
	}
	fp=fopen("Commodity.txt","a+");
	fprintf(fp,"\n%s %s %d %lf",add.number,add.name,add.count,add.prize);
	fclose(fp);
	fp=fopen("Commodity.txt","r+");
	Commodity++;
	fprintf(fp,"%d\n",Commodity);
	fclose(fp);
	printf("写入完毕");
	system("pause");
	cls();
	commodity(); 
}
void C_rank(){
	FILE *fp;
	int Commodity,i,j;
	if ((fp=fopen("Commodity.txt","r"))==NULL){
		cls();
		printf("好像出错了...回到上级菜单。\n");
		commodity(); 
	}
	fscanf (fp,"%d",&Commodity);
	printf("总共有%d件商品，下面是它们的信息：\n",Commodity);
	struct commodity S[Commodity],temp;
	for (i=0;i<Commodity;i++){
		fscanf(fp,"%s %s %d %lf",S[i].number,S[i].name,&S[i].count,&S[i].prize);
		printf("%s %s %d %.1lf\n",S[i].number,S[i].name,S[i].count,S[i].prize);
	}
	fclose(fp);
	printf("下面是按总销售额排序的结果\n");
	for (i=0;i<Commodity-1;i++){
	for (j=i+1;j<Commodity;j++){
		if ((S[i].count*S[i].prize)<(S[j].count*S[j].prize)){
			temp=S[i];S[i]=S[j];S[j]=temp;
		}
	}
	}
	for (i=0;i<Commodity;i++){
		printf("%s %s %d %.1lf\n",S[i].number,S[i].name,S[i].count,S[i].prize);
	}
	printf("排序完毕\n");
	system("pause");
	cls(); 
	commodity(); 
}
void record(){
	int i;
	printf("#################################################\n");
	printf("#                                               #\n"); 
	printf("#                   销售记录菜单                #\n");
	printf("#                                               #\n");
	printf("#       1、新增销售记录                         #\n");
	printf("#       0、返回上级菜单                         #\n");
	printf("#                                               #\n");
	printf("#################################################\n");
	printf("请输入指令前的序号:");
	scanf ("%d",&i);
	switch (i){
		case 1:cls();R_add(); break;
		case 0:cls();mainmenu(); break;
		default:cls();printf("输入的好像不对呢...重新输入一遍看看吧。\n");record();
	}
}
void R_add(){
	int i,j,t1,t2,N;
	char NoC[5],NoS[5];
	printf("#################################################\n");
	printf("#                                               #\n"); 
	printf("#                   新增销售记录                #\n");
	printf("#                                               #\n");
	printf("#       请按 销售员编号 商品编号 销售数量       #\n");
	printf("#       的格式输入销售记录                      #\n");
	printf("#                                               #\n");
	printf("#################################################\n");
	printf("请输入:\n");
	scanf("%s %s %d",NoS,NoC,&N);
	
	FILE *fp;
	int Commodity,tc=-1;
	double temp;
	if ((fp=fopen("Commodity.txt","r"))==NULL){
		cls();
		printf("好像出错了...回到上级菜单。\n");
		record(); 
	}
	fscanf (fp,"%d",&Commodity);
	struct commodity C[Commodity];
	for (i=0;i<Commodity;i++){
		fscanf(fp,"%s %s %d %lf",C[i].number,C[i].name,&C[i].count,&C[i].prize);
	}
	fclose(fp);
	for (i=0;i<Commodity;i++){
		if ((C[i].number[2]==NoC[2]) && (C[i].number[3]==NoC[3])){
			tc=i;
			if (N>C[i].count){
				printf("销售量大于库存了！请重新输入。\n");
				R_add(); 
			}else {
				C[i].count=C[i].count-N;
				temp=N*C[i].prize;
			}
			break;
		}
	}
	if (tc==-1){
		printf("没有找到这个商品呢...重新输入试试看？\n");
		R_add(); 
	}
	fp=fopen("Commodity.txt","w");
	fprintf(fp,"%d",Commodity);
	for(i=0;i<Commodity;i++){
		fprintf(fp,"\n%s %s %d %.1lf",C[i].number,C[i].name,C[i].count,C[i].prize);
	}
	fclose(fp);

	
	int Persons,ts=-1;
	if ((fp=fopen("Salespersons.txt","r"))==NULL){
		cls();
		printf("好像出错了...回到上级菜单。\n");
		record(); 
	}
	fscanf (fp,"%d",&Persons);
	struct salesperson S[Persons];
	for (i=0;i<Persons;i++){
		fscanf(fp,"%s %s %s %s %lf",S[i].number,S[i].name,S[i].sex,S[i].edu,&S[i].SUM);
	}
	fclose(fp);
	for (i=0;i<Persons;i++){
		if ((S[i].number[2]==NoS[2]) && (S[i].number[3]==NoS[3])){
			S[i].SUM=S[i].SUM+temp;
			ts=i;
		}
	}
	if (ts==-1){
		printf("没有找到这个销售员呢...重新输入试试看？\n");
		R_add(); 
	}
	fp=fopen("Salespersons.txt","w");
	fprintf(fp,"%d",Persons-1);
	for(i=0;i<Persons;i++){
		fprintf(fp,"\n%s %s %s %s %.1lf",S[i].number,S[i].name,S[i].sex,S[i].edu,S[i].SUM);

	}
	fclose(fp);
	
	fp=fopen("Records.txt","a+");
	fprintf(fp,"\n%s %s %d",NoS,NoC,N);
	fclose(fp);
	
	printf("写入完毕,返回上级菜单\n");
	system("pause");
	cls();
	record(); 
}
