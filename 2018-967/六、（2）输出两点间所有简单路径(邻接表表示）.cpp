#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAXN = 100;
struct ArcNode {
	int adjvex;
	ArcNode* nextarc;
};



struct Vnode {
	int data;
	ArcNode* firstarc;
};
struct graph
{
	Vnode adjlist[MAXN];
	int n, e;
};

graph *g = (graph*)malloc(sizeof(graph));
void creatgraph(graph *g) {
	int i, j;
	printf("n,e = ");
	scanf("%d %d", &g->n, &g->e);
	printf("Please input jd informatin: ");
	for (int k = 1; k <= g->n; k++) {
		g->adjlist[k].data = k;
		g->adjlist[k].firstarc = NULL;
	}
	printf("Please input the from and to: ");
	for (int k = 1; k <= g->e; k++) {
		ArcNode * p;
		scanf("%d %d", &i, &j);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->nextarc = g->adjlist[i].firstarc;
		g->adjlist[i].firstarc = p;

		/*

		/*
				for (int k = 1; k <=g->n; k++) {
					printf("%d  ", g->adjlist[k].data);
					ArcNode*p = g->adjlist[k].firstarc;;
					while (p != NULL) {
						printf("%d ", p->adjvex);
						p = p->nextarc;
					}
					printf("\n");
				}
				*/
	}
}


int path[MAXN];
int visit[100];
void DFS(graph g,int v, int to,int d) {//��������
	visit[v] = 1;//��ǵ�ǰ�ڵ��Ѿ�����
	path[++d] = v;//����·������
	if (v == to && d > 1) {//�統ǰ�ڵ���ҪѰ�ҵ��ص�
		for (int i = 0; i <= d; i++) {//���·��
			printf("%d ", path[i]);
		}
		printf("\n");
	}
	ArcNode *p = g.adjlist[v].firstarc;//pָ��ǰ�ڵ��һ���ڽӽڵ�
	while (p != NULL) {
		if (!visit[p->adjvex]) {//����ǰ�ڵ�δ������
			DFS(g, p->adjvex, to,  d);//�����ڽӽڵ�
		}
		p = p->nextarc;//��һ���ڽӽڵ�
	}
	visit[v] = 0;//��ǵ�ǰ�ڵ�Ϊδ����
}

int main() { 
	memset(path, 0, sizeof(path));
	memset(visit, 0, sizeof(visit));
	creatgraph(g);
	DFS(*g, 1, 6, -1);
}
//test data{
6 8
1 2
1 3
2 4
2 3
3 4
4 5
4 6
5 6
}