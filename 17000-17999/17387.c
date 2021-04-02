#include <stdio.h>

/*
문제 : 두 선분의 각 점마다 좌표가 주어질 때 두 선분이 교차하는지 여부를 출력한다.

해결 방법 :

주요 알고리즘 : 기하학, 선분의 교차 판정
*/

long long int big(long long a, long long b) {
     return a > b ? a : b;
}

long long int small(long long a, long long b) {
     return a < b ? a : b;
}

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
     long long int tri = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
     if (tri > 0) return 1;
     else if (tri == 0) return 0;
     else return -1;
}

int dotinline(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
     if (ccw(x1, y1, x2, y2, x3, y3)) return 0;
     if (x3 > big(x1, x2) || x3 < small(x1, x2) || y3 > big(y1, y2) || y3 < small(y1, y2)) return 0;
     else return 1;
}

int crossline(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3, long long x4, long long y4) {
     if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) < 0 && ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) < 0) return 1;
     else if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) && ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2)) return 0;
     if (dotinline(x1, y1, x2, y2, x3, y3) || dotinline(x1, y1, x2, y2, x4, y4) || dotinline(x3, y3, x4, y4, x1, y1) || dotinline(x3, y3, x4, y4, x2, y2)) return 1;
     else return 0;
}

int main(void) {
     int x1, y1, x2, y2, x3, y3, x4, y4, tri;
     scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
     scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
     printf("%d\n", crossline(x1, y1, x2, y2, x3, y3, x4, y4));
     return 0;
}