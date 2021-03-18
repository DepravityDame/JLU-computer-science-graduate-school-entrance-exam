#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<algorithm>
const int n = 5;
using namespace std;
int a[n][n] = {
		0,1,1,0,0,
		1,0,1,1,0,
		1,1,0,1,0,
		0,1,1,0,1,
		0,0,0,1,0,
};
int visit[n];
int print[n];
void DFS(int v, int step, int k) {
	visit[v] = 1;//��ǵ�ǰ�ڵ��ѷ���
	if (step == k && !print[v]) {//��ǰ�ڵ�����������k����δ����������
		printf("%d ", v);
		visit[v] = 0;//��Ϊδ����
		print[v] = 1;//����������
		return;//����
	}

	for (int i = 0; i < n; i++) {//���������ڽӽڵ�
		if (a[v][i] == 1 && !visit[i]) {//�����������δ���ʹ����ڽӽڵ�
			DFS(i, step + 1, k);
		}
	}
	visit[v] = 0; //  ��Ϊδ����
}

 

int main() {
	memset(visit, 0, sizeof(visit));//��ʼ�����ʱ������
	memset(print, 0, sizeof(print));//��ʼ������������
	int n;
	while (scanf("%d", &n) != EOF) {
		memset(visit, 0, sizeof(visit));
		memset(print, 0, sizeof(print));
		for (int i = 1; i <= n; i++) {//��������С�ڵ���k�Ĳ������ܵ���ĵ�
			DFS(0, 0, i);//���ú���
		}
		printf("\n");//��Ϊ����
	}

}