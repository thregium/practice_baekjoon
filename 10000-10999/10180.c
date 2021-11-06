#include <stdio.h>

/*
문제 : N(N <= 100)개의 우주선 가운데 D(D <= 10^6)의 거리를 갈 수 있는 우주선의 개수를 구한다.
각 우주선은 f_i의 연료가 있고, 속도는 v_i이며, 단위 시간당 연료 소비율은 c_i이다.

해결 방법 : 각 우주선이 D까지 가기 위해 소비하는 연료의 양은 d * c_i / v_i이다. 이 값이 f_i 이하면 갈 수 있다.
여기서 실수 오차를 피하기 위해 d * c_i와 v_i * f_i를 비교해서 전자가 더 크거나 같다면 갈 수 있고,
후자가 더 크다면 갈 수 없다고 하는 것이 좋다. 이제 이를 이용해 갈 수 있는 우주선의 수를 세서 출력하면 된다.

주요 알고리즘 : 수학

출처 : PLU 2014N 11번
*/

int main(void) {
    int t, n, d, v, f, c, r;
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2013\\_IO\\Assignments.in", "r", stdin);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &d);
        r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &v, &f, &c);
            if (f * v >= d * c) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}