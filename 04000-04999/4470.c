#include <stdio.h>

/*
문제 : N(N <= 50)줄의 문자열이 주어질 때, 각 문자열에 번호를 매긴다.

해결 방법 : 반복문과 fgets() 함수를 이용해 문자열을 입력받으며 번호를 출력하고 입력받은 문자열을 다시 출력하면 된다.

주요 알고리즘 : 구현

출처 : PacNW 2010 P번
*/

char line[64];

int main(void) {
    int n;
    scanf("%d", &n);
    fgets(line, 60, stdin);
    for (int i = 1; i <= n; i++) {
        fgets(line, 60, stdin);
        printf("%d. %s", i, line);
    }
    return 0;
}