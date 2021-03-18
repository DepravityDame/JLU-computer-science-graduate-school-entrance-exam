#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
const int MAXN = 100;
typedef struct ArcNode {
	int adjvex;
	ArcNode *nextarc;
};

typedef struct Vnode{
	int data;
	ArcNode *firstarc;
};
typedef struct Graph {
	Vnode adjlist[MAXN];
	int n; int e;
}*graph;
graph g = (graph)malloc(sizeof(Graph));

void creatgraph(graph g) {//����ͼ���̿��Բ�Ҫ��
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

bool find(int v, int u) {//vΪ��㣬uΪ�յ㣬�ڽӱ���ʽ�洢
	ArcNode *p = g->adjlist[v].firstarc;//pָ���һ���ڽӽڵ�
	while (p != NULL) {//�����ڽ�����
		if (p->adjvex == u) {//�ҵ�Ŀ��ڵ�˵���б�
			return true;//����true
		}
		p = p->nextarc;//pָ����һ���ڽӽڵ�
	}
	return false;//����β��δ�ҵ�������false
}

int main() {
	
	int v, u;
	creatgraph(g);//��������
	while (scanf("%d %d", &v, &u) != EOF) {//��������յ�
		printf("%d",find(v, u));//�ж����ޱ�
	}
	

}