#include <stdio.h>

/*
문제 : 10000 이하의 수로 주어지는 두 점의 번호가 주어질 때, 두 점을 더한 점의 번호를 구한다.

해결 방법 : 1번부터 차례로 살펴보며 두 점의 좌표를 구하고, 좌표를 더한 점을 다시 한번씩 살피며 번호를 구한다.

주요 알고리즘 : 수학, 기하학

출처 : Daejeon 2012 D번
*/

int main(void) {
    int t, a, b, x, y, xa, ya;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        x = 1, y = 1;
        for (int i = 1; i < a; i++) {
            if (y == 1) {
                y = x + 1;
                x = 1;
            }
            else {
                x++;
                y--;
            }
        }
        xa = x;
        ya = y;
        x = 1, y = 1;
        for (int i = 1; i < b; i++) {
            if (y == 1) {
                y = x + 1;
                x = 1;
            }
            else {
                x++;
                y--;
            }
        }
        xa += x;
        ya += y;
        x = 1, y = 1;
        for (int i = 1;; i++) {
            if (x == xa && y == ya) {
                printf("%d\n", i);
                break;
            }
            if (y == 1) {
                y = x + 1;
                x = 1;
            }
            else {
                x++;
                y--;
            }
        }
    }
    return 0;
}