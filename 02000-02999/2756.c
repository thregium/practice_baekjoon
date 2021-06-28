#include <stdio.h>
#include <math.h>

/*
문제 : 두 명이 3개씩 다트를 던져서 맞은 위치가 주어질 때, 두 사람의 점수를 비교한다.

해결 방법 : 다트의 영역에 따른 점수를 구하고, 그에 따라 점수를 집계한다. 영역에 따른 점수는 중심과의 거리를 통해 구하면 된다.

주요 알고리즘 : 기하학, 피타고라스 정리

출처 : GNY 2004 A번
*/

double getdist(double x, double y) {
    return sqrt(x * x + y * y);
}

int getscore(double x, double y) {
    double dist = getdist(x, y);
    if (dist <= 3) return 100;
    else if (dist <= 6) return 80;
    else if (dist <= 9) return 60;
    else if (dist <= 12) return 40;
    else if (dist <= 15) return 20;
    else return 0;
}

int main(void) {
    int t, a, b;
    double x, y;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        a = 0;
        b = 0;
        for (int i = 0; i < 3; i++) {
            scanf("%lf %lf", &x, &y);
            a += getscore(x, y);
        }
        for (int i = 0; i < 3; i++) {
            scanf("%lf %lf", &x, &y);
            b += getscore(x, y);
        }
        printf("SCORE: %d to %d, ", a, b);
        if (a > b) printf("PLAYER 1 WINS.\n");
        else if (a == b) printf("TIE.\n");
        else printf("PLAYER 2 WINS.\n");
    }
    return 0;
}