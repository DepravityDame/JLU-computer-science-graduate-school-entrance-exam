#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
const int INF = 999999;
struct Edge {//����߽ڵ�
	int to;//Ŀ��ڵ�
	int length;//Ȩ��
	Edge(int t, int l) :to(t), length(l) {}; //���غ���
};
const int MAXN = 200;//�������ֵ
struct Point {//����ڵ�
	int number;//�������
	int distance;//�������
	Point(int n, int d) :number(n), distance(d) {};//����С�ں�
	bool operator <(const Point&p)const {
		return distance > p.distance;//��ֵС����ǰ��
	}
};
int dis[MAXN];
vector<Edge>graph[MAXN];
void Dijkstr(int s) {
	priority_queue<Point>myqueue;//�������ȶ��У�����ʹ�����ȶ��б�֤��Сdist���ڶ��ף�
	dis[s] = 0;//��ʼ��ԭ�����Ϊ0
	myqueue.push(Point(s, dis[s]));//ԭ�����
	while (!myqueue.empty()) {//�ӷɿ�ѭ��
		int u = myqueue.top().number;//�����
		myqueue.pop();
		for (int i = 0; i < graph[u].size(); i++) {//�����ýڵ�Ϊ���ı�
			int v = graph[u][i].to;//vָ��Ŀ�Ľڵ�
			int d = graph[u][i].length;//��¼��ǰ��Ȩ��
			if (dis[v] > dis[u] + d) {//�����ǰ��dis+dС��Ŀ��ڵ�dis
				dis[v] = dis[u] + d;//����Ŀ��ڵ���Сdis
				myqueue.push(Point(v, dis[v]));//Ŀ��ڵ����
			}
		}
	}
	return;
}


int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {//���붥����������
		memset(graph, 0, sizeof(graph));//��ʼ��ͼ
		fill(dis, dis + n, INF);//������Ϊdis
		while (m--) {//ѭ�������
			int from, to, length;//����Դͷ��ȥ��Ȩ��
			scanf("%d %d %d",&from,&to,&length);//�����
			graph[from].push_back(Edge(to, length));//���ߴ���������
			graph[to].push_back(Edge(from, length));
		}
		Dijkstr(0);//ʹ��Dijkstr�㷨�����·��
		int max = 0;
		for (int i = 0; i < n; i++) {//�������·�����ֵ
			if (dis[i] != INF && dis[i] > max) {
				max = dis[i];
			}
		}
		printf("%d", max);//���Tֱ��
	}
}