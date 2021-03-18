#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
using namespace std;

/*void sort(int a[]) {//额外数组法
	int *ans = new int[100];
	int k = 0;
	for (int i = 0; i < 100; i++) {//将所有非0元素存至新数组
		if (a[i] != 0) {
			ans[k++] = a[i];
		}
	}
	for (int i = k; i < 100; i++) {//在新数组补齐0元素
		ans[i] = 0;
	}
	for (int i = 0; i < 100; i++) {//输出旧数组
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i < 100; i++) {//输出新数组
		printf("%d ", ans[i]);
	}
}
*/

void sort(int a[]) {//不使用额外空间法
	int i = 0;
	while (i < 100) {
		while (a[i] != 0) { i++; }//寻找第一个0元素
		for (int j = i; j < 99; j++) {//后边元素前移一位
			a[j] = a[j + 1];
		}
		a[99] = 0;//0放到最后一位
		i++;
	}
	for (int i = 0; i < 100; i++) {
		printf("%d ", a[i]);
	}

}


int main() {//test data
	int a[100] = { -60,26,67,76,-6,-91,-82,-49,-53,-59,-96,-86,40,-43,85,70,-31,31,-13,-34,-58,-31,-56,58,74,-19,-94,81,-37,-65,-65,-50,-71,-11,0,30,-89,-65,91,87,-19,-78,-4,15,26,-71,-80,-5,-58,36,31,5,7,-35,-55,-23,51,85,10,-25,-73,60,91,-6,-76,92,85,0,-78,-67,0,50,-80,51,19,14,0,81,-71,-78,-56,51,-16,18,24,-14,89,-51,0,91,64,42,7,44,8,-38,62,2,70,38, };
	sort(a);
}