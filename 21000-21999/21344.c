#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 정수가 주어질 때, 이 수들을 인접한 두 수의 차이가 줄어들지 않는 순서로 배치한다.

해결 방법 : 수들을 정렬한 후, 가운데 위치부터 지그재그 순서로 바깥쪽으로 차례로 출력해주면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : NWERC 2020 H번
*/

int t[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, s, d = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    qsort(t, n, sizeof(int), cmp1);
    s = ((n - 1) >> 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", t[s]);
        if (d & 1) s += d;
        else s -= d;
        d++;
    }
    return 0;
}