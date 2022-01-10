#include <stdio.h>

/*
문제 : 한 발을 발판 위로 올리거나 내리는 N(N <= 100)회의 동작이 주어질 때, 발판 위로 올라가거나 내려간 횟수를 구한다.
잘못된 입력은 주어지지 않는다.

해결 방법 : 잘못된 입력이 주어지지 않기 때문에 2회 연속으로 올라갔다면 반드시 발판 밑에서 위로 올라간 것이며,
2회 연속으로 내려갔다면 반드시 발판 위에서 밑으로 내려간 것일 것이다. 따라서, 그러한 행동의 횟수를 구하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JAG 2014D A번
*/

char buff[8];

int main(void) {
    int n, r, last;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r = 0, last = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", buff);
            if (buff[1] == 'u') {
                if (last > 0) r++;
                else last = 1;
            }
            else {
                if (last < 0) r++;
                else last = -1;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}