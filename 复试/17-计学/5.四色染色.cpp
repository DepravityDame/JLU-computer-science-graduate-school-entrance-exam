#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int n = 5;
int color[n];//������5�ڵ�Ϊ�����н��
int c = 4;//��ɫ����
int 	 a[5][5] = {
		0,1,1,1,1,
		1,0,1,1,0,
		1,1,0,1,1,
		1,1,1,0,1,
		1,0,1,1,0,
};
int check(int k) {
	for (int i = 0; i < k; i++) {//����k*k���ڽӾ���
		if (a[i][k] == 1 && color[i] == color[k]) {//a[i][k]==1˵���бߣ�color[i]==color[k]˵����ɫ�غϲ�����Ҫ��
			return false;
		}
	}
	return true;//��������β��δ���ֳ�ͻ�򷵻�true
}
int count = 0;
void graphcolor(int step) {
	if (step == n) {//���нڵ㶼�Ѹ�ֵ�Ϸ���ɫ�����
		for (int i = 0; i < c; i++) {
			printf("%d ", color[i]);
		} 
		count++;//��������
		printf("\n");
		return;//����
	}
	else {
		for (int i = 1; i <= c; i++) {//����������ɫѡ��
			color[step] = i;//��ǵ�ǰ�ڵ���ɫ
			if (check(step) == 1) {//����Ƿ�Ϸ�
				graphcolor(step + 1);//�Ϸ���ݹ����һ�ڵ���м��
			}
		}
	}
}

int main() {
	graphcolor(0);
	printf("%d", count);
	return 0;
}