#include<stdio.h>
#include <stdlib.h>
typedef struct BITNODE
{
	char data;
	struct BITNODE *lchild,*rchild;
}BITNODE,*BITREE;
void PreOrderTraverse(BITREE T)
{
	if (T == NULL)
	{
		return;
	}
	printf("%c",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}
void InOrderTraverse(BITREE T)
{
	if (T == NULL)
	{
		return ;
	}
	InOrderTraverse(T->lchild);
	printf("%c",T->data);
	InOrderTraverse(T->rchild);
}
void PostOrderTraverse(BITREE T)
{
	if (T == NULL)
	{
		return ;
	}
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c",T->data);
}
int CreatBITREE(BITREE *T)
{
	char ch;
	scanf("%c",&ch);
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BITREE)malloc(sizeof(BITNODE));
		if (!*T)
		{
			return 0;
		}
	(*T)->data = ch;
	CreatBITREE(&(*T)->lchild);
	CreatBITREE(&(*T)->rchild);
	}
	return 0;
}
void displaytree(BITREE T,int n)
{
	int i;
	if(T == NULL)
	{
		return ;
	}
	displaytree(T->rchild,n + 2);
	for (i = 0; i < n; i++)
	{
		printf("    ");
	}
	if (n >= 0)
	{
		printf("------");
		printf("%c \n",T->data);
	}
	displaytree(T->lchild,n+2);
}
int Leaf(BITREE T)
{
	int static count = 0;
	if (T != NULL)
	{
		if (T->lchild == NULL && T->rchild == NULL)
		{
		count++;
		}
		Leaf(T->lchild);
		Leaf(T->rchild);
	}
	return count;
}
int Deep(BITREE T)
{
	int h=0,hl=0,hr=0;
	if ( T == NULL)
	{
		h = 0;
	}
	else
	{
		hl = Deep(T->lchild);
		hr = Deep(T->rchild);
		h = 1 + (hl > hr ? hl : hr);
	}
	return h;
}
int main(void)
{
	BITREE T;
	int deepth,Leavescount;
	printf("��������Ķ�����('#'��Ϊ������յ�,�������):\n");
	CreatBITREE(&T);
	printf("�㴴������Ϊ:\n");
	displaytree(T,2);
	printf("����������Ϊ:");
	PreOrderTraverse(T);
	printf("\n");
	printf("����������Ϊ:");
	InOrderTraverse(T);
	printf("\n");
	printf("����������Ϊ:");
	PostOrderTraverse(T);
	printf("\n");
	Leavescount=Leaf(T);
	printf("Ҷ�ڵ�����Ϊ:%d\n",Leavescount);
	deepth=Deep(T);
	printf("�����������Ϊ:%d\n",deepth);
}
