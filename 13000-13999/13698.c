#include <stdio.h>

/*
문제 : 4개의 컵에 공 2개를 넣고, 컵을 주어진 순서에 맞게 옮길 때, 마지막에 두 공이 있는 위치를 구한다.

해결 방법 : 주어진 순서에 맞게 공들을 직접 옮겨본다.

주요 알고리즘 : 구현, 시뮬레이션, 케이스 워크?

출처 : 홍익대 2016 A번
*/

char s[256];

int main(void) {
    int b = 4, l = 1;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A') {
            if (b == 1) b = 2;
            else if (b == 2) b = 1;
            if (l == 1) l = 2;
            else if (l == 2) l = 1;
        }
        else if (s[i] == 'B') {
            if (b == 1) b = 3;
            else if (b == 3) b = 1;
            if (l == 1) l = 3;
            else if (l == 3) l = 1;
        }
        else if (s[i] == 'C') {
            if (b == 1) b = 4;
            else if (b == 4) b = 1;
            if (l == 1) l = 4;
            else if (l == 4) l = 1;
        }
        else if (s[i] == 'D') {
            if (b == 2) b = 3;
            else if (b == 3) b = 2;
            if (l == 2) l = 3;
            else if (l == 3) l = 2;
        }
        else if (s[i] == 'E') {
            if (b == 2) b = 4;
            else if (b == 4) b = 2;
            if (l == 2) l = 4;
            else if (l == 4) l = 2;
        }
        else if (s[i] == 'F') {
            if (b == 3) b = 4;
            else if (b == 4) b = 3;
            if (l == 3) l = 4;
            else if (l == 4) l = 3;
        }
    }
    printf("%d\n%d", l, b);
    return 0;
}