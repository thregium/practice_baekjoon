#include <stdio.h>

/*
문제 : N(N <= 25)개의 자연수가 주어지면 수들을 출력하되, 연속해서 같은 수가 나온 경우 하나씩으로 줄여 출력한다.

해결 방법 : 마지막 수를 미리 저장해둔다. 맨 처음에는 자연수에서 나올 수 없는 -1 등으로 초기화시킨 다음,
이후로는 마지막 수와 같은 수가 나오면 스킵, 다른 수가 나오면 그 수를 출력한 후, 마지막 수를 갱신하면 된다.

주요 알고리즘 : 구현

출처 : MidC 2009 E번
*/

int main(void) {
    int n, l, x;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        l = -1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            if (x == l) continue;
            l = x;
            printf("%d ", x);
        }
        printf("$\n");
    }
    return 0;
}