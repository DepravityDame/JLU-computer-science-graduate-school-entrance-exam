#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int main() {
	int n;
	int step;
	while (scanf("%d", &n) != EOF) {
		step = 1;//��Ӧ��0��ʼ��¼������Ŀ����ʾ������22���16�Ǵ�1��ʼ�Ƶģ����������ʵ���������
		while (n != 1) {//n������1ʱѭ��
			if (n % 2 == 0) {
				n = n / 2; 
			}//nΪż��ʱ����2
			else {
				n = 3 * n + 1;//nΪ����*3+1��
			}
			step++;//�Ʋ�+1
		}
		printf("%d\n", step);//�������
	}
	
}