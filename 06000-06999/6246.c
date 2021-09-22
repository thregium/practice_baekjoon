#include <stdio.h>

/*
문제 : N(N <= 10000)개의 수가 있다. Q(Q <= 100)번 다음 행동을 반복할 때, 남은 수의 개수를 구한다.
L, I가 주어질 때, L부터 I번마다 나오는 수를 지운다.

해결 방법 : 각 수가 지워졌는지 여부를 저장하는 배열을 두고 아직 지워지지 않은 수가 나올 때 마다
배열에 해당 수를 지웠다는 것을 표시하고 결괏값을 N에서 1씩 빼나가면 된다.

주요 알고리즘 : 구현

출처 : USACO 2007O B2번 // 나코더 2015 E번
*/

char bal[10240];

int main(void) {
    int n, q, l, iv, r;
    scanf("%d %d", &n, &q);
    r = n;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &iv);
        for (int j = l; j <= n; j += iv) {
            if (bal[j]) continue;
            else {
                r--;
                bal[j] = 1;
            }
        }
    }
    printf("%d", r);
    return 0;
}