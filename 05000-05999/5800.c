#include <stdio.h>
#include <stdlib.h>

/*
문제 : 주어진 K(K <= 50)개의 정수에 대해 최댓값과 최솟값, 정렬시 인접한 두 수 중 가장 차이가 큰 두 수의 차이를 구한다.
각 수는 0 이상 100 이하이다.

해결 방법 : 각각의 값을 입력이 어떻게 되더라도 항상 갱신이 가능한 수로 초기화시켜둔 다음 갱신해야 할 때 마다
갱신시킨 다음 최종 결과를 출력하면 된다.

주요 알고리즘 : 구현, 정렬

출처 : SouthP 2011 A번
*/

int a[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int k, n, mx, mn, lg;
    scanf("%d", &k);
    for (int kk = 1; kk <= k; kk++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        mx = -1;
        mn = 128;
        lg = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] > mx) mx = a[i];
            if (a[i] < mn) mn = a[i];
            if (i > 0 && a[i] - a[i - 1] > lg) lg = a[i] - a[i - 1];
        }
        printf("Class %d\n", kk);
        printf("Max %d, Min %d, Largest gap %d\n", mx, mn, lg);
    }
    return 0;
}