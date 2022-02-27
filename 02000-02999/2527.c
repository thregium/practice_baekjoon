#include <stdio.h>

/*
문제 : 정수 점(1 <=, <= 50000)을 꼭짓점으로 하고 좌표축에 평행한 두 직사각형이 주어질 때,
두 직사각형 사이 겹치는 부분이 직사각형인지 선인지 점인지 없는 지 구한다.

해결 방법 : X좌표와 Y좌표에 대해 겹치는 부분이 점인 지 구간인 지 없는 지 확인한다.
두 좌표 중 하나라도 겹치는 부분이 없다면 두 직사각형은 겹치지 않는다.
둘 다 점에서 겹치면 직사각형도 점에서 겹치고, 둘 다 구간에서 겹치면 직사각형은 직사각형으로 겹친다.
그 외의 경우에는 선으로 겹친다.

주요 알고리즘 : 기하학, 케이스 워크

출처 : 정올 2012지 초3번
*/

int iscommon(int s1, int e1, int s2, int e2) {
    if (e1 == s2 || e2 == s1) return 1;
    else if (e1 < s2 || e2 < s1) return 0;
    else return 2;
}

int main(void) {
    int x1, y1, p1, q1, x2, y2, p2, q2, r1, r2;
    for (int i = 0; i < 4; i++) {
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &p1, &q1, &x2, &y2, &p2, &q2);
        r1 = iscommon(x1, p1, x2, p2);
        r2 = iscommon(y1, q1, y2, q2);
        if (r1 == 0 || r2 == 0) printf("d\n");
        else if (r1 == 1 && r2 == 1) printf("c\n");
        else if (r1 == 2 && r2 == 2) printf("a\n");
        else printf("b\n");
    }
    return 0;
}