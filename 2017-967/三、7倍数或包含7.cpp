#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
using namespace std;
bool inc(int n) {//�жϸ�λ�������Ƿ����7
	while (n != 0) {//��λȡ���ֲ��ж�
		if (n % 10 == 7) {
			return true;
		}
		n = n / 10;
	}
	return false;//����������false
}
void print(int k) {//��������
	int flag=1;//�����������
	for (int i = 7; i < k; i++) {//��һ������СΪ7��ֱ�Ӵ�7��ʼ
		if (i % 7 == 0 || inc(i)) {//��ǰ���ְ���7���ܱ�7����
			if (flag) {
				printf("%d",i);//��һ��Ԫ��ǰ���������
				flag = 0;
			}
			else {
				printf(",%d",i);;//����Ԫ��ǰ���������
				
			}
			
		}
	}
}


int main() {
	int k;
	while (scanf("%d", &k) != EOF) {//��������
		print(k);//ִ�к���
	}
}