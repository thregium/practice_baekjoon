#include <stdio.h>

/*
문제 : 두 명이 X(X <= 10^9, 자연수)만큼 거리를 두고 있다. 두 명이 번갈아가며 K, A(K, A <= X, 자연수)씩 이동한다고 할 때,
상대의 발을 밟을 수 있는 사람이 누구인지 구한다.

해결 방법 : 두 명이 한 번씩 이동할 때 마다 K + A씩 거리가 줄어들게 된다. 따라서, 거리를 K + A로 나눈 나머지가
마지막 턴에 남은 거리가 된다. 여기서 거리가 K보다 작다면 K가 발을 밟고, K 이상인 경우 A가 발을 밟게 된다.

주요 알고리즘 : 수학

출처 : ILOCAMP 2011 1-3번
*/

int main(void) {
    int x, k, a;
    scanf("%d %d %d", &x, &k, &a);
    printf("%d", (x % (k + a) < k));
    return 0;
}