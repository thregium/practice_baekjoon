#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)명의 사람이 있는 위치와 M(M <= 100)그루의 나무가 있는 위치가 일직선상의
자연수 값(<= 1000)으로 주어진다. 사람 또는 나무의 위치끼리는 중복되지 않는다.
사람은 가장 가까운 나무 가운데 가장 왼쪽에 있는 나무로 이동한다. 각 나무는 1명의 사람만 차지할 수 있다면
나무를 차지할 수 없는 사람의 수를 구한다.

해결 방법 : 각 사람이 차지하는 나무들을 배열에 저장한 다음, 정렬하고 중복되지 않는 나무의 수를 세면 된다.

주요 알고리즘 : 구현, 브루트 포스, 정렬

출처 : VTH 2019 E번
*/

int p[128], t[128], sel[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < n; i++) {
        sel[i] = 103000;
        for (int j = 0; j < m; j++) {
            if (abs(p[i] - t[j]) < abs(p[i] - sel[i]) ||
                (abs(p[i] - t[j]) == abs(p[i] - sel[i]) && t[j] < sel[i])) sel[i] = t[j];
        }
    }
    qsort(sel, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (sel[i] != sel[i + 1]) r++;
    }
    printf("%d", n - r);
    return 0;
}