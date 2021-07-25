#include <stdio.h>

/*
문제 : XXX-XX-XX형태의 번호가 있을 때, 맨 앞자리가 N(100 <= N <= 999)이라면, 이 번호를 식으로 보았을 때 결과가 0이 되는
방법의 수가 몇 가지 있는지 구한다.

해결 방법 : 뒤의 두 수를 각각 00부터 99까지 돌아보며 두 수의 합이 N이 되는 횟수를 구하면 된다.

주요 알고리즘 : 브루트 포스

출처 : NWRRC 2011 A번
*/

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (i + j == n) r++;
        }
    }
    printf("%d", r);
    return 0;
}