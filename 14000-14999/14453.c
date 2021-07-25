#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100000)개의 가위바위보 순서를 미리 알 때, 낼 것을 중간에 한 번만 바꾸어 가장 많이 이기는 방법의 승리 수를 구한다.

해결 방법 : 왼쪽과 오른쪽에서부터 각각 각 패의 누적 합을 구한다. 그 다음으로는 모든 지점에 대해 해당 지점 왼쪽과
해당 지점 오른쪽에서 각각의 패를 내서 이기는 횟수가 가장 많은 것을 고르면 된다.

주요 알고리즘 : 누적 합

출처 : USACO 2017J S2번
*/

int hps[103000], suml[103000][3], sumr[103000][3];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("hps.in", "r");
        fo = fopen("hps.out", "w");
    }
    int n, best = 0;
    char c;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &c);
        if (c == 'H') hps[i] = 0;
        else if (c == 'P') hps[i] = 1;
        else if (c == 'S') hps[i] = 2;
        for (int j = 0; j < 3; j++) suml[i][j] = suml[i - 1][j] + (j == hps[i]);
    }
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < 3; j++) sumr[i][j] = sumr[i + 1][j] + (j == hps[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (suml[i - 1][j] + sumr[i][k] > best) best = suml[i - 1][j] + sumr[i][k];
            }
        }
    }
    printf("%d", best);
    return 0;
}