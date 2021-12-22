#include <stdio.h>

/*
문제 : N * N(N <= 10^9) 크기의 타일을 가장 바깥쪽부터 빨강, 파랑, 노랑, 빨강, 파랑, 노랑, ... 순서로 붙였다고 한다.
이때, 위에서 A, 왼쪽에서 B번째 위치에 있는 타일의 색을 구한다.

해결 방법 : 바깥에서의 거리를 구하면 3을 나눈 나머지를 통해 빠르게 구할 수 있다. 바깥에서의 거리는 A와 B의
1, N과의 거리 가운데 가까운 것 중 가까운 것과 같다.

주요 알고리즘 : 수학

출처 : JOI 2011예 3번
*/

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, k, a, b;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", small(small(a - 1, n - a), small(b - 1, n - b)) % 3 + 1);
    }
    return 0;
}