#include <stdio.h>

/*
문제 : 주어진 수 V(V <= 3^20)를 3진법으로 표현하여 출력한다.

해결 방법 : V의 각 자릿수를 저장한 다음 출력하면 된다. 순서가 반대가 됨과 0의 경우에 유의한다.

주요 알고리즘 : 수학, 구현

출처 : NWERC 2017 PC번
*/

int r[32];

int main(void) {
    int n, p = 0;
    long long v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v);
        if (v == 0) printf("0");
        for (; v; v /= 3) r[p++] = v % 3;
        while (p) printf("%d", r[--p]);
        printf("\n");
    }
    return 0;
}