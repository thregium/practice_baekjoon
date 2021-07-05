#include <stdio.h>
#include <string.h>

/*
문제 : P(P <= 100)개의 가격과 이름이 주어질 때, 가격이 가장 큰 것의 이름을 찾는다.

해결 방법 : 가격이 가장 큰 것의 가격과 이름을 저장해두고 더 큰것이 나오면 그것들을 업데이트한다.
이를 반복하며 마지막에 가장 큰 것의 이름을 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : IDI 2007 A번
*/

char buff[32], bestname[32];

int main(void) {
    int n, p, c, best;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p);
        best = 0;
        for (int j = 0; j < p; j++) {
            scanf("%d %s", &c, buff);
            if (c > best) {
                best = c;
                strcpy(bestname, buff);
            }
        }
        printf("%s\n", bestname);
    }
    return 0;
}