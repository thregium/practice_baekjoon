#include <stdio.h>

/*
문제 : B(B <= 50)개의 버스와 S(S <= 50)개의 정류장이 있을 때, M번 정류장에서 버스 1개를 타고
도달 가능한 정류장의 개수를 구한다. 단, M번 정류장은 제외한다.

해결 방법 : M번 정류장에 서는 버스에 대해 그러한 버스 가운데 하나 이상이 서는 모든 정류장을 기록한다.
그 다음, M번을 제외한 정류장에서 기록된 정류장의 개수를 세면 된다.

주요 알고리즘 : 구현?

출처 : UKIEPC 2018 B번
*/

char bus[64][64], chk[64];

int main(void) {
    int m, b, s, r = 0;
    scanf("%d %d %d", &m, &b, &s);
    for (int i = 0; i < b; i++) {
        scanf("%s", bus[i]);
        if (bus[i][m - 1] == '0') continue;
        for (int j = 0; j < s; j++) {
            if (bus[i][j] == '1') chk[j] = 1;
        }
    }
    for (int i = 0; i < s; i++) {
        if (i == m - 1) continue;
        r += chk[i];
    }
    printf("%d", r);
    return 0;
}