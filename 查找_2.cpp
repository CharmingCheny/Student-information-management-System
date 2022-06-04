#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
#define STUNUM 10
int I=0; //��¼¼���ѧ������ 
typedef struct
{
	int number; //�ؼ���
	char name[5];
	char sex[2];
	int age;
}record;
typedef struct BSTNode
{
	record stu[STUNUM];
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
void InsertBST(BSTree &T,record e)  //�ڿ������� 
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
void InsertBST1(BSTree &T)  //�����е������� 
{
	BSTree S;
	record e;
	printf("������ѧ��ѧ�š��������Ա�����:");
	scanf("%d%s%s%d",&e.number,&e.name,&e.sex,&e.age);
	if(!T)
	{
		S=new BSTNode;
		//�����ǽ�����Ԫ�ش������� 
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
	printf("����������<����ѧ��Ϊ0��Ϊ��ֹ����>:\n");
	printf("ѧ��:");
	scanf("%d",&e.number);
	
	while(e.number!=0)
	{
		I++;
		printf("�������Ա����䣺");
		scanf("%s%s%d",&e.name,&e.sex,&e.age);
		InsertBST(T,e);
		printf("ѧ��:");
		scanf("%d",&e.number);
	}
}
BSTree SearchBST(BSTree T,int num)  //�����㷨 
{
	if((!T)||num==T->stu[num].number) return T;
	else if(num<T->stu[num].number) return SearchBST(T->lchild,num);
	else return SearchBST(T->rchild,num);
}
void Welcome(BSTree &T)  //��ӭ���� 
{
	BSTree R;
	int num,num1;
	char c;
	while(1)
	{
		printf("��ѡ����Ҫʹ�õķ���:\n");  //ѡ����� 
		printf("1.��������������\n2.����ѧ����Ϣ\n3.����ѧ����Ϣ\n");
		while(1)
		{
			scanf("%d",&num);
			if(num>0&&num<4) break;
			else printf("������������ȷ�ķ������(1-3):");  //���Ϸ������ 
		}
		if (num==1) creat(T);  
		else if (num==2) { I++; InsertBST1(T);}
		else if (num==3) 
		{
			printf("��������ҵ�ѧ�����(1-%d)��",I);
			scanf("%d",&num1);
			while(1)
			{
				if(num1<1||num1>I) 
				{
					printf("������������ҵ�ѧ�����(1-%d)��",I);  //���Ϸ� 
					scanf("%d",&num1);
				}
				else break; 
			} 

			R=SearchBST(T,num1);
			printf("%d\t%s\t%s\t%d\n",R->stu[num1].number,R->stu[num1].name,R->stu[num1].sex,R->stu[num1].age);
		} 
		while(1)
		{
			printf("�Ƿ��˳�����(Y/N):");
			scanf("%s",&c);
			if(c!='Y'&&c!='y'&&c!='N'&&c!='n') printf("���������ĸ��Ч��������Y/N:");  //�Ϸ����ж� 
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
	printf("��лʹ�ñ�����");
	return 0;
}
