#include <stdio.h>

/*
문제 : N(N <= 1000)개의 열매가 있다. 각 열매의 포만도 w_i(w_i <= 1000)와
포만도 한계 C(C <= 10^6)가 주어질 때, 어떤 열매에서 먹기 시작하여 이후로 포만도가 남는 한
최대한 먹는 방식으로 먹을 수 있는 열매 개수의 최댓값을 구한다.

해결 방법 : N이 작기 때문에 가능한 모든 열매에서 시작해보면서 포만도를 계산하고, 열매 개수가
가장 많을 때의 개수를 구하면 된다.

주요 알고리즘 : 브루트 포스

출처 : COCI 15/16#6 2번
*/

int w[1024];

int main(void) {
    int n, c, sum, cnt, res = 0;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < n; i++) {
        sum = 0, cnt = 0;
        for (int j = i; j < n; j++) {
            sum += w[j];
            if (sum > c) {
                sum -= w[j];
                continue;
            }
            cnt++;
        }
        if (cnt > res) res = cnt;
    }
    printf("%d", res);
    return 0;
}