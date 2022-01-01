#include <stdio.h>

/*
문제 : 각 줄에 채워지는 수의 개수가 1, 2, 3, ... 순으로 나오는 삼각형에서 두 번호가 주어질 때,
두 번호 사이의 거리를 구한다. 두 번호는 10000 이하의 자연수이다.

해결 방법 : 두 번호가 나오는 행과 열을 구한 다음, 경우를 나누어 답을 구하면 된다.
행 차이에다가 추가로 움직여야 하는 열의 수를 더한다. 이 값은 더 큰 쪽 수의 열이 더 작은 경우 열의 차만큼,
또는 작은 쪽 수의 열보다 행의 차이보다 차이가 큰 경우 열의 차 - 행의 차만큼이고, 이 외에는 0이다.

주요 알고리즘 : 수학

출처 : Tehran 2009 B번
*/

int main(void) {
    int a, b, ax, ay, bx, by, s, r;
    while (1) {
        scanf("%d %d", &a, &b);
        if (a == 0) break;
        s = 0, ax = 0, ay = 0, bx = 0, by = 0;
        for (int i = 1;; i++) {
            s += i;
            if (ax == 0 && s >= a) {
                ax = i;
                ay = a - (s - i);
            }
            if (bx == 0 && s >= b) {
                bx = i;
                by = b - (s - i);
            }
            if (ax && bx) break;
        }
        
        r = 0;
        if (a > b) {
            r += ax - bx;
            if (ay < by) r += by - ay;
            else if (ay > by + r) r += ay - by - r;
        }
        else {
            r += bx - ax;
            if (ay > by) r += ay - by;
            else if (ay + r < by) r += by - ay - r;
        }
        printf("%d\n", r);
    }
    return 0;
}