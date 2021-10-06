#include <stdio.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 1000)개의 지형 높이가 주어질 때, 지형의 최대 높이와 최소 높이 차이를 17 이하로 하려고 할 때의
최소 비용을 구한다. 지형의 높이를 바꿀 때의 비용은 (원래 높이와의 차이)^2이다. 각 지형의 높이는 0 이상 100 이하의 정수이다.

해결 방법 : 각 지형의 높이 영역이 매우 작기 때문에 모든 가능한 높이에 대해서 비용을 계산하고 가장 작은 것을 고르면 된다.

주요 알고리즘 : 브루트 포스

출처 : USACO 2014J B1번
*/

int elev[1024];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("skidesign.in", "r");
        fo = fopen("skidesign.out", "w");
    }
    int n, r = INF, t = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &elev[i]);
    }
    for (int e = 0; e <= 83; e++) {
        t = 0;
        for (int i = 0; i < n; i++) {
            if (elev[i] < e) t += (e - elev[i]) * (e - elev[i]);
            else if (elev[i] > e + 17) t += (elev[i] - e - 17) * (elev[i] - e - 17);
        }
        if (t < r) r = t;
    }
    printf("%d", r);
    return 0;
}