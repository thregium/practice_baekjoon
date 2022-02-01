#include <stdio.h>

/*
문제 : N * N(4 <= N <= 300) 크기의 체스판에 N개의 퀸을
서로 공격받지 않도록 배치하는 방법 중 하나를 구한다.

해결 방법 : N을 6으로 나눈 나머지가 2나 3이 아닌 경우에는 위쪽 절반(또는 + 1)에 홀수 번째 열로 하나씩,
아래쪽 절반에는 짝수 번째 열로 하나씩 배치하면 된다.
나머지가 2나 3인 경우에는 이를 변형하여 5개의 퀸 자리를 따로 배치하고 나머지 퀸들을 밀어내는 방식으로
배치할 수 있다. 단, 이 경우 8이나 9에서는 잘못된 배치가 되기 때문에 이 때에는 직접 처리한다.

주요 알고리즘 : 구성적, 케이스 워크

출처 : PacNW 2005 I번
*/

int res[384];
int prec[9] = { 4, 6, 8, 2, 7, 1, 3, 5, 9 };

int verify(int n) {
    for (int i = 0; i < n; i++) {
        if (res[i] < 0 || res[i] > n) return 0;
        for (int j = i + 1; j < n; j++) {
            if (res[i] == res[j] || i + res[i] == j + res[j] || i - res[i] == j - res[j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        //n = i;
        if (n % 6 != 2 && n % 6 != 3) {
            for (int j = 0; j < ((n + 1) >> 1); j++) res[j] = j * 2 + 1 + (~n & 1);
            for (int j = 0; j < (n >> 1); j++) res[j + ((n + 1) >> 1)] = j * 2 + 1 + (n & 1);
        }
        else if (n > 9) {
            res[0] = n - 1 - (n & 1);
            for (int i = 0; i < (n >> 1); i++) res[1 + i] = i * 2 + 2;
            res[1]--;
            for (int i = 0; i < (n >> 1) - 1; i++) res[1 + (n >> 1) + i] = i * 2 + 3;
            res[1 + (n >> 1)]--;
            res[n - 1 - (n & 1)] = 3;
            if (n & 1) res[n - 1] = n;
        }
        else {
            for (int j = 0; j < n; j++) res[j] = prec[j];
        }
        //printf("%d: %s\n", i, verify(n) ? "OK" : "NO!");
        printf("%d\n", n);
        for (int j = 0; j < n; j++) {
            printf(" %d", res[j] - 1);
        }
        printf("\n");
    }
    return 0;
}