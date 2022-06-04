#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
#define STUNUM 10
int I=0; //记录录入的学生人数 
typedef struct
{
	int number; //关键字
	char name[5];
	char sex[2];
	int age;
}record;
typedef struct BSTNode
{
	record stu[STUNUM];
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
void InsertBST(BSTree &T,record e)  //在空树插入 
{
	BSTree S;
	if(!T)
	{
		S=new BSTNode;
		S->stu[I].age=e.age;
		for(int i=0;i<5;i++)
			S->stu[I].name[i]=e.name[i];
		S->stu[I].number=e.number;
		for(int j=0;j<2;j++)
			S->stu[I].sex[j]=e.sex[j];
		S->lchild=S->rchild=NULL;
		T=S;
	}
	else if(e.number<T->stu[I].number)
		InsertBST(T->lchild,e);
	else if(e.number>T->stu[I].number)
		InsertBST(T->rchild,e);

}
void InsertBST1(BSTree &T)  //在已有的树插入 
{
	BSTree S;
	record e;
	printf("请输入学生学号、姓名、性别、年龄:");
	scanf("%d%s%s%d",&e.number,&e.name,&e.sex,&e.age);
	if(!T)
	{
		S=new BSTNode;
		//以下是将输入元素存入树中 
		for(int i=0;i<5;i++)
			S->stu[I].name[i]=e.name[i];
		S->stu[I].number=e.number;
		for(int j=0;j<2;j++)
			S->stu[I].sex[j]=e.sex[j];
		S->lchild=S->rchild=NULL;
		S->lchild=S->rchild=NULL;
		T=S;
	}
	else if(e.number<T->stu[I].number)
		InsertBST(T->lchild,e);
	else if(e.number>T->stu[I].number)
		InsertBST(T->rchild,e);
}
void creat(BSTree &T)
{
	record e;
	T=NULL;
	printf("请依次输入<输入学号为0视为终止输入>:\n");
	printf("学号:");
	scanf("%d",&e.number);
	
	while(e.number!=0)
	{
		I++;
		printf("姓名、性别、年龄：");
		scanf("%s%s%d",&e.name,&e.sex,&e.age);
		InsertBST(T,e);
		printf("学号:");
		scanf("%d",&e.number);
	}
}
BSTree SearchBST(BSTree T,int num)  //查找算法 
{
	if((!T)||num==T->stu[num].number) return T;
	else if(num<T->stu[num].number) return SearchBST(T->lchild,num);
	else return SearchBST(T->rchild,num);
}
void Welcome(BSTree &T)  //欢迎程序 
{
	BSTree R;
	int num,num1;
	char c;
	while(1)
	{
		printf("请选择你要使用的服务:\n");  //选择服务 
		printf("1.建立二叉排序树\n2.插入学生信息\n3.查找学生信息\n");
		while(1)
		{
			scanf("%d",&num);
			if(num>0&&num<4) break;
			else printf("请重新输入正确的服务序号(1-3):");  //不合法的序号 
		}
		if (num==1) creat(T);  
		else if (num==2) { I++; InsertBST1(T);}
		else if (num==3) 
		{
			printf("请输入查找的学生序号(1-%d)：",I);
			scanf("%d",&num1);
			while(1)
			{
				if(num1<1||num1>I) 
				{
					printf("请重新输入查找的学生序号(1-%d)：",I);  //不合法 
					scanf("%d",&num1);
				}
				else break; 
			} 

			R=SearchBST(T,num1);
			printf("%d\t%s\t%s\t%d\n",R->stu[num1].number,R->stu[num1].name,R->stu[num1].sex,R->stu[num1].age);
		} 
		while(1)
		{
			printf("是否退出程序(Y/N):");
			scanf("%s",&c);
			if(c!='Y'&&c!='y'&&c!='N'&&c!='n') printf("你输入的字母无效，请输入Y/N:");  //合法性判断 
			else break;			
		}
		if(c=='Y'||c=='y') break;
		else if(c=='N'||c=='n') ;
	}

 } 
int main()
{
	BSTree T;
	Welcome(T);
	printf("感谢使用本程序！");
	return 0;
}
