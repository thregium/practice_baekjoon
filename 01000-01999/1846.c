#include <stdio.h>

/*
문제 : N * N(3 <= N <= 100000) 크기의 체스판에 룩 N개를 서로 공격받지 않도록 배치하는 방법을 출력한다.
단, 모든 룩은 대각선 칸에 있어선 안 된다. 배치하는 방법이 없는 경우 -1을 출력한다.

해결 방법  : N이 3인 경우 배치하는 방법이 없다. N이 5 이상의 홀수라면 2번째, 1번째, N번째 칸에 배치한 후,
이후로는 3번째부터 N - 1번째까지 차례로 배치하면 된다. 4 이상의 짝수인 경우 2, 1, N, N - 1번째 칸에 배치하고
3번째부터 N - 2번째까지 차례로 배치하면 된다.

주요 알고리즘 : 구성적
*/

int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 3) {
        printf("-1");
        return 0;
    }
    else if (n & 1) {
        printf("2\n1\n%d\n", n);
        for (int i = 3; i < n; i++) printf("%d\n", i);
    }
    else {
        printf("2\n1\n%d\n%d\n", n, n - 1);
        for (int i = 3; i < n - 1; i++) printf("%d\n", i);
    }
    return 0;
}