#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<iostream>
using namespace std;
const int MAXN = 100;
typedef struct ArcNode {
	int adjvex;
	ArcNode *nextarc;
};

typedef struct Vnode {
	int data;
	ArcNode* firstarc;
};

typedef struct Graph {
	Vnode adjlist[MAXN];
	int n, e;
};
int indegree[MAXN];

void count(Graph g) {//��������
	for (int i = 1; i <= g.n; i++) {//�������нڵ�
		ArcNode* p = g.adjlist[i].firstarc;//pָ��ǰ�ڵ��һ���ڽӽڵ�
		while (p != NULL) {//p��Ϊ�ռ���
			indegree[p->adjvex]++;//pָ��ڵ�����++
			p = p->nextarc;//pָ����һ���ڵ�
		}
	}
}
void creatgraph(Graph *g) {//����ͼ���̿��Բ�Ҫ��
	int i, j;
	printf("n,e = ");
	scanf("%d %d", &g->n, &g->e);//����ڵ�������
	printf("Please input jd informatin: ");//�������
	for (int k = 1; k <= g->n; k++) {//��ʼ������ڵ�
		g->adjlist[k].data = k;
		g->adjlist[k].firstarc = NULL;
	}
	printf("Please input the from and to: ");//����߲������ڽӱ�
	for (int k = 1; k <= g->e; k++) {
		ArcNode * p;
		scanf("%d %d", &i, &j);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->nextarc = g->adjlist[i].firstarc;;
		g->adjlist[i].firstarc = p;

		//p = (ArcNode*)malloc(sizeof(ArcNode));//���������ͼ�ⲿ�ִ���Ҫʡ�ԣ�
		//p->adjvex = i;
		//p->nextarc = g->adjlist[j].firstarc;
		//g->adjlist[j].firstarc = p;
		/*�������
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
int main() {
	memset(indegree, 0, sizeof(indegree));
	Graph *g = (Graph*)malloc(sizeof(Graph));
	creatgraph(g);
	count(*g);
	for (int i = 1; i <= g->n; i++) {
		printf("%d:%d\n",i, indegree[i]);
	}

}