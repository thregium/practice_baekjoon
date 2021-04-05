#include <stdio.h>

/*
문제 : N(N <= 1000) 이하에서 어떤 자연수의 각 자릿수가 등차수열을 이루는 수의 갯수를 구한다.

해결 방법 : N의 크기가 충분히 작기 때문에 N 이하의 각 숫자가 모두 등차수열을 이루는지 전부 확인해본다.

주요 알고리즘 : 브루트 포스, 구현, 수학
*/

int han(int a) {
    int t[10] = {0, };
    int r = 1, j = 0, d;
    for(int i = a; i > 0; i /= 10) {
        t[j] = i % 10;
        j++;
    }
    d = t[1] - t[0];
    for(int i = 1; i < j; i++) {
        if(t[i] - t[i - 1] != d) r = 0; //등차수열을 이루지 않는 경우
    }
    return r;
}

int main() {
	 int n, s = 0;
	 scanf("%d", &n);
	 for(int i = 1; i <= n; i++) {
	     if(han(i)) s++;
	 }
	 printf("%d", s);
	 return 0;
}