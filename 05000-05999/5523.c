#include <stdio.h>

/*
문제 : N(N <= 10^6)번의 A와 B 간의 경기 결과가 주어질 때, A와 B의 승리 횟수를 각각 구한다.
점수가 상대보다 큰 경우 승리한다. 무승부인 경우 양쪽 모두 승리하지 못한다.

해결 방법 : 양쪽의 승리 횟수를 0으로 초기화한 후, 양쪽의 점수를 입력받으며 점수가 큰 쪽의 승리 횟수를 늘린다.
N번의 입력이 끝나면 양쪽의 승리 횟수를 출력하면 된다.

주요 알고리즘 : 구현

출처 : JOI 2013 P2 / 2014 P2번
*/

int main(void) {
    int n, aw = 0, bw = 0, ai, bi;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ai, &bi);
        if (ai > bi) aw++;
        else if (ai < bi) bw++;
    }
    printf("%d %d", aw, bw);
    return 0;
}