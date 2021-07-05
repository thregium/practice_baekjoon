#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10000)개의 수를 원형으로 배치할 때, 인접한 두 수의 차를 가장 적게 한다면 그 차는 얼마인지 구한다.

해결 방법 : 그렇게 배치하는 방법은 양 끝을 가장 작은 수로 맞춘 뒤, 안쪽으로 가며 점점 큰 수를 배치하는 방식이다.
이를 배열로 표현하면 정렬된 배열에서 두 칸씩 이동하는 것과 같음을 알 수 있고, 따라서 정렬된 배열에서 2칸 차이인 수의 차 중
가장 큰 것을 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : Daejeon 2015 E번
*/

int l[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &l[i]);
        }
        qsort(l, n, sizeof(int), cmp1);
        r = 0;
        for (int i = 2; i < n; i++) {
            if (l[i] - l[i - 2] > r) r = l[i] - l[i - 2];
        }
        printf("%d\n", r);
    }
    return 0;
}