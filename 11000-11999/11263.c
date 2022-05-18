#include <stdio.h>

/*
문제 : N(2 <= N <= 7)자리 숫자로 이루어진 수 가운데 숫자의 합이 S인 것의 가짓수를 구한다.
수는 0으로 시작할 수 있다.

해결 방법 : 우선 브루트 포스로 N이 7 이하인 모든 경우에 대해 전처리한 후, 쿼리를 입력받고
답들을 처리하면 된다.

주요 알고리즘 : 브루트 포스

출처 : Thai 2015S G번
*/

int b10[8] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };
int db[8][128];

int main(void) {
    int n, s, t;
    for (int d = 2; d <= 7; d++) {
        for (int i = 0; i < b10[d]; i++) {
            t = 0;
            for (int j = i; j; j /= 10) t += j % 10;
            db[d][t]++;
        }
    }
    while (scanf("%d %d", &n, &s) != EOF) {
        printf("%d\n", db[n][s]);
    }
    return 0;
}