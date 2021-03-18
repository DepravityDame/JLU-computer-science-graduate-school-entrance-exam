#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
using namespace std;
//��ע�Ͳ��ֽ�Ϊ�����ã�����ʱ����д��ֻд��������Ϳ���
typedef struct Node {//�ṹ�嶨��
	int data;
	Node *next;
}*List;
bool isprime(int n) {//�ж�����
	if (n < 2)return false;//���nС��2������false
	else {
		for (int i = 2; i <=n/2; i++) {//�ж��Ƿ��ܱ���1�ͱ���������
			if (n%i == 0) {
				return false;//�ܱ���������false
			}
		}
	}
	return true;//������������true
}

void del(List head) {//��������
	List ppre = head;//����pǰ��
	List p = head->next;//�����������ָ��p
	while (p != NULL) {//������û������βѭ��
		if (isprime(p->data)) {//�����ǰ�ڵ���������������ɾ��
			ppre->next = p->next;
			free(p);//�ͷŵ�ǰ�ڵ�
			p = ppre->next;//���µ�ǰ�ڵ�λ��
			continue;//����һ����ѭ��
		}
		ppre = p;//pǰ������
		p = p->next;//p����
	}
}
List head = (List)malloc(sizeof(Node));

void build() {
	List p1 = head;
	const int n = 10;
	int a[n] = { 4,7,2,5,8,6,9,12,11,3 };
	List p;
	for (int i = 0; i < n; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}

void print(List head) {
	List p = head->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	build();
	print(head);
	del(head);
	print(head);

}
