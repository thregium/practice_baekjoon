#include <stdio.h>

/*
문제 : 지그재그 형태로 분수들을 나열할 때 X(X <= 10^7) 번째 분수를 출력한다.

해결 방법 : 분수가 지그재그 형태로 놓여 있으므로 두 방향을 서로 분리해서 생각한다.
X의 크기가 적당하므로 직접 구현하더라도 시간초과가 되지 않는다.

주요 알고리즘 : 수학, 구현
*/

int main(void) {
     int x, i, a, b, s = 0;
     scanf("%d", &x);
     for (i = 0; i < x; s++) i += s;
     a = i - x + 1;
     b = s - (i - x + 1);
     if (s % 2) printf("%d/%d", b, a);
     else printf("%d/%d", a, b);
     return 0;
}