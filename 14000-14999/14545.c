#include <stdio.h>

/*
문제 : L * L(L <= 10^6)칸의 정사각형 격자가 있을 때, 이 격자에서 찾을 수 있는 정사각형의 수를 구한다.

해결 방법 : 길이가 1인 정사각형은 L * L개, 2인 정사각형은 (L - 1) * (L - 1)개 ... L인 정사각형은 1 * 1개 찾을 수 있다.
따라서, for문을 이용해 1부터 L까지의 제곱의 합을 구하면 된다.

주요 알고리즘 : 수학

출처 : Benin 2016 C번
*/

int main(void) {
    int p, l, r = 0;
    scanf("%d", &p);
    for (int pp = 0; pp < p; pp++) {
        scanf("%d", &l);
        r = 0;
        for (int i = l; i > 0; i--) {
            r += i * i;
        }
        printf("%d\n", r);
    }
    return 0;
}