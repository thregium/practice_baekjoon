#include <stdio.h>

/*
문제 : M(M <= 50)가지 종류의 조약돌이 있고, 각 조약돌별로 50개 이하로 개수가 주어진다.
이때, 모든 조약돌 가운데 K개를 뽑았을 때 모든 조약돌이 같은 종류일 확률을 구한다. 단, K는 전체 개수 이하로 주어진다.

해결 방법 : 각 조약돌에 대해 K개를 모두 해당 조약돌에서 뽑는 경우의 수의 합을 구하고, 전체 조약돌에 대해서도
경우의 수를 구한다. 둘을 나누면 된다. 이때, 수가 커질 수 있으므로 실수형을 써야 한다.

주요 알고리즘 : 수학, 조합론, 확률론
*/

int peb[64];

int main(void) {
    int m, k, s = 0;
    double c = 0, ct, tot = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &peb[i]);
        s += peb[i];
    }
    scanf("%d", &k);
    for (int i = 0; i < m; i++) {
        if (k > peb[i]) continue;
        ct = 1;
        for (int j = 0; j < k; j++) {
            ct *= peb[i] - j;
            ct /= j + 1;
        }
        c += ct;
    }
    tot = 1;
    for (int i = 0; i < k; i++) {
        tot *= s - i;
        tot /= i + 1;
    }
    printf("%.16f", c / tot);
    return 0;
}