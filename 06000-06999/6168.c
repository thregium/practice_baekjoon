#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 30000)개의 1 또는 2가 주어질 때, 최소한의 수를 바꾸어
이 수들을 정렬되도록 만들 때, 바꿔야 하는 수의 개수를 구한다.

해결 방법 : 왼쪽에서부터 2의 개수의 합과 오른쪽에서부터 1의 개수의 합을 미리 구해둔 다음에,
각 위치에 대해 해당 위치까지 1, 오른쪽부터 2일때의 바꿔야 하는 수를 위 값을 이용해 구할 수 있다는 점을 활용해서
모든 위치에서 이 값을 구한 다음, 가장 작은 것을 고르면 된다.

주요 알고리즘 : 누적 합

출처 : USACO 2008F B1번
*/

int dining[32768], lsum[32768], rsum[32768];

int main(void) {
    int n, b, r = INF;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &dining[i]);
        lsum[i] = lsum[i - 1] + (dining[i] == 2);
    }
    for (int i = n; i >= 0; i--) {
        rsum[i] = rsum[i + 1] + (dining[i] == 1);
        if (lsum[i] + rsum[i + 1] < r) r = (lsum[i] + rsum[i + 1]);
    }
    printf("%d", r);
    return 0;
}