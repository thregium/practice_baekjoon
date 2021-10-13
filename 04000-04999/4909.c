#include <stdio.h>
#include <stdlib.h>

/*
문제 : 6명이 매긴 점수가 주어질 때, 최댓값과 최솟값을 뺀 평균을 출력한다. 점수는 0 이상 10 이하의 정수이다.
필요 없는 자리를 출력해서는 안 된다.

해결 방법 : 점수를 정렬한 다음, 2번째부터 5번째까지의 값의 합을 구하고 4로 나누어 정수 단위를 구한다.
소수 단위는 4로 나눈 나머지에 맞추어 구하면 된다.

주요 알고리즘 : 구현, 정렬, 사칙연산

출처 : Arab 2007 A번
*/

int a[6];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int s;
    while (1) {
        for (int i = 0; i < 6; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, 6, sizeof(int), cmp1);
        if (a[5] == 0) break;
        s = a[1] + a[2] + a[3] + a[4];
        printf("%d", s >> 2);
        if ((s & 3) == 0) printf("\n");
        else if ((s & 3) == 1) printf(".25\n");
        else if ((s & 3) == 2) printf(".5\n");
        else printf(".75\n");
    }
    return 0;
}