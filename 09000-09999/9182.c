#include <stdio.h>

/*
문제 : 바이오리듬의 세 주기 최고점이 되었던 날이 각각 주어질 때, D일 이후로 세 주기가 동시에 최고점이 되기까지
걸리는 날 수를 구한다.

해결 방법 : 각 주기는 각각 23, 28, 33으로 나눈 나머지를 취하더라도 값이 같게 된다. 따라서, 각 수로 나눈 나머지가
같아지는 날까지 반복하며 세 주기가 동시에 최고점이 되는 날을 찾아나갈 수 있다.

주요 알고리즘 : 수학, 정수론, 브루트 포스

출처 : PacNW 1999 A번 // ECRC 1999 F번
*/

int main(void) {
    int p, e, i, d;
    for (int tt = 1;; tt++) {
        scanf("%d %d %d %d", &p, &e, &i, &d);
        if (p < 0) break;
        p %= 23;
        e %= 28;
        i %= 33;
        for (int j = d + 1;; j++) {
            if (j % 23 == p && j % 28 == e && j % 33 == i) {
                printf("Case %d: the next triple peak occurs in %d days.\n", tt, j - d);
                break;
            }
        }
    }
    return 0;
}