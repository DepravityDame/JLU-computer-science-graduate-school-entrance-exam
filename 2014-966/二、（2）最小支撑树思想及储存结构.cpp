#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
const int MAXN = 100;
//�㷨���˼�룬����Dijkstra�㷨��֧���������������·��ʱ�������·���߼���������T
typedef struct ArcNode {//�߽ڵ㴢��ṹ
	int adjvex;
	ArcNode* nextarc;
};

typedef struct Vnode {//����ڵ㴢��ṹ
	int data;
	ArcNode* firstarc;
};

typedef struct graph {//�ڽӱ�ͼ/֧��������ṹ
	Vnode adjlist[MAXN];
	int n, e;
};

typedef struct Edge {//�ߴ���ṹ
	int from;
	int to;
	int weight;
};

int dis[MAXN];//�������·������