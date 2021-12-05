#include <stdio.h>
#include <stdlib.h>

/*
문제 : 9개의 정수가 주어질 때, 해당 정수들을 8차항부터 상수항까지의 계수로 하는 다항식을 문제에 주어진 대로 출력한다.

해결 방법 : 다항식의 첫 항인지 여부를 변수로 두고 나머지는 항의 계수와 차수를 기준으로 경우를 나누어 출력해 나가면 된다.
이때, 모든 항이 0인 경우에 유의한다.

주요 알고리즘 : 구현, 케이스 워크

출처 : MidC 1996 A번
*/

int main(void) {
    int coef, stt;
    while (1) {
        stt = 0;
        for (int i = 8; i >= 0; i--) {
            if (scanf("%d", &coef) == EOF) return 0;
            if (coef == 0) continue;
            if (stt == 0) {
                if (coef < 0) printf("-");
                if (abs(coef) > 1) printf("%d", abs(coef));
                else if (i == 0) printf("1");
                if (i > 1) printf("x^%d", i);
                else if (i == 1) printf("x");
                stt = 1;
            }
            else {
                if (coef < 0) printf(" - ");
                else printf(" + ");
                if (abs(coef) > 1) printf("%d", abs(coef));
                else if (i == 0) printf("1");
                if (i > 1) printf("x^%d", i);
                else if (i == 1) printf("x");
            }
        }
        if (!stt) printf("0");
        printf("\n");
    }
    return 0;
}