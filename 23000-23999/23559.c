#include <stdio.h>
#include <stdlib.h>

/*
문제 : X원의 예산으로 N(N <= 100000)일동안 먹을 식단을 준비한다.
각 날의 식단은 1000원짜리와 5000원짜리의 2가지 종류가 있다.
각 날의 식단별 맛(<= 10000)이 주어질 때, 주어진 예산으로 먹을 수 있는 식단의 맛 합을 구한다.

해결 방법 : 우선 1000원짜리로 전부 선택해 둔다. 그리고 두 식단의 맛의 차이를 배열에 넣고
내림차순으로 정렬한다. 그 다음 남는 돈으로 앞에서부터 맛이 좋아지는 가능한 모든 날의 식단을
5000원짜리로 바꾼 다음 답을 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : 제주대 2021 A번
*/

int bonus[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, x, y, r = 0;
    scanf("%d %d", &n, &x);
    x -= 1000 * n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &bonus[i], &y);
        r += y;
        bonus[i] -= y;
    }
    qsort(bonus, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (x >= 4000 && bonus[i] > 0) {
            x -= 4000;
            r += bonus[i];
        }
    }
    printf("%d", r);
    return 0;
}