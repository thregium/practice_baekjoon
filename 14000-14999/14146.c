#include <stdio.h>

/*
문제 : [A, B](1 <= A <= B <= 2 * 10^6)에서 가장 약수가 많은 수의 약수 개수와,
그러한 수들의 목록을 구한다.

해결 방법 : 1부터 200만까지 200만 이하인 그 수의 배수들에 대해 약수의 개수를 늘려준다.
각 약수의 개수를 배열에 0으로 초기화시키고 점차 늘려가면 된다.
다시 A부터 B까지 확인하며 가장 약수가 많은 수의 약수 개수를 확인한 다음,
배열을 다시 돌며 그러한 수들의 목록을 출력하면 된다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스

출처 : CPC 2008 A번
*/

int dvs[2097152];

int main(void) {
    int a, b, best = -1, bn = -1;
    for (int i = 1; i <= 2000000; i++) {
        for (int j = i; j <= 2000000; j += i) dvs[j]++;
    }
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (dvs[i] > best) {
            best = dvs[i];
            bn = 1;
        }
        else if (dvs[i] == best) bn++;
    }
    printf("%d %d\n", best, bn);
    for (int i = a; i <= b; i++) {
        if (dvs[i] == best) printf("%d\n", i);
    }
    return 0;
}