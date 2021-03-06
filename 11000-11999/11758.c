#include <stdio.h>

/*
문제 : 점 3개의 좌표가 순서대로 주어질 때, 점 3개를 이으면 시계방향인지 반시계방향인지 여부를 출력한다.

해결 방법 : 점 3개를 꼭짓점으로 하는 삼각형의 넓이를 절댓값 처리 없이 구하면, 이 값이 양수인 경우 반시계, 음수인 경우 시계방향이다.

주요 알고리즘 : 기하학, CCW 알고리즘
*/

int main(void) {
     int x1, y1, x2, y2, x3, y3, tri;
     scanf("%d %d%d %d%d %d", &x1, &y1, &x2, &y2, &x3, &y3);
     tri = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3); //세 점을 꼭짓점으로 하는 삼각형의 면적 계산
     if (tri > 0) printf("1"); //양수인 경우 반시계
     else if (tri == 0) printf("0");
     else printf("-1"); //음수인 경우 시계방향
     return 0;
}