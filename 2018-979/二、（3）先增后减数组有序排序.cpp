#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>


int main() {
	const int n = 10;
	const int m = 4;
	int a[n] = { 1,2,3,8,7,6,5,4,3,2 };//test data
	int *ans = new int[n];//�½�������
	int k = 0;//������ָ��
	int i = m-1, j =m;//iָ��ǰm���ֵ��jָ���n-m���ֵ
	while (i >= 0&&j<n) {//û���߽�ʱѭ��
		if (a[i]>a[j]) {//�ϴ�Ľ�������
			ans[k++] = a[i--];
		}
		else if (a[i] == a[j]) {
			ans[k++] = a[i--];
			j++;//ȥ��
		}
		else {
			ans[k++] = a[j++];
		}
	}
	while (i >=0) {//�������Ԫ��
		ans[k++] = a[i--];
	}
	while (j <n) {//�������Ԫ��
		ans[k++] = a[j++];
	}
	for (int i = 0; i < k; i++) {//�����
		printf("%d ", ans[i]);
	}
}