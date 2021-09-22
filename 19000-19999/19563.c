#include <stdio.h>
#include <stdlib.h>

/*
문제 : (0, 0)에서 (A, B)(-10^9 <= A, B <= 10^9)로 C(C <= 2 * 10^9)번 상하좌우 이동을 통해 도달 가능한지 구한다.

해결 방법 : 만약 C가 (A, B)로 가는 최단거리보다(|A| + |B|) 적다면 도달 불가능하다. C가 그 이상인 경우에는
A + B와의 홀짝성이 같은 경우 도달 가능하고, 다르다면 도달 불가능하다.

주요 알고리즘 : 수학

출처 : 폴리매스 1회 A번
*/

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (abs(a) + abs(b) > c) printf("NO");
    else printf("%s", (((a + b) & 1) ^ (c & 1)) ? "NO" : "YES");
    return 0;
}