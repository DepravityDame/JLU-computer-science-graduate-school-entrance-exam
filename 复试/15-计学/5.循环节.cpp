#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
int pos = 0;
bool find(int Dec[], int Rem[], int con, int r, int q) {//������������ظ�����������ͬ��һ��
	for (int i = 0; i < q; i++) {//����DEC��REM����
		if (Dec[i] == con && Rem[i] == r) {//���߶������
			pos = i;//��λѭ���ڿ�ͷ
			return true;//�������ҵ�
		}
	}
	return false;//����βҲδ�ҵ����򷵻�δ�ҵ�
}

void cal(int a, int b) {
	int Dec[100];//������
	int Rem[100];//��������
	memset(Dec, 0, sizeof(Dec));
	memset(Rem, 0, sizeof(Rem));
	int con, r, q=0;//con��ʱ�̣�r��ʱ����,qΪDecRem��βָ��
	int Int;//������������
	int end = -1;
	Int = a / b;//��¼��������
	if (a >=b) {
		a = a % b;//��Ϊ�����
	}
	con = a * 10 / b;//�����һ����
	r = (a * 10) % b;//�����һ������
	while (!find(Dec, Rem, con, r, q)) {//�ڱ���δ����ѭ����
		Dec[q] = con;//�������δ���ֹ�����洢
		Rem[q] = r;//�������δ���ֹ�����洢
		q++;//����β����
		con = r * 10 / b;//������һ����
		r = (r * 10) % b;
	}
	printf("%d.", Int);//�����������
	for (int i = 0; i < pos; i++) {//�����ѭ��С������
		printf("%d", Dec[i]);
	}
	for (int i = 99; i >= 0; i--) {//Ѱ��ѭ����ĩβ
		if (Dec[i] != 0) {
			end = i;
			break;
		}
	}
	if (end == -1) {//��û��С������
		printf("0");//��0
	}
	for (int i = pos; i <=end; i++) {//���ѭ��С������
		if (i == pos) {//��ͷ���������
			printf("(");
		}
		printf("%d", Dec[i]);
		if (i == end) {//��β���������
			printf(")");
		}
	}

}



int main() {
	int n, d;
	while (scanf("%d %d", &n, &d) != EOF) {

		cal(n, d);
	}
}