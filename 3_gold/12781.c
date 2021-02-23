#include <stdio.h>

/*
문제 : 두 선분의 시작점과 끝점의 좌표가 주어질 때 두 선분이 교차하는지 여부를 출력한다.(단, 두 선분의 시작점과 끝점은 전부 한 볼록다각형의 모서리 위에 있다.)

해결 방법 : CCW 알고리즘을 이용하여 한 선분의 시작점과 끝점이 다른 선분에 대해 각각 반대 방향에 있는지 확인한다.

주요 알고리즘 : 기하학, 선분의 교차 판정
*/

int main(void) {
     int x1, y1, x2, y2, x3, y3, x4, y4;
     long long int tri1, tri2;
     scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
     tri1 = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
     tri2 = x1 * y2 + x2 * y4 + x4 * y1 - (x2 * y1 + x4 * y2 + x1 * y4);
     if (tri1 * tri2 < 0) printf("1");
     else printf("0");
     return 0;
}