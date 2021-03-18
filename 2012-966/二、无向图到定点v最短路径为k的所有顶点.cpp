#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100;

typedef struct ArcNode {
	int adjvex;
	ArcNode * nextarc;
};

typedef struct Vnode {
	int  data;
	ArcNode *firstarc;
	int dist;
};

typedef struct Graph {
	Vnode adjlist[MAXN];
	int n, e;
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

		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->nextarc = g->adjlist[j].firstarc;
		g->adjlist[j].firstarc = p;
	}
	/*
			for (int k = 1; k <=g->n; k++) {
				printf("%d  ", g->adjlist[k].data);
				ArcNode*p = g->adjlist[k].fistarc;
				while (p != NULL) {
					printf("%d ", p->adjvex);
					p = p->nextarc;
				}
				printf("\n");
			}
			*/
}
int visit[MAXN];
void BFS(int from, int k) {
	for (int i = 0; i < g->n; i++) {
		g->adjlist[i].dist = 0;
	}//��ʼ�����нڵ�distΪ0��
	queue<Vnode>q;//������������BFS
	visit[from] = 1;//�������ѷ���
	q.push(g->adjlist[from]);//��ǰ�ڵ����
	while (!q.empty()) {//������в�Ϊ��
		Vnode cur = q.front();//��ȡ��ͷԪ��
		q.pop();//��ͷԪ�س���
		ArcNode *p = cur.firstarc;//pָ��ǰ�ڵ��һ���߽ڵ�
		while (p != NULL) {
			if (visit[p->adjvex] == 0) {//�����ǰ�߽ڵ�δ������
				visit[p->adjvex] = 1;//���ʵ�ǰ�ڵ�
				g->adjlist[p->adjvex].dist=cur.dist+1;//��ǰ�ڵ���ڶ�ͷ�ڵ����+1
				q.push(g->adjlist[p->adjvex]);//��ǰ�ڵ����
				if (g->adjlist[p->adjvex].dist == k) {//����ǰ�ڵ�������k�����
					printf("%d ", p->adjvex);
				}
			}
			p = p->nextarc;//pָ����һ���ڽӽڵ�
		}
	}
}



int main() {
	creatgraph(g);
	memset(visit, 0, sizeof(visit));
	int from, k;
	while (scanf("%d %d", &from, &k) != EOF) {//��������벽��
		memset(visit, 0, sizeof(visit));
		BFS(from, k);//������ȱ�������̾���
	}
	
}