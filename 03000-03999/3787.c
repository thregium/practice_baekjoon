#include <stdio.h>

/*
문제 : 모든 분수가 나오는 순서를 문제에 정의된대로 한다면, N(N <= 10^7)번째 분수를 찾는다.

해결 방법 : 분모와 분자의 합을 구한 다음 분모, 분자로 가능한 값을 찾고,
방향에 따라 분모와 분자를 배치하면 된다.

주요 알고리즘 : 수학, 브루트 포스

출처 : SEERC 2004 I번
*/

int main(void) {
    int x, i, a, b, s = 0;
    while (scanf("%d", &x) != EOF) {
        s = 0;
        for (i = 0; i < x; s++) i += s;
        a = i - x + 1;
        b = s - (i - x + 1);
        if (s % 2) printf("TERM %d IS %d/%d\n", x, b, a);
        else printf("TERM %d IS %d/%d\n", x, a, b);
    }
    return 0;
}