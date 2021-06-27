#include <stdio.h>

/*
문제 : 골프에서 파와 타수가 주어질 때, 이것이 무엇인지를 주어진 조건에서 찾아 출력한다.(조건 생략)

해결 방법 : 문제에서 주어진 경우에 맞게 출력한다. 홀인원 조건을 가장 먼저 처리해야 한다.

주요 알고리즘 : 구현

출처 : SWERC 1996 PB번
*/

int main(void) {
    int p, s;
    for (int tt = 1;; tt++) {
        scanf("%d %d", &p, &s);
        if (p == 0) break;
        printf("Hole #%d\n", tt);
        if (s == 1) printf("Hole-in-one.\n\n");
        else if (s == p - 3) printf("Double eagle.\n\n");
        else if (s == p - 2) printf("Eagle.\n\n");
        else if (s == p - 1) printf("Birdie.\n\n");
        else if (s == p) printf("Par.\n\n");
        else if (s == p + 1) printf("Bogey.\n\n");
        else printf("Double Bogey.\n\n");
    }
    return 0;
}