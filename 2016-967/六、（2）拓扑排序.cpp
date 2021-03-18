#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100;

typedef struct ArcNode {
	int adjvex;
	ArcNode *nextarc;
};



typedef struct Vnode {
	int data;
	ArcNode * firstarc;
};
typedef struct Graph {
	Vnode adjlist[MAXN];
	int n;
	int e;
}graph;


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
int topo[100];//������
int visit[100];//����Ƿ���ʹ�
int t;
bool dfs(int v) {
	visit[v] = 1;//��ǵ�ǰ�ڵ��ѷ���
	ArcNode *p = g->adjlist[v].firstarc;//pָ���ڽӽڵ�
	while (p != NULL) {
		if (!visit[p->adjvex]) {//����ǰ�ڵ��ڽӽڵ�δ������
			dfs(p->adjvex);//�����ڽӽڵ�
		}
		p = p->nextarc;//������һ���ڽӽڵ�
	}
	topo[t--] = v;//��󱻷��ʵĽڵ���������DFS�����һ��
	return true;
}



int main() {
	creatgraph(g);
	memset(visit, 0, sizeof(visit));
	t = g->n;
	for (int i = 1; i <= g->n; i++) {//
		if (!visit[i]) {
			dfs(i);//���ڵ�δ���ʣ���������
		}
	}

	for (int i = 1; i <= g->n; i++) {
		printf("%d", topo[i]);//���������������
	}
}

//test data
/* 5 5 
1 2 
1 3 
2 4 
3 4 
4 5*/