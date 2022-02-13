#include <stdio.h>

/*
문제 : N(N <= 100)개의 'J', 'O', 'I'로 이루어진 문자열을 'J' 이후로 'O', 그 뒤로 'I'가 오도록
순서를 바꾸어 출력한다.

해결 방법 : 'J', 'O', 'I'의 개수를 각각 센 후, 각 문자를 'J', 'O', 'I' 순서대로 개수에 맞춰 출력하면 된다.

주요 알고리즘 : 문자열, 구현, 정렬

출처 : JOI 2021예1 1-2번
*/

char s[128];

int main(void) {
    int n, jc = 0, oc = 0, ic = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'J') jc++;
        else if (s[i] == 'O') oc++;
        else ic++;
    }
    for (int i = 0; i < jc; i++) printf("J");
    for (int i = 0; i < oc; i++) printf("O");
    for (int i = 0; i < ic; i++) printf("I");
    printf("\n");
    return 0;
}