#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 100000)개의 그림들이 일렬로 놓여있고, 각 그림의 위치는 Xi(Xi <= 10^9)이다. 각 그림들은 각각의 가치가 있는데,
각 그림의 가치는 Vi(Vi <= 10^9)이다. 이때, 그림들을 M개만 남겨두면서 각 그림들이 최소 D미터 떨어지도록 하고 싶다.
이때의 그림들중 최소 가치를 최대로 할 때, 최소 가치를 구한다.

해결 방법 : 그림들을 위치 순으로 정렬하고, 그림의 가치들도 정렬해둔다. 그 다음, 가치가 X번째인 그림 이상의 그림들만 사용하여
모든 그림들을 배치할 수 있는지 여부를 통해 매개 변수 탐색을 진행한다.
해당 여부는 배치 가능한 그림이 나올 때 마다 전부 배치해서 M개를 놓을 수 있는지를 통해 확인할 수 있다.

주요 알고리즘 : 그리디 알고리즘, 이분 탐색

출처 : JOIG 2021 4번
*/

int pics[103000][2], vals[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int getres(int n, int m, int d, int x) {
    int p = 0, l = -INF;
    for (int i = 0; i < n; i++) {
        if (pics[i][1] < vals[x]) continue;
        if (pics[i][0] - l >= d) {
            l = pics[i][0];
            p++;
        }
    }
    return (p >= m);
}

int main(void) {
    int n, m, d, l, h;
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pics[i][0], &pics[i][1]);
        vals[i] = pics[i][1];
    }
    qsort(pics, n, sizeof(int) * 2, cmp1);
    qsort(vals, n, sizeof(int), cmp1);
    l = -1, h = n - 1;
    while (l < h) {
        if (getres(n, m, d, (l + h + 1) >> 1)) l = ((l + h + 1) >> 1);
        else h = ((l + h + 1) >> 1) - 1;
    }
    if (l < 0) printf("-1");
    else printf("%d", vals[l]);
    return 0;
}