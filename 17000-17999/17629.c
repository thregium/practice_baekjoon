#include <stdio.h>

/*
문제 : 길이 N과 M(N, M <= 100)의 대문자로 된 두 문자열 A, B가 주어질 때, 문제에 주어진 방법대로 두 문자열의 궁합을 구한다.

해결 방법 : 두 문자열을 문제에 주어진 방식대로 합친다. 그 다음, 문자열의 획수를 구하고,
획수에서 연속된 두 수의 합 % 10을 반복하여 두 수가 남을 때 까지 한다. 남은 두 수에서 답을 구해 출력하면 된다.

주요 알고리즘 : 구현, DP?

출처 : 인하대 2019 G번
*/

char a[128], b[128], s[256];
int mem[256][256];
const int strk[26] = { 3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

int main(void) {
    int n, m, nn = 0, mm = 0;
    scanf("%d %d", &n, &m);
    scanf("%s %s", a, b);
    for (int i = 0; i < n + m; i++) {
        if (i & 1) {
            if (b[mm]) s[i] = b[mm++];
            else s[i] = a[nn++];
        }
        else {
            if (a[nn]) s[i] = a[nn++];
            else s[i] = b[mm++];
        }
    }
    for (int i = 0; i < n + m; i++) {
        mem[0][i] = strk[s[i] - 'A'];
    }
    for (int i = 1; i < n + m - 1; i++) {
        for (int j = 0; j < n + m - i; j++) {
            mem[i][j] = (mem[i - 1][j] + mem[i - 1][j + 1]) % 10;
        }
    }
    printf("%d%%", mem[n + m - 2][0] * 10 + mem[n + m - 2][1]);
    return 0;
}