#define _CRT_SECURE_NO_DEPRECATE //��֤VS�����scanf����
#include<stdio.h>



void plat(int a[], int n) {//������
	int key = a[0];//�ڱ��ڵ㣬��ʾƽ̨��ʼԪ��ֵ
	int len=1;//ƽ̨����,a[0]�Ѵ�����ƽ̨��������Ϊ1����˴�����Ϊ0��forѭ������i��0��ʼ
	int max=0;//���ƽ̨����
	for (int i = 1; i < n; i++) {
		if (a[i] == key) {//��ƽ̨��Ԫ��ֵ��ȣ�ƽ̨����++
			len++;
		}
		else {//��ƽ̨��Ԫ�ز���
			if (len > max) {//�Ƚϵ�ǰƽ̨���������ƽ̨���ȣ��������ֵ
				max = len;
			}
			key = a[i];//����ƽ̨��Ԫ��ֵ
			len = 1;//ƽ̨���ȹ�1
		}
	}
	printf("%d\n", max);
}








int main() {
	const int n = 11;
	int a[n] = { 9,8,8,8,8,7,3,3,1,1,1 };// test data;
	plat(a, n);//���ú�����
}

