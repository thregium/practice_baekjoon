#include <stdio.h>

/*
문제 : N * M 크기의 격자의 한쪽 꼭짓점에서 출발해 모든 지점을 이동하려고 할 때 필요한 90도 회전의 최소 개수를 구한다.

해결 방법 : 긴쪽 변으로 계속 이동하다 다음 줄로 돌아가는 것을 반복하는 것이 가장 적게 회전하는 것이다.
이때의 회전 횟수는 (짧은 변의 길이 - 1) * 2이다.

주요 알고리즘 : 수학

출처 : COCI 17/18#2 1번
*/

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int k, n, m;
    scanf("%d", &k);
    for (int kk = 0; kk < k; kk++) {
        scanf("%d %d", &n, &m);
        printf("%d\n", (small(n, m) - 1) * 2);
    }
    return 0;
}