#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
const int MAXN = 100;
typedef struct ArcNode {//�߽��ṹ��
	int adjvex;
	ArcNode *nextarc;
};

typedef struct Vnode {//����ṹ��
	int data;
	ArcNode *firstarc;
};

typedef struct Graph {//ͼ�ṹ��
	Vnode adjlist[MAXN];
	int n, e;
}graph;
graph *g = (graph*)malloc(sizeof(graph));
int t;
void creatgraph(graph *g) {//����ͼ���̿��Բ�Ҫ��
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

		p = (ArcNode*)malloc(sizeof(ArcNode));//���������ͼ�ⲿ�ִ���Ҫʡ�ԣ�
		p->adjvex = i;
		p->nextarc = g->adjlist[j].firstarc;
		g->adjlist[j].firstarc = p;
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
	creatgraph(g);
}

