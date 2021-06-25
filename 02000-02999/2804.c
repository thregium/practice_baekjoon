#include <stdio.h>

/*
문제 : 30자 이하의 두 문자열 A와 B가 주어질 때, 두 문자열 사이 겹치는 첫 문자를 찾아 크로스워드 형태로 출력한다.

해결 방법 : 문제에 쓰인대로 구현한다. 가로/세로가 바뀜에 유의한다.

주요 알고리즘 : 구현, 문자열

출처 : COCI 11/12#5 1번
*/

char a[32], b[32];

int main(void) {
    int x = -1, y = -1;
    scanf("%s %s", a, b);
    for (int i = 0; a[i]; i++) {
        for (int j = 0; b[j]; j++) {
            if (a[i] == b[j]) {
                x = i;
                y = j;
                break;
            }
        }
        if (x >= 0) break;
    }

    for (int i = 0; b[i]; i++) {
        for (int j = 0; a[j]; j++) {
            if (i == y) printf("%c", a[j]);
            else if (j == x) printf("%c", b[i]);
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}