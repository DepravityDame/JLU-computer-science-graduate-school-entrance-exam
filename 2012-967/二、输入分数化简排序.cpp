#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>
#include<stack>
using namespace std;


typedef struct fs {//����ڵ�ṹ�嶨��
	int fz;//����
	int fm;//��ĸ
	fs* next;//�ṹ��ָ��
}*List;

int gys(int a, int b) {//�����Լ���Ի���
	if (a%b == 0)return b;
	else {
		return gys(b, a%b);
	}
}

int main() {
	int a; int b;
	List head = (List)malloc(sizeof(fs));//������ͷ�ڵ�
	List p1, p;
	p1 = head;
	head->fz = 0;
	head->fm = 1;//���Ի���ͷ�ڵ�Ϊ0
	head->next = NULL;
	for (int i = 0; i < 100; i++) {//����
		p1 = head;
		scanf("%d %d", &a, &b);//������ӷ�ĸ
		List p= (List)malloc(sizeof(fs));//�����½ڵ�
		p->fz = a / gys(a, b);//�������
		p->fm= b / gys(a, b);//�����ĸ
		while (p1->next!=NULL && p1->next->fz*1.0 / p1->next->fm < p->fz*1.0 / p->fm) {//Ѱ�Ҳ���λ��
			p1 = p1->next;
		}
		if (p1->next !=NULL && p1->next->fz*1.0 / p1->next->fm == p->fz*1.0 / p->fm)continue;//�����ظ�ֵ
		p->next = p1->next;//���½ڵ��������
		p1->next = p;
	}
	p1 = head->next;
	while (p1 != NULL) {//��������õ�����
		printf("%d/%d ", p1->fz, p1->fm);
		p1 = p1->next;
	}
}

//test data
7 30 12 32 4 4 13 23 5 10 23 44 12 15 23 33 1 11 15 19 1 
8 28 49 3 7 4 32 30 37 8 10 17 44 9 20 14 49 38 47 26 28
5 27 21 28 2 2 12 21 26 40 17 38 16 18 21 40 16 18 3 34 
1 31 3 3 17 33 4 4 28 34 14 26 14 41 1 12 15 15 30 41 2 
6 3 26 14 34 13 20 4 43 12 17 1 3 26 40 5 10 22 37 3 3 32
32 9 14 12 19 6 19 26 30 5 18 6 31 3 4 1 1 5 37 25 29 4 49
3 19 37 49 4 11 46 48 16 45 15 36 12 29 13 33 10 15 2 7 37 
45 35 36 3 50 9 10 31 49 17 28 40 42 23 37 31 42 1 37 1 2 2
4 6 9 20 50 5 7 14 50 10 18 28 28 28 36 20 33 23 31 13 43
1 2 13 20 5 10 21 45