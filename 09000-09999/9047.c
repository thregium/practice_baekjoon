#include <stdio.h>
#include <stdlib.h>

/*
문제 : 모든 숫자가 같은 수를 제외한 4자리 자연수가 주어진다. 이때, Kaprekar 연산을 반복하여 이러한 모든 자연수가 6174가
된다는 것이 증명되어 있다. 몇 회 반복해야 6174가 되는지 구한다.
Kaprekar 연산은 각 자릿수를 재배열하여 나올 수 있는 가장 큰 수에서 가장 작은 수를 빼는 연산이다.
앞에 0이 오는 경우도 상관하지 않는다.

해결 방법 : 4자리 자연수는 앞에 0이 오는 경우를 포함해 10000가지이다. 따라서, 많아야 10000번 내로 주어지는 어떤 4자리 자연수든
6174가 될 것이다. 그러므로, 4자리 자연수에서 직접 Kaprekar 연산을 해보면 된다.
Kaprekar 연산은 각 자릿수를 구한 다음, 정렬하여 가장 큰 숫자부터 오는 수에서 가장 작은 숫자부터 오는 수를 빼면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 정렬

출처 : Seoul 2008I B번
*/

int nm[4];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        if (n > 9999) return 1;
        for (r = 0; n != 6174; r++) {
            nm[0] = n / 1000;
            nm[1] = n / 100 % 10;
            nm[2] = n / 10 % 10;
            nm[3] = n % 10;
            qsort(nm, 4, sizeof(int), cmp1);
            n = (nm[3] * 999 + nm[2] * 90 - nm[1] * 90 - nm[0] * 999);
        }
        printf("%d\n", r);
    }
    return 0;
}