#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char M1[3] = { 'Y','N','2' };
char M2[3] = { 'y','n','1' };

bool exsit(int flag ,char x) {
	if (flag) {//�ж�˵�Ļ��ͻ���������Ƿ����
		for (int i = 0; i < 3; i++) {
			if (M1[i] == x)return true;
		}
		return false;
	}
	else {
		for (int i = 0; i < 3; i++) {
			if (M2[i] == x)return true;
		}
		return false;
	}
}
bool judge(char *str) {
	
	int flag = 1;//flagָʾ��ǰ�Ǹ���������˵��
	if (!exsit(flag, str[0])) {//�ж��Ƿ��һ����������˵��
		return false;
	}
	for (int i = 1; i < strlen(str); i++) {//������������
		if (str[i] == '2') {//��һ�������˽��������תΪ�ڶ���������
			flag = 0;
		}
		else if (str[i] == '1') {//�ڶ��������˽��������תΪ��һ��������
			flag = 1;
		}
		else if (!exsit(flag, str[i])) {//�жϵ�ǰ˵�Ļ���˵���Ļ������Ƿ����
			return false;
		}

	}
	return true;
}

int main() {
	char str[100];
	while (scanf("%s", str) != EOF) {
		if (judge(str))printf("1\n");
		else printf("0\n");
	}
}