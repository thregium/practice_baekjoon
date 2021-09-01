#include <stdio.h>
#include <stdlib.h>

/*
문제 : 종이를 가로선과 세로선으로 자르는 위치가 주어질 때, 가장 큰 종이의 크기를 구한다.

해결 방법 : 각 가로와 세로에서 가장 넓은 구간을 구하고, 그 값을 곱하면 된다.
가장 넓은 구간은 자르는 위치를 정렬한 다음, 위치들 사이 간격이 가장 큰 것을 고르면 구할 수 있다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : 정올 2001 초1번
*/

int vers[256], hors[256];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int w, h, n, horn = 1, vern = 1, d, p, horr = 0, verr = 0;
    scanf("%d %d", &w, &h);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &d, &p);
        if (d) vers[vern++] = p;
        else hors[horn++] = p;
    }
    hors[horn++] = h;
    vers[vern++] = w;
    qsort(hors, horn, sizeof(int), cmp1);
    qsort(vers, vern, sizeof(int), cmp1);
    for (int i = 1; i < horn; i++) {
        if (hors[i] - hors[i - 1] > horr) horr = hors[i] - hors[i - 1];
    }
    for (int i = 1; i < vern; i++) {
        if (vers[i] - vers[i - 1] > verr) verr = vers[i] - vers[i - 1];
    }
    printf("%d", horr * verr);
    return 0;
}