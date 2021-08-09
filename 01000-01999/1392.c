#include <stdio.h>

/*
문제 : N(N <= 100)개의 악보의 길이가 주어지고, 이 악보들을 순서대로 부른다고 할 때, Q(Q <= 1000)개의 쿼리에 응답한다.
X분에는 몇 번째 악보를 연주하고 있는가?
악보는 0분부터 연주하며 한 악보가 끝나면 바로 다른 악보를 응답한다. 모든 입력은 정수이고 연주가 끝난 뒤를 물어보는 경우는 없다.

해결 방법 : 미리 모든 악보의 누적합 - 1을 구해둔 후, 각 쿼리마다 악보에서 누적합이 쿼리의 값보다 작은 첫 번째 악보를 구하면 된다.

주요 알고리즘 : 구현

출처 : USACO 2009J B3번
*/

int scores[128];

int main(void) {
    int n, q, x;
    scanf("%d %d", &n, &q);
    scores[0] = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &scores[i]);
        scores[i] += scores[i - 1];
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &x);
        for (int j = 1; j <= n; j++) {
            if (scores[j] >= x) {
                printf("%d\n", j);
                break;
            }
        }
    }
    return 0;
}