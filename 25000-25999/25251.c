#include <stdio.h>

/*
문제 : N * M(N, M <= 2000) 크기의 지도에 'C'와 '_'이 있다. 최단 경로로 맨 왼쪽 위에서
맨 오른쪽 아래로 격자 단위 이동을 반복할 때, 모든 'C'가 있는 칸을 지나기 위해
이동해야 하는 최소 횟수를 구한다.

해결 방법 : 가장 위쪽 부분을 긁으면서 가능한 많은 'C'를 갖고 오는 것을 반복한다.
가장 위쪽 부분의 위치는 투 포인터 알고리즘을 이용해 구할 수 있다.

주요 알고리즘 : 그리디 알고리즘, 투 포인터

출처 : GCPC 2021 G번
*/

char c[2048][2048];
int hi[2048];

int main(void) {
    int n, m, res = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", c[i]);
    }
    for (int i = 0; i < m; i++) {
        hi[i] = n;
        for (int j = n - 1; j >= 0; j--) {
            if (c[j][i] == 'C') hi[i] = j;
        }
    }
    hi[m] = n;
    for (int i = m - 1; i >= 0; i--) {
        if (hi[i] > hi[i + 1]) hi[i] = hi[i + 1];
    }
    while (hi[0] < n) {
        for (int i = 0; i < m; i++) {
            for (int j = hi[i]; j <= hi[i + 1]; j++) c[j][i] = '_';
        }
        for (int i = 0; i < m; i++) {
            for (int j = hi[i]; j < n; j++) {
                if (c[j][i] == '_') hi[i] = j + 1;
                else break;
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            if (hi[i] > hi[i + 1]) hi[i] = hi[i + 1];
        }
        res++;
    }
    printf("%d", res);
    return 0;
}