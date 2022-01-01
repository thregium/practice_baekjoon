#include <stdio.h>

/*
문제 : 1 m^2당 씨를 심는데 드는 비용 C(C <= 100, 양의 실수)와 L(L <= 100)개의 씨를 겹치지 않는 심을 땅에 대한
길이와 너비 H, W(H, W <= 100, 양의 실수)가 주어질 때, 모든 땅에 씨를 심기 위해 필요한 비용을 구한다.
각 땅들은 직사각형 형태이다.

해결 방법 : 각 땅에 대한 H * W * C의 값을 더하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : UKIEPC 2016 I번
*/

int main(void) {
    int l;
    double c, w, h, r = 0.0;
    scanf("%lf%d", &c, &l);
    for (int i = 0; i < l; i++) {
        scanf("%lf %lf", &w, &h);
        r += w * h * c;
    }
    printf("%.9f", r);
    return 0;
}