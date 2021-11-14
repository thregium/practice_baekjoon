#include <stdio.h>

/*
문제 : x(-100 <= x <= 100) < (- * N(0 <= N <= 10))가 주어질 때, 이 연산자를 while문에 넣을 때 출력되는 수의 개수를 구한다.
컴파일이 되지 않는다면 ERROR, 무한정 출력된다면 INFINITE를 출력한다.

해결 방법 : -가 0개와 1개, 2개 이상의 짝수, 3개 이상의 홀수일 때로 각각 나누어 생각한다.
0개와 1개일 때에는 일반적인 for문처럼 처리하면 되고, 3개 이상의 홀수인 경우에는 ERROR를 출력한다.
짝수인 경우에는 x가 음수일 때에는 항상 0이고, 그 외에는 (x - 1) / (n / 2)를 계산하여 구할 수 있다.

주요 알고리즘 : 애드 혹, 케이스 워크

출처 : 서울대 2018D2 C번
*/

int main(void) {
	int x, n;
	scanf("%d %d", &x, &n);

	if (n == 0) printf("%s", x < 0 ? "INFINITE" : "0");
	else if (n == 1) printf("%s", x < 0 ? "INFINITE" : "0");
	else if (n & 1) printf("ERROR");
	else if (x <= 0) printf("0");
	else printf("%d", (x - 1) / (n >> 1));

}