#include <stdio.h>

/*
문제 : 직사각형의 너비와 높이, 면적 중 하나가 주어지지 않을 때, 주어지지 않은 값을 포함한 세 개의 값을 구한다.

해결 방법 : 넓이가 주어지지 않은 경우 가로 * 세로를 하면 되고, 가로나 세로가 주어지지 않은 경우 넓이에서
나머지 하나를 나누어 주면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : NZPC 2007 D번
*/

int main(void) {
    int l, w, a;
    while (1) {
        scanf("%d %d %d", &l, &w, &a);
        if (l == 0 && w == 0 && a == 0) break;
        if (a == 0) printf("%d %d %d\n", l, w, l * w);
        else if (w == 0) printf("%d %d %d\n", l, a / l, a);
        else if (l == 0) printf("%d %d %d\n", a / w, w, a);
    }
    return 0;
}