#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100)개의 수로 이루어진 배열에서 A1 - A2 구간을 뒤집고, B1 - B2 구간을 뒤집는 것을 K(K <= 10^9)회 반복한 후 배열의 모습을 출력한다.

해결 방법 : 배열에서 해당 구간을 뒤집은 다음, 1 - N번째 수가 이동한 위치를 저장해 놓는다. 그 후 희소 배열을 이용하여
구간을 2^N회 뒤집은 상태의 이동 위치들을 저장하고, 각 위치에 대해 K회 뒤집은 상태의 이동 위치들을 각각 확인하면 도니다.

주요 알고리즘 : 자료구조, 희소 배열

출처 : USACO 2020F B3번
*/

int a[128], mv[32][128];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("swap.in", "r");
        fo = fopen("swap.out", "w");
    }
    int n, k, a1, a2, b1, b2, x;
    scanf("%d %d%d %d%d %d", &n, &k, &a1, &a2, &b1, &b2);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    for (int j = a1, k = a2; j < k; j++, k--) {
        swap(&a[j - 1], &a[k - 1]);
    }
    for (int j = b1, k = b2; j < k; j++, k--) {
        swap(&a[j - 1], &a[k - 1]);
    }
    for (int i = 0; i < n; i++) mv[0][i] = a[i] - 1;
    for (int i = 1; i <= 30; i++) {
        for (int j = 0; j < n; j++) {
            mv[i][j] = mv[i - 1][mv[i - 1][j]];
        }
    }
    for (int i = 0; i < n; i++) {
        x = i;
        for (int j = 0; j <= 30; j++) {
            if (k & (1 << j)) {
                x = mv[j][x];
            }
        }
        printf("%d\n", x + 1);
    }
    return 0;
}