#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>
#include<stack>
using namespace std;

int main() {//��������
	int n; 
	int sum;
	stack<int>mystack;//ջ����������ת������ֵ
	while (scanf("%d", &n) != EOF) {
		sum = 0;
		int tmp = 1;
		while (n != 0) {
			mystack.push(n % 8);//ʮ����ת�˽��ƹ���
			n = n / 8;
		}
		while (!mystack.empty()) {//���ת����İ˽�����
			printf("%d", mystack.top());
			mystack.pop();
		}
		printf("\n");
	}
	
}