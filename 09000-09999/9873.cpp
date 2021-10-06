#include <stdio.h>
#include <algorithm>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)
using namespace std;

/*
문제 : N(N <= 1000)개의 서로 다른 자연수가 주어질 때, 조건을 만족하는 세 자연수 (X, Y, Z)의 쌍을 구한다.
X < Y < Z이며 Y - X <= Z - Y <= (Y - X) * 2를 만족해야 한다.

해결 방법 : 먼저, 주어진 수들을 정렬한다. 그 다음, X와 Y의 모든 경우에 대해 만족하는 Z의 개수를 이분 탐색을 이용해 구한다.
upper_bound와 lower_bound 함수를 사용하는 것이 좋다.

주요 알고리즘 : 이분 탐색, 정렬

출처 : USACO 2013D B2번
*/

long long cow[1024];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("baseball.in", "r");
        fo = fopen("baseball.out", "w");
    }
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &cow[i]);
    }
    sort(cow, cow + n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            r += upper_bound(cow + j + 1, cow + n, cow[j] * 3 - cow[i] * 2) - lower_bound(cow + j + 1, cow + n, cow[j] * 2 - cow[i]);
        }
    }
    printf("%d", r);
    return 0;
}