#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

bool isright(char str[]) {
	int flagzm = 0;//Сд��ĸ��ʶ
	int flagZM = 0;//��д��ĸ��ʶ
	int flagsz = 0;//���ֱ�ʶ
	int len = strlen(str);//�����ַ�������
	for (int i = 0; i < len; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			flagsz = 1;//�������ָ������ֱ�ʶ
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			flagzm = 1;//����Сд��ĸ����Сд��ĸ��ʶ
		}
		else if (str[i] >= 'A'&& str[i] <= 'Z') {
			flagZM = 1;//���Ǵ�д��ĸ���´�д��ĸ��ʶ
		}
		if (flagzm + flagZM + flagsz > 1) {//���Ѿ�����2��������true
			return true;

		}
	}
	return false;//���ַ���ĩβҲΪ������������false
}


int main() {
	
	char str[100];
	while (scanf("%s", str) != EOF) {
		if (isright(str)) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
	
}