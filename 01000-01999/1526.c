#include <stdio.h>

/*
문제 : N(N <= 10^6)이하의 자연수들 가운데 4와 7만으로 이루어진 가장 큰 수를 구한다.

해결 방법 : N 이하의 모든 수에 대해 4와 7로만 이루어져 있는 수가 있는지 확인한다. 확인은 10으로 나눠가며
자릿수들을 살펴보면 된다.

주요 알고리즘 : 브루트 포스, 구현
*/

int isk(int n) {
    int num[9] = {0, };
    int i;
    for (i = 0; n; i++) {
        num[i] = n % 10;
        n /= 10;
    }
    for (int j = 0; j < i; j++) {
        if (num[j] != 4 && num[j] != 7) return 0;
    }
    return 1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    while (1) {
        if (isk(n)) {
            printf("%d", n);
            break;
        }
        n--;
    }
    return 0;
}