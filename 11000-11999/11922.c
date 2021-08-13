#include <stdio.h>

/*
문제 : N * 4개의 카드가 주어질 때, 이 카드들의 점수를 구한다. (점수표 생략)

해결 방법 : 기준에 맞게 점수를 구한다.

주요 알고리즘 : 구현

출처 : COCI 15/16#6 1번
*/

char cd[8];

int main(void) {
    int n, r = 0;
    char b;
    scanf("%d %c", &n, &b);
    for (int i = 0; i < n * 4; i++) {
        scanf("%s", cd);
        if (cd[1] == b) {
            if (cd[0] == 'A') r += 11;
            else if (cd[0] == 'K') r += 4;
            else if (cd[0] == 'Q') r += 3;
            else if (cd[0] == 'J') r += 20;
            else if (cd[0] == 'T') r += 10;
            else if (cd[0] == '9') r += 14;
        }
        else {
            if (cd[0] == 'A') r += 11;
            else if (cd[0] == 'K') r += 4;
            else if (cd[0] == 'Q') r += 3;
            else if (cd[0] == 'J') r += 2;
            else if (cd[0] == 'T') r += 10;
        }
    }
    printf("%d", r);
    return 0;
}