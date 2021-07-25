#include <stdio.h>

/*
문제 : 가방의 크기와 무게가 주어지면 조건에 맞는 가방인지 확인한다. (조건 생략)

해결 방법 : 조건을 확인한 후 판단하면 된다.

주요 알고리즘 : 구현?

출처 : Phuket 2013 I번
*/

int main(void) {
    int t, r = 0;
    double l, d, h, w;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lf %lf %lf %lf", &l, &d, &h, &w);
        if (((l > 56.005 || d > 45.005 || h > 25.005) && (l + d + h) > 125.005) || w > 7.005) printf("0\n");
        else {
            printf("1\n");
            r++;
        }
    }
    printf("%d", r);
    return 0;
}