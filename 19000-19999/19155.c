#include <stdio.h>

/*
문제 : 1부터 N(N <= 100000)까지의 자연수로 이루어진 순열이 주어질 때, 이 순열과 각 원소의 차의 합이 N 이상인
순열 중 하나를 출력한다.

해결 방법 : 각 수가 모두 다르다면 차의 합이 N 이상일 것이다. 따라서, 한 칸씩 값을 밀어내면 그러한 순열이 된다.

주요 알고리즘 : 수학, 구성적

출처 : Jakarta 2019 A번
*/

int main(void) {
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        printf("%d ", a == n ? 1 : a + 1);
    }
    return 0;
}