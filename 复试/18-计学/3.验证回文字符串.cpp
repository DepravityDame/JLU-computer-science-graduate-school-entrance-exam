#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>


bool yz(char str[]) {
	int i = 0;//ǰָ��
	int j = strlen(str) - 1;//��ָ��
	while (i < j) {//δ�غ�ʱѭ��
		if (str[i] != str[j]) {//��ǰ������򷵻�flase
			return false;
		}
		i++;//ǰָ����ƺ�ָ��ǰ��
		j--;
	}
	return true;//ָ���غϷ���true
}


int main() {
	char str[100];//�������鴢���ַ���
	while (scanf("%s", str) != EOF) {
		if (yz(str))printf("1\n");//��֤�Ƿ��ǻ����ַ���
		else {
			printf("0\n");
		}
	}
}