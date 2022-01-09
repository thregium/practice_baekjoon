#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

/*
문제 : N(N <= 100)개의 점을 차례로 이어 만들어진 아래로 볼록한 형태의 선분 모임이 주어진다.
이때, X좌표 A가 왼쪽 접지면이고 한 변의 길이가 1인 정사각형을 X좌표 양수 방향으로 굴려
B(0 <= A < B <= 200)까지 이동시킬 때, 최종적으로 정사각형이 접지한 면을 구한다.
주어지는 모든 점은 0 이상 200 이하의 정수 점이며, 실수 오차에 의해 답이 달라지는 경우는 주어지지 않는다.
정사각형은 미끄러지지 않고 돌기만 하며, B까지 이동한 것은 오른쪽 끝 점이 B 이상이 된 경우이다.

해결 방법 : 정사각형은 다음 선분으로 이동하기 전까지 해당 선분을 타고 1씩의 거리로 움직이게 된다.
다음 선분을 타는 경우는 3가지가 있는데, 하나는 다음 선분과의 거리가 1 이하가 된 경우,
또 하나는 다음 선분과 이루는 각이 예각이고, 거리가 sqrt(2) 이하가 된 경우, 마지막으로 다다음 선분과 이루는 각이
예각이고, 거리가 sqrt(2) 이하가 된 경우이다.
각 경우에 대해 거리는 점과 선분의 거리를 이용해 구할 수 있고, 다음 선분으로 이동하는 경우 만나는 점은
제2 코사인 법칙을 이용하여 올라간 길이를 구하여 알 수 있다. 또한, 매번 이동 거리는 기울기로 간단히 알 수 있다.
이를 이용하여 왼쪽 점이 B까지 이동한 상태의 회전 횟수를 구하고 4로 나눈 나머지를 구하면 답을 알 수 있다.
이 과정에서 발생할 수 있는 예외 상황들에 대한 처리를 잘 해야 한다.

주요 알고리즘 : 기하학, 케이스 워크

출처 : JAG 2011S4 G번
*/

double point[256][2];
char* color[] = { "Red", "Green", "Blue", "White" };

double getangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    //두 선분이 이루는 각을 구한다.
    double cross = (x2 - x1) * (x4 - x3) + (y2 - y1) * (y4 - y3);
    double l1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double l2 = sqrt((x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3));
    return PI - acos(cross / l1 / l2);
}

double pointlinedist(double px, double py, double x1, double y1, double x2, double y2) {
    //점과 선분과의 거리를 구한다.
    if (x1 == x2) return fabs(px - x1);
    double dxy = fabs((y2 - y1) / (x2 - x1)) + fabs((x2 - x1) / (y2 - y1));
    double yp = y1 + (y2 - y1) * ((px - x1) / (x2 - x1));
    double cx = px + fabs(py - yp) / dxy;
    double cy = y1 + (y2 - y1) * ((cx - x1) / (x2 - x1));
    //printf("%lf\n", sqrt((px - cx) * (px - cx) + (py - cy) * (py - cy)));
    if (cx < x1) return sqrt((x1 - px) * (x1 - px) + (y1 - py) * (y1 - py));
    else return sqrt((px - cx) * (px - cx) + (py - cy) * (py - cy));
}

double getcrossx(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    //두 직선이 만나는 지점의 X좌표를 구한다.
    double d1 = (y2 - y1) / (x2 - x1);
    double d2 = (y4 - y3) / (x4 - x3);
    double in1 = y1 - x1 * d1;
    double in2 = y3 - x3 * d2;
    return (in1 - in2) / (d2 - d1);
}

int main(void) {
    int n, itv = 0, cnt = 0; //itv: 현재 선분 구간, cnt: 회전 횟수
    double a, b, y, slop, an, an2, xdiff, cx, t; //a: 현재 정사각형의 왼쪽 x좌표, b: 목표 x좌표, \
    y: 현재 정사각형의 왼쪽 y좌표, slop: 현재 선분의 경사, xdiff: 선분을 따라 1 이동시 x좌표 변화량\
    an: 현재 선분과 다음 선분의 각(라디안), an2: 현재 선분과 다다음 선분의 각(라디안), \
    cx: 현재 선분과 다다음 선분의 직선으로 볼 시 교차점 X좌표, t: 다음 선분으로 올라가는 길이
    scanf("%d %lf %lf", &n, &a, &b);
    if (n < 2) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &point[i][0], &point[i][1]);
    }
    //다음 선분을 임의로 추가한다.
    point[n][0] = point[n - 1][0] * 2 - point[n - 2][0];
    point[n][1] = point[n - 1][1] * 2 - point[n - 2][1];
    slop = (point[1][1] - point[0][1]) / (point[1][0] - point[0][0]);
    xdiff = 1.0 / sqrt(slop * slop + 1);
    while (a < b) {
        y = point[itv][1] + (point[itv + 1][1] - point[itv][1]) *
            ((a - point[itv][0]) / (point[itv + 1][0] - point[itv][0]));
        //printf("%lf %lf\n", a, y); //현재 좌표 출력(디버그용)
        an = getangle(point[itv][0], point[itv][1], point[itv + 1][0], point[itv + 1][1],
            point[itv + 1][0], point[itv + 1][1], point[itv + 2][0], point[itv + 2][1]);
        an2 = getangle(point[itv][0], point[itv][1], point[itv + 1][0], point[itv + 1][1],
            point[itv + 2][0], point[itv + 2][1], point[itv + 3][0], point[itv + 3][1]);
        if (pointlinedist(a, y, point[itv + 1][0], point[itv + 1][1], point[itv + 2][0], point[itv + 2][1]) < 1
            && itv < n - 2) {
            //다음 선분으로 넘어가는 경우(90도 회전)
            t = (point[itv + 1][0] - a) * (1.0 / xdiff);
            t = cos(an) * t + sqrt((t * t) * (cos(an) * cos(an) - 1) + 1);
            itv++;
            slop = (point[itv + 1][1] - point[itv][1]) / (point[itv + 1][0] - point[itv][0]);
            xdiff = 1.0 / sqrt(slop * slop + 1);
            a = point[itv][0] + t * xdiff;
        }
        else if (pointlinedist(a, y, point[itv + 1][0], point[itv + 1][1],
            point[itv + 2][0], point[itv + 2][1]) < sqrt(2) && an < PI / 2) {
            //다음 선분으로 넘어가는 경우(180도 회전)
            t = (point[itv + 1][0] - a) * (1.0 / xdiff);
            t = cos(an) * t + sqrt((t * t) * (cos(an) * cos(an) - 1) + 2);
            itv++;
            cnt++;
            slop = (point[itv + 1][1] - point[itv][1]) / (point[itv + 1][0] - point[itv][0]);
            xdiff = 1.0 / sqrt(slop * slop + 1);
            a = point[itv][0] + t * xdiff;
        }
        else if (pointlinedist(a, y, point[itv + 2][0], point[itv + 2][1],
            point[itv + 3][0], point[itv + 3][1]) < sqrt(2) && an2 < PI / 2 && itv < n - 3) {
            //다다음 선분으로 넘어가는 경우(180도 회전)
            cx = getcrossx(point[itv][0], point[itv][1], point[itv + 1][0], point[itv + 1][1],
                point[itv + 2][0], point[itv + 2][1], point[itv + 3][0], point[itv + 3][1]);
            t = (cx - a) * (1.0 / xdiff);
            t = cos(an2) * t + sqrt((t * t) * (cos(an2) * cos(an2) - 1) + 2);
            itv += 2;
            cnt++;
            slop = (point[itv + 1][1] - point[itv][1]) / (point[itv + 1][0] - point[itv][0]);
            xdiff = 1.0 / sqrt(slop * slop + 1);
            a = cx + t * xdiff;
        }
        else a += xdiff;
        if (a > b) break;
        cnt++;
    }
    //printf("%d\n", cnt);
    printf("%s", color[cnt & 3]);
    return 0;
}