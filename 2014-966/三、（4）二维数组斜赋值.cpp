#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>.
#include<string.h>
int main() {
	int a[10][10];//�½�����
	memset(a, 0, sizeof(a));//��ʼ������
	int n = 1;//��ֵ����
	int i, j;//����ָ��
	for (int k = 0; k < 10; k++) {//k����ѭ������
		j = 0; i = k;//��ÿ�е�һ�����ֿ�ʼ��ֵ
		while (i >= 0) {
			a[i--][j++] = n++;//б�Ϸ���ֵ��iΪ0ʱֹͣ
		}
	}
	for (int k = 1; k <10; k++) {////k����ѭ������
		i = 9; j = k;//���һ�еڶ��п�ʼ��ֵ
		while (j<10) {//j=9ʱ����߽���ֹ
			a[i--][j++] = n++;//б�Ϸ���ֵ
		}
	}
	for (int i = 0; i < 10; i++) {//�����
		for (int j = 0; j < 10; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
}