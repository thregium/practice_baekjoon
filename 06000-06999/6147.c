#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 20000)마리의 소들의 키가 각각 주어진다. 이때, B(B <= 2 * 10^9) 이상의 높이가 되기 위해 필요한
소가 최소 몇 마리인지 구한다.

해결 방법 : 가장 큰 소부터 차례로 쌓는 것이 가장 좋음을 쉽게 알 수 있다. 키 순으로 정렬한 다음 가장 큰 소부터 쌓아나가면서
B 이상의 높이가 될 때까지 쌓은 소의 마릿수를 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : USACO 2007D B1번
*/

int heights[20480];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, b, s = 0;
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
    qsort(heights, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        s += heights[i];
        if (s >= b) {
            printf("%d", i + 1);
            break;
        }
    }
    if (s < b) return 1;
    return 0;
}