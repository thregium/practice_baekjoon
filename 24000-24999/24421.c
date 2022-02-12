#include <stdio.h>

/*
문제 : N(N <= 100)개의 자연수 A_i(< 1000)가 주어질 때, 차례로 서로 다른 i, j, k를 선택한 후
A_i * A_j = A_k가 되는 경우의 수를 구한다.

해결 방법 : 모든 i, j, k에 대해 그러한 경우들을 전부 시도해본 후 횟수를 구하면 된다.

주요 알고리즘 : 수학, 브루트 포스

출처 : JOIG 2022 2번
*/

int a[128];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i] * a[j] == a[k]) r++;
            }
        }
    }
    printf("%d", r);
    return 0;
}