#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

using namespace std;

bool isconsist(int n) {//��������
	while (n != 0) {
		int tmp = n % 10;//ȡn���һλ
		if (!(tmp == 1 || tmp == 3 || tmp == 5 || tmp == 7 || tmp == 9)) {//�жϵ�ǰλ�Ƿ����1,3,5,7,9
			return false;
		}
		n = n / 10;//n�ƶ�һλ
	}
	return true;
}


int main() {
	int n;
	scanf("%d", &n);
	if (isconsist(n)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}