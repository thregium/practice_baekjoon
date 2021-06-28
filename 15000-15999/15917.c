#include <stdio.h>

/*
문제 : 주어진 수 A가 2의 거듭제곱 꼴인지 구한다. 이는 A & -A == A라는 연산을 통해 구할 수 있다고 한다.

해결 방법 : 문제에서 주어진대로 풀면 된다.

주요 알고리즘 : 구현

출처 : 선린 2회 B번
*/

int main(void) {
    int q, a;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &a);
        if ((a & -a) == a) printf("1\n");
        else printf("0\n");
    }
    return 0;
}