#include <stdio.h>
#include <string.h>

/*
문제 : 4분할을 반복한 지도의 분할 순서가 주어질 때, 해당 지역의 좌표를 구한다.

해결 방법 : 방향을 확인하고 1칸씩 이동한 후 좌표를 2배로 하는 것을 반복하면 된다.

주요 알고리즘 : 수학

출처 : NWERC 2015 I번
*/

char s[32];

int main(void) {
    int l, x = 0, y = 0;
    scanf("%s", s);
    l = strlen(s);
    for (int i = 0; i < l; i++) {
        x *= 2, y *= 2;
        if (s[i] == '1') x++;
        else if (s[i] == '2') y++;
        else if (s[i] == '3') {
            x++;
            y++;
        }
    }
    printf("%d %d %d", l, x, y);
    return 0;
}