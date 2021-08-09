#include <stdio.h>

/*
문제 : kg, lb, l, g(갤런)로 된 물체의 무게 또는 부피가 주어질 때, 다른 단위로 바꾸어 출력한다. (단위표 생략)

해결 방법 : 물체의 단위를 문자열로 받은 다음 문자열을 살펴보며 어떤 단위인지 확인하고 경우에 따라 바꾸면 된다.

주요 알고리즘 : 구현, 사칙연산, 문자열

출처 : GNY 2007 B번
*/

char buff[8];

int main(void) {
    int t;
    double x;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lf %s", &x, buff);
        if (buff[0] == 'k') printf("%.4f lb\n", x * 2.2046);
        else if (buff[0] == 'l' && buff[1] == 'b') printf("%.4f kg\n", x * 0.4536);
        else if (buff[0] == 'l') printf("%.4f g\n", x * 0.2642);
        else printf("%.4f l\n", x * 3.7854);
    }
    return 0;
}