#include <stdio.h>

/*
문제 : N(N <= 40)마리의 동물이 있다. 이 동물들은 토끼 또는 고양이이다. 또한, 모든 동물의 크기는 다르다.
이때, 각 동물들에 대해 자신과 같은 종인 동물 중 자신보다 더 큰 동물의 수(<= 40, 음아정)가 주어지면
각 동물마다 종을 구별하는 경우의 수를 구한다. 불가능한 경우는 0이다.

해결 방법 : 가능한 경우를 생각해보면 0부터 각 수의 나온 횟수를 셌을 때 2 이하의 범위에서
단조 감소하는 경우만 된다는 것을 알 수 있다. 그렇지 않다면 0을 출력하면 된다.
가능할 때의 값은 2^(2의 개수 + 1)과 같다. 단, 1이 없는 경우에는 2^(2의 개수)와 같다.

주요 알고리즘 : 수학, 조합론, 케이스 워크
*/

int cnt[64];

int main(void) {
    int n, x, phase = 2, lo = -1, hi = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 0; i <= 40; i++) {
        if (cnt[i] > 2) phase = -1;
        else if (cnt[i] == 2) {
            if (phase != 2) phase = -1;
        }
        else if (cnt[i] == 1) {
            if (phase == 2) {
                phase = 1;
                lo = i + 1;
            }
            else if (phase == 0) phase = -1;
        }
        else {
            if (phase == 2) {
                phase = 0;
                lo = i + 1;
                hi = i + 1;
            }
            else if (phase == 1) {
                phase = 0;
                hi = i + 1;
            }
        }
    }
    if (phase < 0) printf("0");
    else if (lo == hi) printf("%d", 1LL << (lo - 1));
    else printf("%d", 1LL << lo);
    return 0;
}