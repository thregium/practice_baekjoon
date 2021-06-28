#include <stdio.h>

/*
문제 : 프로그램을 병렬로 개발하는데 드는 추가 작업시간과, 병렬로 개발할때의 프로그램 작업시간, 병렬로 개발하지 않을 때의 작업시간이 주어지고,
작업 횟수가 주어질 때, 병렬로 개발하는 것과 개발하지 않는 것 중 어느 쪽이 더 이득(작업시간이 적은)인지 구한다.

해결 방법 : 병렬화할 때의 이득은 프로그램 작업 횟수 * (병렬 - 직렬) - 추가 작업시간이다. 이 값이 0보다 크면 병렬화하는 것이 좋고,
0이면 상관없고, 0보다 작으면 병렬화하지 않는 것이 좋다.

주요 알고리즘 : 수학

출처 : IDI 2008 C번
*/

int main(void) {
    int t, d, n, s, p;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d %d", &d, &n, &s, &p);
        if (n * (s - p) - d > 0) printf("parallelize\n");
        else if (n * (s - p) - d == 0) printf("does not matter\n");
        else printf("do not parallelize\n");
    }
    return 0;
}