#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int ysh(int n) {//����Լ����
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n%i == 0) {//������
			sum += i;
		}
	}
	return sum;//����Լ����
}
int main() {
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF) {//����m��n
		if (ysh(m)==n && m== ysh(n)) {//��������
			printf("YES\n");
		}
		else {//����������
			printf("NO\n");
		}
	}
}