#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 50)가지 동전의 가치(<= 100000)가 주어질 때, 100000 이하에서 동전 문제의 그리디한 풀이의
반례가 있는 지 구하고, 있다면 그 중 가장 작은 값을 출력한다. 없다면 -1을 출력한다.

해결 방법 : 냅색을 통해 100000 이하의 모든 수에 대해 동전 수를 구한 다음, 0부터 10만까지
그리디한 방법과 일일히 비교해 나간다. 그 중 서로 다른 가장 작은 값을 출력하면 된다.

주요 알고리즘 : DP, 냅색, 그리디 알고리즘

출처 : TOPC 2019 C번
*/

int coin[50], mem[103000];

int small(int a, int b) {
    return a < b ? a : b;
}

int greedy(int x, int n) {
    int r = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (x >= coin[i]) {
            r += x / coin[i];
            x %= coin[i];
        }
    }
    return r;
}

int main(void) {
    int n;
    for (int i = 1; i <= 103000; i++) mem[i] = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
        for (int j = coin[i]; j <= 100000; j++) {
            mem[j] = small(mem[j], mem[j - coin[i]] + 1);
        }
    }
    for (int i = 0; i <= 100000; i++) {
        if (greedy(i, n) != mem[i]) {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}