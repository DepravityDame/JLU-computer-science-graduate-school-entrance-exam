#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>

double dist  (int x1, int y1, int x2, int y2) {
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));//计算两点间距离
}


double area(int x1, int y1, int x2, int y2, int x3, int y3) {
	double a = dist(x1, y1, x2, y2);
	double b = dist(x1, y1, x3, y3);
	double c = dist(x2, y2, x3, y3);
	double s = (a + b + c) / 2;
	return(sqrt(s*(s - a)*(s - b)*(s - c)));//计算三角形面积
}


int main() {
	int x[100] = {
		39,-11,76,6,3,-37,34,67,-47,57,36,41,46,89,4,44,-25,18,44,56,-47,-34,49,0,-39,-5,-45,-1,-20,31,59,-24,84,-37,-3,2,-22,-21,-47,50,-49,28,83,29,99,67,58,48,18,-23,-44,56,23,-4,57,-2,99,86,-47,-43,-27,79,64,29,-37,-23,81,-6,38,95,36,60,7,91,23,-5,59,98,84,45,58,73,75,-22,56,74,13,15,-5,-31,-13,77,87,43,-5,-47,90,70,-43,68
	};
	int y[100] = {
		14,83,52,81,92,85,16,-3,33,-48,79,25,41,-16,-7,58,-33,63,46,22,33,-15,-23,57,26,-27,72,5,-17,81,74,89,12,-21,-32,52,-18,71,92,39,84,82,-50,37,-11,-11,-8,87,42,63,-4,84,9,97,49,-41,-17,-18,80,72,39,58,30,79,48,-13,100,13,-13,-7,4,69,28,-31,-20,96,33,-4,-31,-48,32,52,71,55,75,28,21,-3,99,95,28,63,28,34,49,-42,19,19,36,45
	};
	double max=0.0;
	for (int i = 0; i < 98; i++) {//循环选点
		for (int j = i+1; j < 99; j++) {
			for (int k = i+1; k < 100; k++) {
				double a = area(x[i], y[i], x[j], y[j], x[k], y[k]);//计算面积
				if (a > max) {//对比当前面积与现有最大值面积
					max = a;//储存最大值
				}
			}
		}
	}
	printf("%lf", max);//输出最大值
}