#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : M(M <= 100)개의 금지어가 있다. N(N <= 100)개의 문자열에 대해 리트를 적용해서 금지어가 들어있는지 확인한다.
각 문자열의 길이는 25자 미만이다.

해결 방법 : N개의 문자열을 받은 다음 리트를 적용한다. 그 후 strstr를 이용해 모든 금지어에 대해 금지어가 들어있는지 여부를 확인하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : PacNW U번
*/

char* leet = "OLZE4SBTB9";
char bad[128][32], check[128][32];

int main(void) {
    int n, m, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", bad[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", check[i]);
        for (int j = 0; check[i][j]; j++) {
            if (isdigit(check[i][j])) {
                check[i][j] = leet[check[i][j] - '0'];
            }
        }
        t = 1;
        for (int j = 0; j < n; j++) {
            if (strstr(check[i], bad[j]) != NULL) {
                t = 0;
                break;
            }
        }
        printf("%s\n", t ? "VALID" : "INVALID");
    }
    return 0;
}