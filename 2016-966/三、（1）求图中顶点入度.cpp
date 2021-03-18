#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
const int MAXN = 100;

typedef struct ArcNode {
	int adjvex;
	ArcNode* nextarc;
};



typedef struct Vnode {
	int data;
	ArcNode* firstarc;
};

typedef struct Graph {
	Vnode adjlist[MAXN];
	int n, e;
}graph;



int* count(Graph g) {
	int *indegree = new int[g.n+1];//�½�indegree��¼����
	memset(indegree, 0, sizeof(int)*(g.n + 1));//��ʼ��Ϊ0
	for (int i = 1; i <= g.n; i++) {//�����ڽӱ�
		ArcNode*p = g.adjlist[i].firstarc;//�߽�����++
		while (p != NULL) {
			indegree[p->adjvex]++;
			p = p->nextarc;
		}
	}
	return indegree;//���ش�����
}


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
	int *ans = count(*g);
	for (int i = 1; i <= g->n; i++) {
		printf("%d ", ans[i]);
	}
}

