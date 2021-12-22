#include <stdio.h>
#include <string.h>
#define RT2 1.414213562373

/*
문제 : (X, Y)에서 시작하여 N - 1(N <= 100)회의 이동이 주어질 때, 도착하는 곳의 위치를 구한다.
각 이동은 동, 서, 남, 북, 북동, 북서, 남서, 남동 중 하나이며 직선 이동이다. 주어지는 각 좌표의 값은 0 이상 100 이하의 정수이다.

해결 방법 : 동, 서, 남, 북 이동은 이전 위치에서, X 또는 Y 값을 더하거나 빼는 방식으로 간단히 구할 수 있다.
그 외 방향으로의 이동은 이전 위치에서 X, Y의 값을 sqrt(2)만큼 나누어 더하거나 빼는 방식으로 구할 수 있다.
모든 이동을 한 후 나오는 값을 출력하면 된다.

주요 알고리즘 : 수학, 기하학

출처 : ECRC 2017 PA번
*/

char buff[8];

int main(void) {
    int n;
    double x, y, d;
    scanf("%d%lf %lf", &n, &x, &y);
    for (int i = 1; i < n; i++) {
        scanf("%s %lf", buff, &d);
        if (!strcmp(buff, "N")) y += d;
        else if (!strcmp(buff, "E")) x += d;
        else if (!strcmp(buff, "S")) y -= d;
        else if (!strcmp(buff, "W")) x -= d;
        else if (!strcmp(buff, "NE")) {
            x += d / RT2;
            y += d / RT2;
        }
        else if (!strcmp(buff, "SE")) {
            x += d / RT2;
            y -= d / RT2;
        }
        else if (!strcmp(buff, "SW")) {
            x -= d / RT2;
            y -= d / RT2;
        }
        else if (!strcmp(buff, "NW")) {
            x -= d / RT2;
            y += d / RT2;
        }
        else return 1;
    }
    printf("%.9lf %.9lf", x, y);
    return 0;
}