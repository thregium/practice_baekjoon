#include <stdio.h>

/*
문제 : N(N <= 1000)장의 카드를 원하는 순서대로 만들기 위해 시작해야 할 순서를 출력한다.

해결 방법 : 첫 번째 칸부터 매번 i개 뒤의 카드를 i로 만들면 된다. 단, 이미 정해진 카드는 세지 않아야 한다.

주요 알고리즘 : 구현

출처 : NCPC 2006 E번
*/

int res[1024];

int main(void) {
    int t, n, pos;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) res[i] = 0;
    pos = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            pos = (pos + 1) % n;
            while (res[pos]) {
                pos = (pos + 1) % n;
            }
        }
        res[pos] = i;
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", res[i % n]);
    }
    printf("\n");
    return 0;
}
