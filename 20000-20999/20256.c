#include <stdio.h>

/*
문제 : 자연수 N(N < 2 ^15)이 주어질 때, 조건을 만족하는 두 자연수 A * B(1 <= A <= B <= A * 2)로
나타낼 수 있는 지 구한다. 이를 T(T <= 1000)번 반복한다.

해결 방법 : A * B가 32768보다 작은 모든 경우를 하나씩 확인하면서 조건을 만족하는 수를 모두 체크한다.
그리고 각 수가 나올 때 마다 답을 출력해 나가면 된다.

주요 알고리즘 : 수학, 브루트 포스

출처 : Taipei 2020 A번
*/

int res[32768];

int main(void) {
    int t, n;
    for (int a = 1; a * a < 32768; a++) {
        for (int b = a; b <= a * 2 && a * b < 32768; b++) res[a * b] = 1;
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        printf("%d\n", res[n]);
    }
    return 0;
}