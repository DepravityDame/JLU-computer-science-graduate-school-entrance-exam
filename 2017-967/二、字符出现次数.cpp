#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
using namespace std;


int * cot(char s[], char a[], int n) {
	int *ans = new int[n];//������һά�ַ�����ȳ��Ĵ�����
	memset(ans, 0, sizeof(int)*n);//����Ԫ����0����ansΪָ�����ͣ���sizeofδʹ��sizeof(ans),�����ᵼ��ֻ��һ��Ԫ�ر���ֵ
	int len = strlen(s);//�����ַ�������
	for (int i = 0; i < len; i++) {//�����ַ���
		for (int j = 0; j< n; j++) {//���ַ������в����Ƿ��з��ϵ�
			if (s[i] == a[j]) {
				ans[j]++;//�з��ϵĶ�Ӧ��������++
				break;//�ж���һλ
			}
		}
	}
	return ans;//���ؼ�������ָ��
}





int main() {
	char str[100];
	char a[4] = { 'a','b','c' };
	int *ans=NULL;
	while (scanf("%s", str) != EOF) {
		ans = cot(str, a, 3);//���ú�����
		for (int i = 0; i < 3; i++) {//������
			printf("%c:%d\n", a[i], ans[i]);
		}
	}
	
}