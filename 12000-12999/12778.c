#include <stdio.h>

/*
문제 : M과 알파벳 한 문자가 주어진 다음 M(M <= 500)개의 알파벳 대문자(해당 문자가 'C'인 경우) 또는 수(해당 문자가 'N'인 경우)
가 주어진다. 이때, 알파벳이 주어진 경우 몇 번째 알파벳인지 각각 출력하고, 수가 주어진 경우 해당하는 번째의
알파벳(대문자)을 각각 출력한다.

해결 방법 : 문자의 종류에 따라 경우를 나눈다. 대문자인 경우는 해당 문자에서 'A'를 빼고 1을 더하면 되고,
수인 경우는 해당 문자에서 'A'를 더하고 1을 빼면 된다.

주요 알고리즘 : 구현

출처 : 인하대 2016 A번
*/

int main(void) {
    int t, m, n;
    char p, c;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %c", &m, &p);
        if (p == 'C') {
            for (int i = 0; i < m; i++) {
                scanf(" %c", &c);
                printf("%d ", c - 'A' + 1);
            }
        }
        else {
            for (int i = 0; i < m; i++) {
                scanf("%d", &n);
                printf("%c ", (char)(n + 'A' - 1));
            }
        }
        printf("\n");
    }
    return 0;
}