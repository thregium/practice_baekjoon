#include <stdio.h>

/*
문제 : N(N <= 20) 롤링페이퍼의 메세지가 각각 주어지면 좋지 않은 말을 한 사람이 누구이고 누구에게 그랬는지 구한다.

해결 방법 : 왼쪽에서 X번째에 쓰인 메시지는 X명 왼쪽 사람이 쓴 것이다. 간단한 연산을 통해 그 사람을 찾을 수 있고,
그 사람을 출력하면 된다.

주요 알고리즘 : 구현

출처 : NZPC 2006 F번
*/

int mess[32][32];
char s[32][64];

int main(void) {
    int n, r = 0;
    char c;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i]);
            for (int j = 1; j < n; j++) {
                scanf(" %c", &c);
                if (c == 'N') mess[i][j] = 1;
                else mess[i][j] = 0;
            }
        }
        printf("Group %d\n", tt);

        r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mess[i][j]) {
                    printf("%s was nasty about %s\n", s[(i - j + n) % n], s[i]);
                    r++;
                }
            }
        }
        if (r == 0) printf("Nobody was nasty\n");
        printf("\n");
    }
    return 0;
}