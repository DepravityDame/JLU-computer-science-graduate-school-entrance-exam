#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
const int MAXN = 100;
typedef struct ArcNode{//�߽��ṹ��
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
		/*���c����
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
int Enum, Vnum;//Enum��¼������ Vnum��¼������
int visit[MAXN];//����Ƿ��ѷ�������
void dfs(graph g, int v, int &Vnum, int&Enum, int visit[]) {//v��ʾ��ǰ�ڵ㣬Vnum��Enum��Ҫ�ı���ֵ����ʹ��
	visit[v] = 1;//��ǵ�ǰ�ڵ��ѷ���
	Vnum++;//���ʽڵ���+1��
	ArcNode *p = g.adjlist[v].firstarc;//pָ��ǰ�ڵ��һ���ڽӽڵ�
	while (p != NULL) {
		Enum++;//p��Ϊ��˵������һ����
		if (!visit[p->adjvex]) {//p���ڽӽڵ���δ������
			dfs(g, p->adjvex, Vnum, Enum, visit);//������
		}
		p = p->nextarc;//pָ����һ�ڽӽڵ�
	}
}



bool istree(graph g) {
	Enum = 0;
	Vnum = 0;
	memset(visit, 0, sizeof(visit));//visit��0
	dfs(g, 1, Vnum, Enum, visit);//�����������ͼ
	if (Vnum == g.n && Enum == 2 * (g.n - 1))return true;//����ͼ�����ص㣬����Ϊ2*��������-1�������򷵻�true�����Ϸ���false
	else return false;

}


int main() {
	graph g;
	creatgraph(&g);
	if (istree(g))return 1;
	else return 0;
}

/*testdata
������
3 3
1 2
1 3
2 3
����
4 3
1 2
1 3
1 4

*/