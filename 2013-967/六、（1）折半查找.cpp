#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

int Del(int a[], int n, int x) {//��������
	int i = 0;//��߽�
	int j = n-1;//�ұ߽�
	int mid = (i + j) / 2;//��ֵ
	while (i < j) {//�߽�δ�ཻʱ
		if (a[mid] == x) {//����ҵ���Ԫ��
			for (int k = mid; k < n-1; k++) {//�������ǰ��һλ�൱��ɾ��
				a[k] = a[k + 1];
			}
			n--;//�ܳ���1
			return n;//���س���
		}
		else if (a[mid] > x) {//��ֵ��Ҫɾ�����ݴ󣬽��ұ߽�����Ϊmid-1
			j = mid - 1;
		}
		else {
			i = mid + 1;//��ֵ��Ҫɾ������С������߽�����Ϊmid+1
		}
		mid = (i + j) / 2;//������ֵ
	}
	printf("No found it!");//�߽��ཻ��δ�ҵ�������ʧ�ܣ�����δ�ҵ���
	return n;
}


int main(){
	int a[10] = {1,2,3,4,5,6,7,8,9,10};//�������ݿ����ǲ���д��ֻ��Ҫд�ϱߺ�������
	int x,n;
	n = 10;
	while (scanf("%d", &x) != EOF) {
		n=Del(a,n,x);
		for (int i = 0; i < n; i++) {//�����ǰ����
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	
}