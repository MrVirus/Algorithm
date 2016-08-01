#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define M 10
#define N 10
typedef struct
{
	int x,y;
	char dir;
}Element;//�����Թ�Ԫ�����ͣ�����x,y���꣬�Լ�����dir
typedef struct STACK
{
	Element out;
	struct STACK *next;
}STACK,*LSTACK;//������ջ
typedef struct
{
	int x;
	int y;
}ZB;//������������,����x,y����
void InitStack(LSTACK &S)//�����ջ
{   
	S=NULL;
}
int Empty(LSTACK S)//�жϿ�ջ
{
	if(S==NULL) 
		return 1;
	else
		return 0;
}
int Push(LSTACK &S , Element e)//��ջ����
{
	LSTACK top;
	top=(LSTACK)malloc(sizeof(STACK));
	top->out=e;
	top->next=S;
	S=top;
	return 1;
} 
int Pop(LSTACK &S,Element &e)  //ջ��Ԫ�س�ջ
{
	LSTACK top;
	e=S->out;
	top=S;
	S=S->next;
	free(top);
	return 1;

}
void CreatMG(int MG[M][N])//�����Թ�
{
	int i,j;
	int m,n;
	printf("�������Թ�������: ");
	scanf("%d",&m);
	printf("�������Թ�������: ");
	scanf("%d",&n);
	printf("����������Թ�(1Ϊǽ��0Ϊ·���ÿո����):\n");
	for( i = 1; i <= m; i++ )              //������forѭ��������ʼ���Թ�
		for( j = 1 ; j <= n ; j++ )
			scanf("%d",&MG[i][j]);
	printf("��������Թ�Ϊ:\n");
	for( i = 0;i <= m + 1; i++ )          //������forѭ����������ǽ 
	{
		MG [i][0] = 1 ;
		MG [i][n + 1] = 1;
	}
	for( j = 0 ; j <= n + 1 ; j++ )
	{
		MG[0][j] = 1;
		MG[m + 1][j] = 1;
	}
	for( i = 0 ; i <= m + 1 ; i++ ) //������forѭ����������Թ�
	{
		for(j=0;j<=n+1;j++)
			printf("%d ",MG[i][j]); 
		printf("\n");
	}
}
int OutMG(ZB start, ZB end,int MG[M][N],int Move[4][2])        //���Թ�����
{
	int h,k,x_next,y_next,dir;           
	Element e1,e2;
	LSTACK S1,S2;                  //��������ջ�������á�S1��·����S2��������
	InitStack(S1);
	InitStack(S2);           
	e1.x=start.x; 
	e1.y=start.y;            
	h=e1.x;                 
	k=e1.y;
	e1.dir=-1;                   //�����λ�õķ���Ϊ-1,�Ա��ڷ���̽������
	Push(S1,e1);                 //���г�·�����ӦΪ·��֮һ
	while(!Empty(S1))
	{
		Pop(S1,e1);
		dir=e1.dir+1;
		while(dir<4)
		{
			x_next=h+Move[dir][0];
			y_next=k+Move[dir][1];
			if(MG[x_next][y_next]==2)
			{

				e1.x=h;
				e1.y=k;
				e1.dir=dir;
				MG[h][k]=3;
				h=x_next;
				k=y_next;
				dir=-1;
				Pop(S1,e1);
			}
			if(x_next==end.x&&y_next==end.y&&MG[x_next][y_next]==0)   
			{
				e1.x=h;
				e1.y=k;
				e1.dir=dir;
				Push(S1,e1);
				e1.x=x_next;
				e1.y=y_next;
				e1.dir=66;
				Push(S1,e1);
				while(!Empty(S1))
				{
					Pop(S1,e2);
					Push(S2,e2);
				}
				printf("dir��0Ϊ�ң�1Ϊ�£�2Ϊ��3Ϊ��.\n");
				printf("�Թ���·Ϊ:\n");
				while(!Empty(S2))
				{
					Pop(S2,e2);
					printf("(%d,%d,%d)",e2.x,e2.y,e2.dir);
				}
				return 0;
			}
			if(MG[x_next][y_next]==0)
			{
				MG[x_next][y_next]=2;
				e1.x=h;
				e1.y=k;
				e1.dir=dir;
				Push(S1,e1);
				h=x_next;
				k=y_next;
				dir=-1;
			}
			dir++;
		}
	}
	printf("û�г�·����\n");
	return 0;
}
void main()
{
	ZB start,end;
	int Move[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int MG[M][N];
	CreatMG(MG);
	printf("�������Թ��������<���Ÿ���>:\n");
	scanf("%d,%d",&start.x,&start.y);
	printf("�������Թ���������<���Ÿ���>:\n");
	scanf("%d,%d",&end.x,&end.y);
	OutMG(start,end,MG,Move);
}