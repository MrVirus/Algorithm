#include <stdio.h>
#define MAXVEX 30                        //��󶥵���30
#define MAX 666                          //�������Ϊ666�����ڲ���
typedef struct  
{
	char vexs [MAXVEX];                   //���㼯��
	int arc[MAXVEX][MAXVEX];              //�ڽӾ���
	int Vex_num,Edge_num;                 //�������ͱ���
}MGraph;                                //ͼ�ṹ
void CreatMGraph(MGraph *G)             //ͼ�Ĵ�������
{
	int i,j,k,w;
	printf("���붥�����ͱ���(�ö��Ÿ���~):\n");
	scanf("%d,%d",&G->Vex_num,&G->Edge_num);
	for (i = 0; i < G->Vex_num ; i++)
		for(j = 0; j < G->Edge_num; j++)
			G->arc[i][j] = MAX;
	for (k = 0; k < G->Edge_num; k++)
	{
		printf("�������vi,vj���±�i,j�����ڱߵ�Ȩֵ(�ö��Ÿ���~):\n");
		scanf("%d,%d,%d",&i,&j,&w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
}
/*--------------------------��Ϊ�����㷨------------------------*/
void ShortestPath_DJ(MGraph G,int v0,int P[MAXVEX],int D[MAXVEX])
{                   
	int v;                                        //1
	int w;                                        //2
	int k,min;                                    //3
	int final[MAXVEX]; //4 ������Ϊ��Ǳ�������,���ü��Ϸ���
	for (v = 0; v < G.Vex_num; v++)        //5 ��ʼ��������
	{                                          //6
		final[v] = 0;                             //7
		D[v] = G.arc[v0][v];                      //8
		P[v] = 0;                                 //9
	}                                          //10
	D[v0] = 0;                                 //11
	final[v0] = 1;                             //12
	for (v = 1; v < G.Vex_num; v++)       //13 �˴���ʼ��Ҫѭ��
	{                                          //14
		min = MAX;                                //15
		for (w = 0; w < G.Vex_num; w++)  //16 Ѱ�����ʼ��������Ķ���    
		{                                        //17   
			if (!final[w] && D[w] < min)          //18
			{                                     //19
				k = w;                             //20
				min = D[w];                //21 ��V(w)��V(0)����
			}                                    //22
		}                                        //23
		final[k] = 1;                    //24 �����ҵ�����Ķ�����
		for (w = 0; w < G.Vex_num; w++)  //25 ���Ǹ�ȷ��ѭ�����ܹؼ�
		{                                        //26
			if (!final[w] && (min + G.arc[k][w] < D[w])) //27
			{                                            //28
				D[w] = min + G.arc[k][w];      //29 �޸ĵ�ǰ·��
				P[w] = k;                      //30
			}                                  //31
		}                                      //32 
	}                                       //33 
}                                           //34
/*--------------------������----------��������-----------*/
int main(void)                
{
	int v;
	int P[MAXVEX];
	int D[MAXVEX];
	MGraph G;
	CreatMGraph(&G);
	ShortestPath_DJ(G,0,P,D); //ע��ڶ��������������0���㿪ʼѰ��
	for(v = 1; v < G.Vex_num; v++)
	{
		printf("v0������%d�����ȨֵΪ:%d\n",v,D[v]);
	}
	printf("���·������Ϊ:P=");
	for(v = 0; v < G.Vex_num; v++)
	{
		printf("<%d> ",P[v]);
	}
	printf("\n");
}
