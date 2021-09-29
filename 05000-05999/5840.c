#include <stdio.h>
#define INF 1012345678
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 50000)개의 수로 이루어진 수열이 주어진다. 이 수열에서 번호가 K(K < N) 이하로 차이 나는 같은 수가 있을 때,
이 수를 혼잡하다고 할 때, 수열에서 혼잡한 가장 큰 수를 구한다. 없다면 -1을 출력한다.
수열의 수들은 0 이상 10^6 이하의 정수이다.

해결 방법 : 각 수가 마지막으로 등장한 위치를 배열에 저장한다. 주어진 수의 위치와 K 이하로 차이가 나고 결괏값보다
큰 수라면 결괏값을 갱신한다.

주요 알고리즘 : 구현?

출처 : USACO 2013M B2번
*/

int breed[1048576];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("proximity.in", "r");
        fo = fopen("proximity.out", "w");
    }
    int n, k, x, r = -1;
    scanf("%d %d", &n, &k);
    for (int i = 0; i <= 1000000; i++) breed[i] = -INF;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (i - breed[x] <= k && x > r) r = x;
        breed[x] = i;
    }
    printf("%d", r);
    return 0;
}