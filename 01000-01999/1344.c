#include <stdio.h>

/*
문제 : 90분간 하는 축구에서 5분 기준 두 팀의 득점 확률이 백분율로 주어질 때, 두 팀 중 한 팀이라도
득점 수가 소수일 확률을 구한다.

해결 방법 : 시간과 양 팀의 득점 횟수로 재귀를 한다. 이때, 한번 확인한 것은 다시 확인하지 않도록
메모이제이션을 해줘야 한다. 최대 득점 가능 수는 18개에 불과하므로 소수 여부는 하드코딩해도 된다.
각 확률은 4가지로 나누어 양 팀의 득점 여부에 따라 들어가면 된다.

주요 알고리즘 : DP, 확률론

출처 : SRM 422 D1A / D2B
*/

int isodd[20] = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1 };
double mem[32][32][32];
char chk[32][32][32];

double getprob(int t, int a, int b, int ag, int bg, double p) {
    if (t == 18) return (isodd[ag] | isodd[bg]) * p;
    if (chk[t][ag][bg]) return mem[t][ag][bg];
    chk[t][ag][bg] = 1;
    return mem[t][ag][bg] = getprob(t + 1, a, b, ag, bg, p * (100 - a) * (100 - b) / 10000.0)
        + getprob(t + 1, a, b, ag, bg + 1, p * (100 - a) * b / 10000.0)
        + getprob(t + 1, a, b, ag + 1, bg, p * a * (100 - b) / 10000.0)
        + getprob(t + 1, a, b, ag + 1, bg + 1, p * a * b / 10000.0);
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%.9f", getprob(0, a, b, 0, 0, 1.0));
    return 0;
}