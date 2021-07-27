#include <stdio.h>

/*
문제 : 복면산 HELLO + WORLD의 값이 N이 되는 각 문자들이 있는지 찾고, 있다면 그러한 것을 하나 출력한다.
단, H나 W의 값은 0이 될 수 없고, 모든 문자들은 서로 달라야 한다. 없는 경우에는 No Solution을 출력한다.

해결 방법 : 각 문자들을 서로 다르게 하는 순열들을 각각 찾은 후, H와 W가 0이 아니고 HELLO + WORLD가 N과 같다면
그러한 식을 출력하고 프로그램을 종료한다. 찾지 못한 경우엔 없는 것이므로 No Solution을 출력하면 된다.

주요 알고리즘 : 수학, 백트래킹

출처 : FunctionCup 2016 H번
*/

int digits[8], chk[16];
int n, fin = 0;

void check(void) {
    if (digits[0] == 0 || digits[4] == 0) return;
    if (digits[0] * 10000 + digits[1] * 1000 + digits[2] * 120 + digits[3] * 1001 + digits[4] * 10000 + digits[5] * 100 + digits[6] == n) {
        fin = 1;
        printf("  %d%d%d%d%d\n", digits[0], digits[1], digits[2], digits[2], digits[3]);
        printf("+ %d%d%d%d%d\n", digits[4], digits[3], digits[5], digits[2], digits[6]);
        printf("-------\n");
        if (n < 100000) printf("  %d", n);
        else printf(" %d", n);
    }
}

void track(int x) {
    if (x == 7) {
        check();
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        digits[x] = i;
        track(x + 1);
        chk[i] = 0;
        if (fin) return;
    }
}

int main(void) {
    scanf("%d", &n);
    track(0);
    if (!fin) printf("No Answer");
    return 0;
}