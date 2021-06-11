#include <stdio.h>

/*
문제 : 4개의 자연수로 이루어져 있고 가장 큰 수가 J(J <= 99)인 증가하는 수열의 가짓수를 구한다.

해결 방법 : J - 1개의 수들 가운데 3개를 뽑는 경우와 같으므로 (J - 1)C3의 값을 구하면 된다.

주요 알고리즘 : 수학, 조합론

출처 : CCC 2012 S1번
*/

int main(void) {
    int j;
    scanf("%d", &j);
    if (j < 4) printf("0");
    else printf("%d", (j - 1) * (j - 2) * (j - 3) / 6);
    return 0;
}