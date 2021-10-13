#include <stdio.h>
#include <math.h>

/*
문제 : 수소 이온 또는 수산화 이온의 농도가 주어질 때, pH값을 구한다. 각 이온에 따른 pH의 값에 대한 식이 문제에 주어진다.

해결 방법 : 문제에 주어진대로 경우를 나누어 식을 적용하면 된다.

주요 알고리즘 : 수학

출처 : PLU 2014A 2번
*/

char s[8];

int main(void) {
    int t;
    double v;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s = %lf", s, &v);
        if (s[0] == 'H') {
            printf("%.2lf\n", -log10(v));
        }
        else {
            printf("%.2lf\n", 14 + log10(v));
        }
    }
    return 0;
}