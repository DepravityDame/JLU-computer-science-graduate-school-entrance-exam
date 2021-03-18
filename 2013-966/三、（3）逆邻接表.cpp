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

void convert(Graph *a,Graph *b) {//��������
	for (int i = 1; i <= a->n; i++) {//�������нڵ�
		ArcNode* p = a->adjlist[i].firstarc;//pָ��ǰ�ڵ��һ���ڽӽڵ�
		while (p != NULL) {//p��Ϊ�ռ���
			ArcNode *tmp = (ArcNode*)malloc(sizeof(ArcNode));//�½��ڵ�
			tmp->adjvex = a->adjlist[i].data;//�½ڵ�������Ϊ��ǰ��ͷ�ڵ�ֵ�������ܵ�tmp��
			tmp->nextarc = b->adjlist[p->adjvex].firstarc;//ͷ�巨����Ŀ��ڵ��firstarc
			b->adjlist[p->adjvex].firstarc = tmp;
			p = p->nextarc;//pָ����һ���ڵ�//������һ���ڵ�
		}
	}
	int tmp = 0;
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
	Graph *a = (Graph*)malloc(sizeof(Graph));
	creatgraph(a);
	Graph *b = (Graph*)malloc(sizeof(Graph));
	b->e = a->e; b->n = a->n;
	for (int k = 1; k <= b->n; k++) {//��ʼ��������
		b->adjlist[k].data = k;
		b->adjlist[k].firstarc = NULL;
	}
	convert(a,b);

	for (int i = 1; i <= a->n; i++) {
		printf("%d:%d\n",i, indegree[i]);
	}

}

//test data

/*
5 5
1 2
1 3
2 4
3 4
4 5
*/