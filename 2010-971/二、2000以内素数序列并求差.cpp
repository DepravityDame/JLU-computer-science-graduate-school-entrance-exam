#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
using namespace std;
bool isprime(int n) {
	if (n < 2)return false;
	for (int i = 2; i <= n / 2; i++) {
		if (n%i == 0)return false;
	}
	return true;
}


int main() {
	int arr[1000];//��������
	int ans[1000];//�������
	bool prime[2001];//�Ƿ����������
	int k = 0;
	memset(prime, true, sizeof(prime));
	for (int i = 2; i <= 2000; i++) {//����ɸ��������
		if (prime[i]) {
			arr[k++] = i;
			for (int j = i * i; j <=2000; j += i) {//ĳ�������������ı�������������
				prime[j] = false;//����������Ϊflase
			}
		}
	}
	for (int i = 0; i < k-1; i++) {//���������
		ans[i] = arr[i + 1] - arr[i];
		printf("%d ", ans[i]);
	}

}