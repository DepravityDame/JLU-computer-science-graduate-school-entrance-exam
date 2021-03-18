#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 100;
int visit[MAXN];


typedef struct ArcNode {
	int adjvex;
	ArcNode * nextarc;
};

typedef struct Vnode {
	int  data;
	ArcNode *firstarc;
};

typedef struct graph {
	Vnode adjlist[MAXN];
	int n, e;
};

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
int flag = 0;
void dfs(graph g,int v, int visit[]) {
	if (flag) {//����Ѿ��л���ֱ�ӷ���
		return;
	}
	visit[v] = 0;//��ǵ�ǰ�ڵ����ڷ���
	ArcNode*p = g.adjlist[v].firstarc;//pΪ��ǰ�ڵ��ڽӽڵ�
	while (p != NULL) {
		if (visit[p->adjvex] == 0) {//�����x�����ڵ�״̬ҲΪ0��˵���л�
			flag = 1; return;//flag��1������
		}
		if (visit[p->adjvex]==-1) {//�����ǰ�ڵ㻹δ����
			dfs(g, p->adjvex, visit);//��������p���ڽӽڵ�
		}
		p = p->nextarc;//pָ����һ���ڽӽڵ�
	}
	visit[v] = 1;//��v���ʽ���
}



int main() {
	memset(visit, -1, sizeof(visit));//��ʼ��������顣-1��ʾδ���ʣ�0��ʾ���ڷ��ʣ�1��ʾ�ѷ���
	graph *g = (graph*)malloc(sizeof(graph));
	creatgraph(g);
	dfs(*g, 1, visit);
	if (flag) { printf("true\n"); }
	else {
		printf("false\n");
	}
}