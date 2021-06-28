#include <stdio.h>

/*
문제 : 수열의 초항과 공차가 주어질 때, K가 몇 번째 항인지 구한다, 항이 아니라면 X를 출력한다.
초항의 절댓값은 1000 이하이고 K의 절댓값은 100만 이하이다.

해결 방법 : 최대 약 100만회 이내에는 K를 얻을 수 있음을 알 수 있다. 따라서, 100만회 넘게 등차수열을 계산한 다음,
항이 나온 경우 해당 번째 항이고, 나오지 않았다면 앞으로도 나오지 않을 것이므로 X를 출력하면 된다.

주요 알고리즘 : 수학, 브루트 포스

출처 : 한양대E 2017B E번
*/

int main(void) {
    int a, d, k;
    scanf("%d %d %d", &a, &d, &k);
    for (int i = 1; i <= 1234567; i++) {
        if (a == k) {
            printf("%d", i);
            return 0;
        }
        a += d;
    }
    printf("X");
    return 0;
}