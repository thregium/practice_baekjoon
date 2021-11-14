#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)장의 문서를 와 출력하는 범위가 주어진다. 출력하는 페이지를 모두 구한다.
st-ed와 p 형태가 콤마를 사이에 두고 구분되며, st > ed인 경우는 출력하지 않고 범위를 벗어나는 경우도 출력하지 않는다.
주어지는 문자열은 1000자 이내이다.

해결 방법 : strtok() 함수를 이용해 파싱한다. 그 범위에서 수들은 다시 strtoll() 함수를 이용해 뽑아내고,
출력할 페이지들은 배열을 이용해 관리한다. 배열에서 출력할 페이지가 된 페이지들을 세서 그 개수를 구하면 답이 된다.

주요 알고리즘 : 구현, 파싱

출처 : Rocky 2010 E번
*/

char s[1024];
int toprint[1024];

int main(void) {
    int n, r = 0, st, ed;
    char* c;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%s", s);
        c = strtok(s, ",");
        while (c) {
            if (strchr(c, '-')) {
                st = strtoll(c, &c, 10);
                c++;
                ed = strtoll(c, NULL, 10);
                for (int i = st; i > 0 && i <= ed && i <= n; i++) toprint[i] = 1;
            }
            else {
                st = strtoll(c, NULL, 10);
                if (st >= 1 && st <= n) toprint[st] = 1;
            }
            c = strtok(NULL, ",");
        }
        r = 0;
        for (int i = 1; i <= n; i++) {
            r += toprint[i];
            toprint[i] = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}