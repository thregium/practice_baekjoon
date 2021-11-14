#include <stdio.h>
#include <stdlib.h>

/*
문제 : 주어진 문자열(100자, 소문자)과 처음 손가락의 위치가 주어질 때, 문자열을 치는데 걸리는 시간을 구한다.
치는데 걸리는 시간은 1초 + 마지막 손가락과의 거리이다.

해결 방법 : 왼손과 오른손의 문자판 위치를 저장한 다음, 각 문자열에서 어느 위치에 있는지 확인하고,
그 거리를 더해나가면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 한양대E 2020 A번
*/

const char* lt = "qwertasdfgzxcv-";
const char* rt = "-yuiop-hjkl-bnm---";
char s[128];

int main(void) {
    int xl = -1, yl = -1, xr = -1, yr = -1, r = 0;
    char sl, sr;
    scanf("%c %c", &sl, &sr);
    for (int i = 0; i < 15; i++) {
        if (sl == lt[i]) {
            xl = i / 5;
            yl = i % 5;
        }
    }
    for (int i = 0; i < 18; i++) {
        if (sr == rt[i]) {
            xr = i / 6;
            yr = i % 6;
        }
    }
    if (xl < 0 || xr < 0) return 1;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        for (int j = 0; j < 15; j++) {
            if (s[i] == lt[j]) {
                r += abs(j / 5 - xl);
                r += abs(j % 5 - yl);
                xl = j / 5;
                yl = j % 5;
            }
        }
        for (int j = 0; j < 18; j++) {
            if (s[i] == rt[j]) {
                r += abs(j / 6 - xr);
                r += abs(j % 6 - yr);
                xr = j / 6;
                yr = j % 6;
            }
        }
        r++;
    }
    printf("%d", r);
    return 0;
}