#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(3 <= N <= 100000)개의 자연수(<= 10^9)가 주어질 때, 이 자연수들의 간격을 모두 같게 만들기 위해
추가해야 하는 수의 개수를 구한다.

해결 방법 : 정렬한 각 인접한 수들의 차이의 최대공약수가 모두 같게 만들 수 있는 최소 간격이다.
따라서, 최대공약수를 구한 다음 최대공약수보다 차이가 크다면 최대공약수로 나눈 값 - 1개를 결괏값에 추가하는 것을 반복하면 된다.

주요 알고리즘 : 수학, 유클리드 호제법, 정렬

출처 : 정올 2010지 고2번
*/

int tre[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, g, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tre[i]);
    }
    qsort(tre, n, sizeof(int), cmp1);
    g = tre[1] - tre[0];
    for (int i = 2; i < n; i++) {
        g = gcd(g, tre[i] - tre[i - 1]);
    }
    for (int i = 1; i < n; i++) {
        r += (tre[i] - tre[i - 1]) / g - 1;
    }
    printf("%d", r);
    return 0;
}