#include <stdio.h>

/*
문제 : 현재 시각과 알람 시계의 설정 시각이 분 단위로 주어질 때, 알람이 울리기까지 몇 분 남았는지 구한다.

해결 방법 : 두 시각을 분 단위로 계산한 다음, 알람 시계의 시각이 더 빠르다면 1440분(1일)을 더한다.
그 다음 두 시각의 차이를 구하면 된다.

주요 알고리즘 : 구현, 사칙연산

출처 : Brasil 2009 B번
*/

int main(void) {
    int h1, m1, h2, m2, t1, t2;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2009\\alarme.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2009\\alarme.out", "w", stdout);
    while (1) {
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;
        t1 = h1 * 60 + m1, t2 = h2 * 60 + m2;
        if (t1 > t2) t2 += 1440;
        printf("%d\n", (t2 - t1));
    }
    return 0;
}