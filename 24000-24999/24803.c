#include <stdio.h>

/*
문제 : 금, 은, 동의 카드가 합쳐서 5장 이내로 있다. 금 카드는 3, 은은 2, 동은 1의 가치를 갖는다.
이때, 이 카드들로 살 수 있는 가장 좋은 것들을 출력한다.

해결 방법 : 경우를 나누어 해결하면 된다.

주요 알고리즘 : 구현, 케이스 워크

출처 : VTH 2017 K번
*/

int main(void) {
    int g, s, c, b = 0, v = 0, t = 0;
    scanf("%d %d %d", &g, &s, &c);
    b = g * 3 + s * 2 + c;
    if (b >= 8) v = 3;
    else if (b >= 5) v = 2;
    else if (b >= 2) v = 1;
    if (b >= 6) t = 3;
    else if (b >= 3) t = 2;
    else if (b >= 0) t = 1;
    if (v) printf("%s or ", v == 3 ? "Province" : v == 2 ? "Duchy" : "Estate");
    printf("%s", t == 3 ? "Gold" : t == 2 ? "Silver" : "Copper");
    return 0;
}