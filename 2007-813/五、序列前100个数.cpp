#include<stdio.h>
#include<queue>
using namespace std;
int main() {
	int count = 0;//��������
	priority_queue<int,vector<int>, greater<int> >myqueue;//���ȶ��У�С����
	myqueue.push(1);
	while (count != 100) {
		int cur = myqueue.top();
		myqueue.pop();
		printf("%d ", cur);
		count++;
		myqueue.push(cur * 2);//�������
		if (cur%3==0 && cur %2==0) { continue; }//���⹫�����ظ����
		myqueue.push(cur * 3);//�������
	}
}