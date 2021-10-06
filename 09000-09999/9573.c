#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 1부터 N(N <= 100)까지의 자연수로 이루어진 다이얼이 3개 있는 금고가 있다. 금고에는 두 가지 비밀번호가 있는데,
두 가지 비밀번호 중 하나의 비밀번호와 모든 다이얼의 차이가 2 이하인 경우 금고가 열린다.
금고를 여는 방법의 가짓수를 구한다. N번과 1번은 연결되어 있다.

해결 방법 : N이 충분히 작으므로 N^3가지 경우를 전부 확인하며 금고가 열리는 경우를 전부 찾으면 된다.
두 비밀번호에 대해 각 수의 차이를 확인한다. 각 수의 차이는 N을 더한 값과 비교해보면 확인 가능하다.
모든 차이가 2 이하인 경우 금고가 열리는 경우이다.

주요 알고리즘 : 수학, 브루트 포스

출처 : USACO 2013N B1번
*/

int john[3], master[3];

int small(int a, int b) {
    return a < b ? a : b;
}

int getdiff(int n, int a, int b) {
    if (a > b) return small(abs(a - b), abs(b + n - a));
    else return small(abs(b - a), abs(a + n - b));
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("combo.in", "r");
        fo = fopen("combo.out", "w");
    }
    int n, r = 0;
    scanf("%d", &n);
    scanf("%d %d %d%d %d %d", &john[0], &john[1], &john[2], &master[0], &master[1], &master[2]);
    for (int i = 1; i <= n; i++) {
        if (getdiff(n, i, john[0]) > 2 && getdiff(n, i, master[0]) > 2) continue;
        for (int j = 1; j <= n; j++) {
            if (getdiff(n, j, john[1]) > 2 && getdiff(n, j, master[1]) > 2) continue;
            for (int k = 1; k <= n; k++) {
                if (getdiff(n, i, john[0]) <= 2 && getdiff(n, j, john[1]) <= 2 && getdiff(n, k, john[2]) <= 2) r++;
                else if (getdiff(n, i, master[0]) <= 2 && getdiff(n, j, master[1]) <= 2 && getdiff(n, k, master[2]) <= 2) r++;
            }
        }
    }
    printf("%d", r);
    return 0;
}