#include <stdio.h>

/*
문제 : N개의 문자에 대한 대응표가 주어질 때, M(M <= 100000)개의 문자에 대해 대응표에 있는 지 확인하고,
있다면 대응하는 문자를, 없다면 원래 문자를 출력한다.
대응표에 들어가는 값과 입력되는 모든 문자들은 대소문자 또는 숫자이다.

해결 방법 : 대응표를 배열에 저장하고, 문자들을 입력받으면서 배열의 값이 NULL인 경우 원래 문자를,
그 외에는 배열의 값을 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : JOI 2006예 2번
*/

char tb[256];

int main(void) {
    int p, n;
    char c1, c2;
    for (int tt = 0;; tt++) {
        scanf("%d", &p);
        if (p == 0) break;
        for (int i = 0; i < p; i++) {
            scanf(" %c %c", &c1, &c2);
            tb[c1] = c2;
        }
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %c", &c1);
            if (tb[c1]) printf("%c", tb[c1]);
            else printf("%c", c1);
        }
        printf("\n");
        for (int i = 0; i < 256; i++) tb[i] = '\0';
    }
    return 0;
}