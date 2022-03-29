#include <stdio.h>

/*
문제 : 현재 시각을 4자리로 표현한 수가 주어질 때, 이를 주어진 형식대로 2진 형태로 출력한다.

해결 방법 : 문제에 주어진 방식대로 출력한다. 문자열을 사용하는 것이 좋다.

주요 알고리즘 : 구현, 비트마스킹

출처 : MidAtl 2021 B번 // NCNA 2021 D번
*/

char n[8];

int main(void) {
    scanf("%s", n);
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            printf("%c", (((n[j] - '0') >> i) & 1) ? '*' : '.');
            if (j == 1) printf("   ");
            else if (j < 3) printf(" ");
        }
        printf("\n");
    }
    return 0;
}