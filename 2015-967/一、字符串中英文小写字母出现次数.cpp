#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
int main() {
	char str[100];//�洢������ַ���
	int a[27]; //�洢26����ĸ���ִ���
	while (scanf("%s", str) != EOF) {//�����ַ���
		memset(a, 0, sizeof(a));//������0
		for (int i = 0; str[i] != '\0'; i++) {//�ж���ĸ
			if (str[i] >= 'a'&&str[i] <= 'z') {
				a[str[i] - 'a']++;//��Ӧ��ĸͳ�ƴ���++
			}
			
		}
		for (int i = 0; i < 26; i++) {
			printf("%c:%d\n", i + 'a', a[i]);//�������ĸ�����ִ���
		}
	}
}