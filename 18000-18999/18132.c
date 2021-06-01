#include <stdio.h>
#define MOD 1000000007

/*
문제 : 간선 N(N <= 5000)개가 있는 이진 트리의 개수를 구한다.

해결 방법 : 이진 트리의 왼쪽과 오른쪽에 간선을 나누어 놓는 방법의 DP를 통해 이진 트리의 개수를 구할 수 있다.
각 트리의 왼쪽과 오른쪽 간선에서 1개씩 빼면 각 서브트리의 간선 수가 되고, 그 수의 곱을 각각 구해서 더하면 된다.
이때 한쪽 서브트리의 값이 0이 되는 경우 한쪽의 간선 수만 확인한 후 더한다.

주요 알고리즘 : DP, 카탈란 수

출처 : 가톨릭대 1회D1 C번
*/

int mem[5120];

int main(void) {
    mem[0] = 1;
    mem[1] = 2;
    for (int i = 2; i <= 5000; i++) {
        mem[i] = (mem[i - 1] * 2) % MOD;
        for (int j = 1; j < i; j++) {
            mem[i] = (mem[i] + (long long)mem[j - 1] * mem[i - j - 1]) % MOD;
        }
    }
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        printf("%d\n", mem[n]);
    }
    return 0;
}