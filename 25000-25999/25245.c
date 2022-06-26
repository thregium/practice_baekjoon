#include <stdio.h>

/*
문제 : N(N <= 10^18)개의 좌석이 일렬로 있을 때, 처음 오는 사람이 잡는 자리를 선택하면
나머지 사람들이 가장 멀리 떨어진 자리 가운데 무작위하게 앉더라도 항상 모든 사람이 1칸씩 떨어지도록
앉을 수 있는 지 확인하고, 있다면 그렇게 만들기 위해 앉아야 하는 자리를 구한다.

해결 방법 : 양쪽의 남은 좌석의 수가 0 또는 2의 거듭제곱 꼴로 남아야 한다.
따라서 왼쪽에 그만큼 남기는 경우에 대해 오른쪽도 조건을 만족하는 지 확인하고,
조건을 만족하는 것이 있다면 그때의 왼쪽 좌석수 + 1을, 없다면 impossible을 출력하면 된다.

주요 알고리즘 : 수학

출처 : GCPC 2021 A번
*/

int ispoweroftwo(long long x) {
    return ((x & -x) == x);
}

int main(void) {
    long long n;
    scanf("%lld", &n);
    if (ispoweroftwo(n - 1)) {
        printf("1");
        return 0;
    }
    for (long long i = 2; i <= n; i <<= 1) {
        if (ispoweroftwo(n - i - 1)) {
            printf("%lld", i + 1);
            return 0;
        }
    }
    printf("impossible");
    return 0;
}