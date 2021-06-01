#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1024)개의 먹이들의 높이와, 뱀의 초기 높이 L이 주어진다. 뱀은 현재 높이 이하의 먹이를 먹을 수 있고,
먹이 하나를 먹을 때 마다 높이가 1씩 늘어난다면 최대로 컸을 때의 높이를 구한다.

해결 방법 : 가장 낮은 곳에 있는 먹이부터 순서대로 먹다가 가장 낮은 높이에 있는 먹이를 먹을 수 없다면 그때의 높이를 출력하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : 경북대 2018 뱀번
*/

int h[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, l;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    qsort(h, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (h[i] > l) break;
        else l++;
    }
    printf("%d", l);
    return 0;
}