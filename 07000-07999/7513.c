#include <stdio.h>

/*
문제 : N(N <= 50)개의 단어가 주어지고, 이후 N(N <= 300)개의 단어에 대해 K(K <= 10)개의 주어지는 위치의 단어들을
이어붙인 문자열을 출력한다.

해결 방법 : 각 단어들을 입력받은 다음, 주어지는 위치의 단어를 찾아 연속으로 출력해주면 이어붙인 문자열이 된다.

주요 알고리즘 : 구현

출처 : TUD 2008S 3번
*/

char word[64][16];

int main(void) {
    int t, m, n, k, x;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%s", word[i]);
        }
        scanf("%d", &n);
        printf("Scenario #%d:\n", tt);
        for (int i = 0; i < n; i++) {
            scanf("%d", &k);
            for (int j = 0; j < k; j++) {
                scanf("%d", &x);
                printf("%s", word[x]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}