#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>
#include<stack>
using namespace std;

int main() {
	char arr[100];//�洢�ַ�����
	while (scanf("%s", arr) != EOF) {
		int len = strlen(arr);//��ȡ�ַ�������
		if (arr[0] != 'a' || arr[len - 1] != 'd') { printf("N"); continue; }//ͷβ�����ϵ�ֱ�����N���ж���һ��
		int k = 0;
		while (arr[k] == 'a') {//ͳ���ַ�a���ִ���
			k++;
		}
		while (arr[k] == 'b') {//ͳ���ַ�b���ִ���
			k++;
		}
		while (arr[k] == 'c') {//ͳ���ַ�c���ִ���
			k++;
		}
		while (arr[k] == 'd') {//ͳ���ַ�d���ִ���
			k++;
		}
		if (k == len) {//abcd�������ʱk����len���
			printf("Y\n");
		}
		else {
			printf("N\n");
		}
	}
}