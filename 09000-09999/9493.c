#include <stdio.h>
#include <math.h>

/*
문제 : 거리 M(M <= 10000) km를 A km / h로 갈 때와 B(0 < A < B <= 1000) km / h로 갈 때 걸리는 시간을
초 단위로 반올림하여 출력한다.

해결 방법 : A로 갈 때 걸리는 시간은 M / A이고, B로는 M / B이다. M / A가 더 크므로 M / A - M / B를 구한 다음,
3600을 곱하면 걸리는 초가 되고, round()함수를 이용해 반올림한 다음, 시, 분, 초를 나누어 출력하면 된다.

주요 알고리즘 : 수학

출처 : SEUSA 2013D2 I번
*/

int main(void) {
    int m, a, b, r;
    //freopen("E:\\PS\\ICPC\\North America\\Southeast USA\\2013\\speed.judge", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Southeast USA\\2013\\speed.out", "w", stdout);
    while (1) {
        scanf("%d %d %d", &m, &a, &b);
        if (m == 0) break;
        r = round(((double)m / a - (double)m / b) * 3600 + 0.000001);
        printf("%d:%02d:%02d\n", r / 3600, r / 60 % 60, r % 60);
    }
    return 0;
}