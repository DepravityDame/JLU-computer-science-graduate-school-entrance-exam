#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
bool judge(char str[]) {
	for (int i = 0; str[i] != '\0'; i++) {//��λ�ж��Ƿ�Ϊ����
		if (!(str[i] >= '0'&&str[i] <= '9'))return false;//�����һλ�����򷵻�false
	}
	return true;//ȫ�����Ƿ���true
}

int main() {
	char str[100];//�����ַ���
	while (scanf("%s", str) != EOF) {
		if (judge(str))  printf("%s\n",str);//��������������������������������
		else printf("����\n");
	}
		
}