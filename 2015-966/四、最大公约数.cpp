#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>.
#include<string.h>
#include<stack>
using namespace std;


int gcd(int a, int b) {
	if (a%b == 0)return b;//��a������b�򷵻�b
	else {
		return gcd(b, a%b);//�ݹ����
	}
}

int main() {
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		printf("%d\n", gcd(a, b));
	}
}