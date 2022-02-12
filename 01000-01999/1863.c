#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10000)번의 스카이라인 높이 변화가 주어질 때, 건물의 최소 개수를 구한다.
스카이라인의 높이는 0 이상 500000 이하며, 높이 0은 건물이 없는 상태이다.

해결 방법 : 스택을 통해 현재 스카이라인을 이루는 건물의 높이들을 저장한다.
더 낮은 건물이 나오면 스택에서 이전에 있던 높이이면 해당 건물의 연장으로 보고, 없던 높이이며
0이 아니라면 새로운 건물로 본다. 이를 반복하여 건물의 개수를 세면 된다.

주요 알고리즘 : 자료 구조, 스택

출처 : USACO 2005N S6번
*/

int stack[51200], ht[51200][2];
int top = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ht[i][0], &ht[i][1]);
    }
    qsort(ht, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        while (top > 0 && stack[top - 1] > ht[i][1]) top--;
        if (top <= 0 || stack[top - 1] < ht[i][1]) {
            if (ht[i][1] == 0) continue;
            stack[top++] = ht[i][1];
            r++;
        }
    }
    printf("%d", r);
    return 0;
}