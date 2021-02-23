#include <stdio.h>

/*
문제 : 두 선분의 각 점마다 좌표가 주어질 때 두 선분이 교차하는지 여부를 출력한다. (단, 한 선분이 다른 선분에서 시작하는 경우는 없다.)

해결 방법 : 한 선분의 양 끝점이 다른 선분에 대해 반대쪽에 있고, 다른 선분의 양 끝점도 한 선분에 대해 반대쪽에 있는 경우 두 선분이 교차한다.
-|형으로 교차하지 않는 경우가 있기에 두 선분을 모두 봐야 한다.

주요 알고리즘 : 기하학, 선분의 교차 판정
*/

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
     long long int tri = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
     if (tri > 0) return 1;
     else if (tri == 0) return 0;
     else return -1;
}

int main(void) {
     int x1, y1, x2, y2, x3, y3, x4, y4, tri;
     scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
     scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
     if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) < 0 && ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) < 0) printf("1");
     else printf("0");
     return 0;
}