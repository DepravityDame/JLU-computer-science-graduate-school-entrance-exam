#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

bool isprime(int n) {
	if (n < 2)return false;
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int visit[21];
int ans[20];
bool check(int step) {//����Ƿ����Ҫ��
	if (isprime(ans[step - 1] + ans[step]))return true;//����Ҫ�󷵻�true
	else if (step == 19) {//��ǰΪ���һ����Ҫ�����һ���Ƿ�ƥ��
		if(isprime(ans[19]+ans[0]))return true;
	}
	else return false;//��ƥ�䷵��false
}

int flag = 0;
void dfs(int step) {//������ȱ���
	if (step == 20) {//����������������
		for (int i = 0; i < 20; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		flag = 1;//��ĿҪ�����һ�飬����һ��󷵻ء�
	}
	if (flag)return;
	for (int i = 2; i <= 20; i++) {//�����������֣�1��Ĭ���Ѿ�����
		if (!visit[i]) {//�����ǰ����δʹ��
			ans[step] = i;//��ǰλ��ֵ��ǰ����
			visit[i] = 1;//����ѷ���
			if (check(step)) {//���Ϸ�������һλ����DFS��
				dfs(step + 1);
			}
			visit[i] = 0;//��Ǳ�����Ϊδ���ʻ���
		}
	}
	
}


int main() {
	memset(visit, 0, sizeof(visit));//��ʼ�����ַ��ʱ������
	memset(ans, 0, sizeof(ans));//��ʼ��������
	ans[0] = 1;//���ô𰸵�һλΪ1
	visit[1] = 1;//���Ϊ�ѷ���
	dfs(1);//dfs���б���
}



