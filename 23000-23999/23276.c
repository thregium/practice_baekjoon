#include <stdio.h>

/*
문제 : K(K < 100)쌍의 매미들이 동시에 나온 해(1800 <=, <= 2021)와
두 매미가 나오는 주기(연 단위, < 100, 자연수)가 주어지면, 주어진 쌍들 가운데 하나라도 나오게 되는 첫 해를 구한다.
이 해는 최소 2022년 이후이다.

해결 방법 : 매미가 나오는 주기가 비교적 짧기 때문에 모든 해마다 각 매미가 동시에 나오는 쌍이 있는지 확인해볼 수 있다.
이는 모듈로를 통해 간단히 구하는 것이 가능하다.

주요 알고리즘 : 수학, 시뮬레이션

출처 : NCPC 2021 L번
*/

int p[128][3];

int main(void) {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &p[i][0], &p[i][1], &p[i][2]);
    }
    for (int i = 2022;; i++) {
        for (int j = 0; j < k; j++) {
            if ((i - p[j][0]) % p[j][1] == 0 && (i - p[j][0]) % p[j][2] == 0) {
                printf("%d", i);
                return 0;
            }
        }
    }
    return 0;
}