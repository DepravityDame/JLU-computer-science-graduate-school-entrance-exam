#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>

int pos;//posΪѭ������ʼ


bool find(int Dec[], int Rem[], int con, int r, int q) {//�жϵ�ǰcon��r�Ƿ���Dec��Rem�г��ֹ�
	for (int i = 0; i < q; i++) {//δ����β�����
		if (Dec[i] == con && Rem[i] == r) {//�ҵ���
			pos = i;//����ѭ���ڿ�ʼ
			return true;//�����ҵ���
		}
	}
	return false;//��ĩβ��û�ҵ�������û�ҵ�
}




void cal(int a, int b) {
	int Dec[100];//�����λ������
	int Rem[100];//�����λ��������
	memset(Dec, 0, sizeof(Dec));//��ʼ��Ϊ0
	memset(Rem, 0, sizeof(Rem));//��ʼ��Ϊ0
	int con, r, end=-1, q=0;//con��ʾ��ʱ�̣�r��ʾ��ʱ������endΪѭ���ڽ�β��qΪDecĩβָ��
	int Int;//������������
	Int = a / b;//ȡ��������
	if (a > b) {
		a = a % b;//��Ϊ�����
	}
	con = a * 10 / b;//��ʼ����һ����
	r = (a * 10) % b;//��ʼ����һ������
	while (!find(Dec, Rem, con, r, q)) {//������û�ҵ���ѭ��
		Dec[q] = con;//����������
		Rem[q] = r;//������������
		q++;//��βָ�����
		con = r * 10 / b;//������һ����
		r = (r * 10) % b;//������һ������
	}
	printf("%d.", Int);//�����������
	for (int i = 99; i >= 0; i--) {//����ѭ����ĩβ
		if (Dec[i] != 0) {
			end = i;//��¼ѭ����ĩβ
			break;
		}
	}
	if (end == -1) {//�ܹ�������
		printf("0");//��0
	}
	for (int i = 0; i < pos; i++) {//�����ѭ������
		printf("%d", Dec[i]);
	}
	for (int i = pos; i <= end; i++) {//���ѭ������
		if(i==pos)printf("(");//ǰ����
		printf("%d", Dec[i]);
		if(i==end)printf(")");//������
	}
	printf("\n");//����
}

int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		cal(a, b);
	}
}