#include <stdio.h>
#include <math.h>

/*
문제 : P(P <= 50)개의 점의 위치가 주어질 때, 트랙 내부 또는 경계에 있는 점의 개수를 구한다.
트랙은 직사각형의 양 옆에 반원이 연결된 형태이다.

해결 방법 : 각 점에 대해 직사각형과 양쪽 원 중 한 쪽 안에 있는지 여부를 확인한다. 하나라도 안쪽에 있다면
안에 있는 것이고 그 외에는 밖에 있는 것이다. 안에 있는 것의 개수를 세면 된다.

주요 알고리즘 : 기하학, 케이스 워크
*/

int sqr(int x) {
    return x * x;
}

int getdist(int x1, int y1, int x2, int y2) {
    return sqr(x1 - x2) + sqr(y1 - y2);
}

int main(void) {
    int w, h, x, y, p, rad, xx, yy, r = 0;
    scanf("%d %d %d %d %d", &w, &h, &x, &y, &p);
    rad = h / 2;
    for (int i = 0; i < p; i++) {
        scanf("%d %d", &xx, &yy);
        if (getdist(xx, yy, x, y + rad) <= rad * rad) r++;
        else if (getdist(xx, yy, x + w, y + rad) <= rad * rad) r++;
        else if (xx >= x && yy >= y && xx <= x + w && yy <= y + h) r++;
    }
    printf("%d", r);
    return 0;
}