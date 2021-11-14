#include <stdio.h>

/*
문제 : 높이 10의 완전 힙 트리에서 두 정점 A, B가 주어질 때, AB의 최소 공통 조상의 값에 10을 곱한 것을 구한다.

해결 방법 : 각 정점이 같아질 때 까지 더 큰 정점의 값을 절반으로 줄여나가면 같아질 때의 정점이 LCA이다.
따라서, 이 값에 10을 곱한 것이 답이 된다.

주요 알고리즘 : 수학

출처 : Coders 2016R2 PA번
*/

int main(void) {
    int t, a, b;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        while (a != b) {
            if (a > b) a >>= 1;
            if (b > a) b >>= 1;
        }
        printf("%d\n", a * 10);
    }
    return 0;
}