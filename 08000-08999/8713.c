#include <stdio.h>

/*
문제 : 두 정수 A, B(|A|, |B| <= 10000)가 주어질 때, 사이에 +, -, * 중 답이 가장 커지는 것을 골라 넣고 식을 완성한다.
단, 그러한 경우가 두 개 이상인 경우 NIE를 출력하고, 출력시에 음수에는 괄호를 쳐야 한다.

해결 방법 : 3가지 경우를 각각 해본다. 중간에 답이 가장 큰 경우와 동일하다면 더 큰 것이 나올 때 까지 체크해둔다.
체크가 되어있는 경우에는 NIE를 출력하고 그 외에는 그 연산자를 찾아 음수에 유의하며 계산하면 된다.

주요 알고리즘 : 구현, 케이스 워크

출처 : ILOCAMP 2010B 1-4번
*/

int main(void) {
    int a, b, best = -103000, bop = -1;
    scanf("%d %d", &a, &b);
    if (a + b > best) {
        best = a + b;
        bop = 0;
    }
    else if (a + b == best) bop = -1;
    if (a - b > best) {
        best = a - b;
        bop = 1;
    }
    else if (a - b == best) bop = -1;
    if (a * b > best) {
        best = a * b;
        bop = 2;
    }
    else if (a * b == best) bop = -1;
    if (best == -103000) return 1;
    if (bop < 0) printf("NIE");
    else {
        if (a < 0) printf("(%d)", a);
        else printf("%d", a);
        printf("%c", bop == 0 ? '+' : bop == 1 ? '-' : '*');
        if (b < 0) printf("(%d)=", b);
        else printf("%d=", b);
        if (best < 0) printf("(%d)", best);
        else printf("%d", best);
    }
    return 0;
}