#include <stdio.h>

/*
문제 : N(N <= 10)개의 홀로 이루어진 골프 코스가 있다. 홀수 번째 홀은 파가 2이고, 짝수번째는 3이다.
7타 이상은 7타로 취급한다면, 각 홀의 타수가 주어질 때, 언더파 또는 오버파 수를 출력한다.

해결 방법 : 각 홀 수마다 전체의 파 수 합은 floor(N * 5 / 2)로 구할 수 있다. 7 이상은 7로 취급한 타수의 합에서
전체 파 수 합을 빼면 답이 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : SwOI 2017Q 1번
*/

int main(void) {
    int n, x, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x > 7) s += 7;
        else s += x;
    }
    printf("%d", s - ((n * 5) >> 1));
    return 0;
}