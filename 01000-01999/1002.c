#include <stdio.h>
#include <math.h>

/*
https://www.acmicpc.net/problem/1002

문제 : 특정한 두 지점(x1, y1), (x2, y2)에서 각각 r1, r2만큼 떨어진 지점이 평면 상에 몇 군데 존재하는지 출력한다.

해결 방법 : 특정한 지점에서 일정한 거리만큼 떨어진 지점을 이으면 원이 된다. 따라서 두 점에서 반지름이 r1, r2인 원의 교점을 찾으면 된다.
두 원의 교점이 1개인 경우는 두 원이 외접 또는 내접하는 경우이고, 0개인 경우는 두 원이 만나지 않거나 한 원이 다른 원을 포함하는 경우,
무한대인 경우는 두 원이 같은 경우이고, 2개인 경우는 그 외의 경우이다.

주요 알고리즘 : 기하학, case work
*/

int main(void) {
     int t, x1, y1, r1, x2, y2, r2;
     double d; //두 지점 사이의 거리
     scanf("%d", &t);
     for (int i = 0; i < t; i++) {
          scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
          d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
          if (d == 0) {
			  //두 원의 중점이 같은 경우
               if (r2 == r1) printf("-1\n");
               else printf("0\n");
          }
          else {
               if (d == r1 + r2 || d == abs(r1 - r2)) printf("1\n");
               else if (d < r1 + r2 && d > abs(r1 - r2)) printf("2\n");
               else printf("0\n");
          }
          //printf("%lf", d);
     }
     return 0;
}
