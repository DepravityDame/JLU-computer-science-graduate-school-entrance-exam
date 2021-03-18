#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct Node {
	int data;
	Node*next;
}*List;

List head = (List)malloc(sizeof(Node));
int revk(List head,int k) {//��������
	List fast;//��ָ��
	List slow;//��ָ��
	fast = slow = head;//����ָ��ָ��ͷ�ڵ�
	for (int i = 0; i < k&&fast!=NULL; i++) {//��ָ������k��
		fast = fast->next;
	}
	if (fast == NULL) {//�����ָ���ߵ�NULL�ˣ�˵��Ԫ�ز���k��������0
		printf("0\n");
		return 0;
	}
	while (fast != NULL) {//����ָ��ͬʱ�ƶ���fast��nullʱ����ָ��ָ������K��Ԫ��
		slow = slow->next;
		fast = fast->next;
	}
	printf("%d", slow->data); return 1;//�ҵ��˵�����K��Ԫ�أ����DATA��������1
}

void build() {
	List p1 = head;
	const int n = 10;
	int a[n] = { 4,7,2,5,8,6,9,4,11,3 };
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

}


int main() {

	build();
	print(head);
	printf("\n");
	int k;
	while (scanf("%d", &k) != EOF) {
		if (revk(head, k))printf("YES\n");
		else return printf("NO\n");
	}
	
}