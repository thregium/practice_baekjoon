#include <stdio.h>

/*
문제 : N(N <= 50)명의 친구 관계가 주어질 때, (친구와 친구의 친구의 수의 합)(2-친구)이 가장 많은 사람의 2-친구 수를 구한다.
자기 자신은 2-친구가 아니고, A와 B가 친구이면 B와 A도 친구이다.

해결 방법 : 각 사람의 친구들을 전부 확인하고, 각 친구에 대해 그 친구의 친구 가운데 자기 자신을 제외한 모든 사람들을 확인한다.
이를 모든 사람에 대해 반복하고, 2-친구 수를 확인해 가장 많은 값을 구하면 된다.

주요 알고리즘 : 그래프 이론, 브루트 포스
*/

char f[64][64];
int is2[64][64], cnt[64];

int main(void) {
    int n, bcnt = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", f[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (f[i][j] == 'N') continue;
            is2[i][j] = 1;
            for (int k = 0; k < n; k++) {
                if (f[j][k] == 'N' || k == i) continue;
                is2[i][k] = 1;
            }
        }
        for (int j = 0; j < n; j++) {
            cnt[i] += is2[i][j];
        }
        if (cnt[i] > bcnt) bcnt = cnt[i];
    }
    printf("%d", bcnt);
    return 0;
}