#include <stdio.h>
#include <stdlib.h>

/*
문제 : 4개의 자연수 A, B, C, D(A, B, C, D <= 10^9)가 주어질 때, 두개씩 짝지어 만든 분수의 합이 가장 작을 때의 순서를 출력한다.

해결 방법 : 큰 2개의 수가 분모로, 작은 2개의 수가 분자로 가는 것이 좋음을 알 수 있다. 또한, 각 그룹에 대해 더 큰 수끼리,
더 작은 수끼리 짝지어 분수를 만드는 것이 통분하였을 때 분자가 작아지기 때문에 그렇게 하는 것이 가장 분수의 합이 작아진다.
따라서, 정렬한 후 가장 작은 것 / 2번째로 큰 것 + 2번째로 작은 것 / 가장 큰 것을 하면 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 수학, 정렬

출처 : ROI 2017H K번
*/

int a[4];

int cmp1(const void* a, const void* b) {
	int ai = *(int*)a;
	int bi = *(int*)b;
	return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
	qsort(a, 4, sizeof(int), cmp1);
	printf("%d %d %d %d", a[0], a[2], a[1], a[3]);
    return 0;
}