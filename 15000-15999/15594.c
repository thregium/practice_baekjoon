#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100)개의 수로 이루어진 수열에서 정렬되지 않은 수가 하나 있다. 이 수열을 정렬된 상태로 만들기 위해서 교환 연산이 최소 몇 회 필요한지 구한다.

해결 방법 : 정렬되지 않은 수는 그 수의 양쪽 수가 모두 그 수보다 작거나 모두 그 수보다 크다.
그런데, 수열에서 그러한 수는 2개가 존재하기 때문에 어느 것인지 알기 어렵지만, 최소 이동 횟수가 더 먼 것이 정렬되지 않은 수이기 때문에
두 경우 모두 시도해보면 된다. 최소 이동 횟수는 정렬되지 않은 수의 위치에서 원래 있어야 할 위치 사이에 있는 수의 개수와 같다.

주요 알고리즘 : 그리디 알고리즘, 애드 혹

출처 : USACO 2018J B3번
*/

int a[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("outofplace.in", "r");
        fo = fopen("outofplace.out", "w");
    }
    int n, x = 0, y = 0, c = 0, d = 0;
    scanf("%d", &n);
    a[n + 1] = 1234567;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) x = i;
        else if (a[i] < a[i - 1] && a[i] < a[i + 1]) y = i;
    }
    if (x) {
        for (int i = x + 1; a[i] < a[x]; i++) {
            if (a[i - 1] != a[i]) c++;
        }
    }
    if(y) {
        for (int i = y - 1; a[i] > a[y]; i--) {
            if (a[i + 1] != a[i]) d++;
        }
    }
    printf("%d", c > d ? c : d);
    return 0;
}