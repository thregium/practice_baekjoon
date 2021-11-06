#include <stdio.h>

/*
문제 : N(N <= 100)개의 삼지선다 문제의 답지가 주어질 때, 문제에 주어진 세 방식 중 가장 정답을 많이 맞춘 방식의
정답 수와 그러한 방식들을 출력한다.

해결 방법 : 각 문제마다 각 방식들로 찍을 때 맞는지 확인한다. 모든 문제를 확인한 후 가장 많이 맞은 방식의
맞은 횟수를 출력하고 그 방식도 출력하면 된다.

주요 알고리즘 : 구현

출처 : COCI 08/09#1 2번
*/

char s[128];
const char* ax = "ABC";
const char* bx = "BABC";
const char* cx = "CCAABB";

int main(void) {
    int n, a = 0, b = 0, c = 0, r;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == ax[i % 3]) a++;
        if (s[i] == bx[i & 3]) b++;
        if (s[i] == cx[i % 6]) c++;
    }
    r = a > b && a > c ? a : b > c ? b : c;
    printf("%d\n", r);
    if (a == r) printf("Adrian\n");
    if (b == r) printf("Bruno\n");
    if (c == r) printf("Goran\n");
    return 0;
}