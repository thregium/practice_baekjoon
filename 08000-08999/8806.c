#include <stdio.h>

/*
문제 : 두 명이 가위바위보 중 낼 것의 확률이 주어질 때, 두 명 중 이길 확률이 더 높은 사람을 찾는다.

해결 방법 : 두 명이 이길 확률은 각자 자신이 내는 것의 확률에 상대가 지는 것을 내는 확률을 전부 더하면 된다.
이를 구한 다음, 두 명의 확률 차가 일정(약 1E-6) 이하인 경우 서로 같은 것으로 보고 =를 출력하고
그 외에는 더 확률이 높은 사람을 출력하면 된다.

주요 알고리즘 : 수학

출처 : Spot 2010F 1-3번
*/

double p1[4], p2[4];

double ax(double a) {
    if (a < 0) return -a;
    else return a;
}

int main(void) {
    int z;
    double g, a;
    scanf("%d", &z);
    for (int zz = 0; zz < z; zz++) {
        scanf("%lf%lf%lf", &p1[0], &p1[1], &p1[2]);
        scanf("%lf%lf%lf", &p2[0], &p2[1], &p2[2]);
        if (ax(p1[0] + p1[1] + p1[2] - 1) > 0.000001) return 1;
        if (ax(p2[0] + p2[1] + p2[2] - 1) > 0.000001) return 1;
        g = 0.0, a = 0.0;
        for (int i = 0; i < 3; i++) {
            g += p1[i] * p2[(i + 2) % 3];
            a += p1[i] * p2[(i + 1) % 3];
        }
        if (ax(g - a) < 0.000000001) printf("=");
        else if (g > a) printf("GOSIA");
        else printf("ADAM");
        printf("\n");
    }
    return 0;
}