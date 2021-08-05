#include <stdio.h>

/*
문제 : N(N <= 25)명이 있는 줄이 있고, 각 그룹이 주어질 때, 줄의 맨 끝에 서면 몇 번째 그룹인지 구한다.

해결 방법 : 마지막 사람과 서로 다른 그룹에 속하는 경우 그룹의 수를 1 올린다.
마지막까지 확인한 후 그룹의 수에 1을 더하면 답이 된다.

주요 알고리즘 : 구현

출처 : COCI 17/18#3 1번
*/

int main(void) {
    int n, r = 1;
    char l = '\0', c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &c);
        if (c != l) {
            l = c;
            r++;
        }
    }
    printf("%d", r);
    return 0;
}