#include <stdio.h>
#include <stdlib.h>

/*
문제 : 정삼각형 모양을 작은 삼각형들로 나누어 순서대로 번호를 붙였다.
A번째 삼각형에서 B(A, B <= 10^9)번째 삼각형으로 가는 최단거리를 구한다.

해결 방법 : 두 지점의 위치를 특정한 다음, 경우를 나누어 해결한다.

주요 알고리즘 : 수학, 케이스 워크
*/

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int a, b, ax = 0, ay = 0, bx = 0, by = 0, res;
    scanf("%d %d", &a, &b);
    if (a > b) swap(&a, &b);
    for (int i = 1;; i++) {
        if (i * i >= a) {
            ax = i - 1;
            ay = a - (i - 1) * (i - 1) - ax - 1;
            break;
        }
    }
    for (int i = 1;; i++) {
        if (i * i >= b) {
            bx = i - 1;
            by = b - (i - 1) * (i - 1) - bx - 1;
            break;
        }
    }

    res = bx - ax;
    if ((ax + ay) & 1) ax--;
    if (abs(ay - by) > bx - ax) res += abs(ay - by);
    else res += bx - ax - ((bx + by) & 1);
    printf("%d", res);
    return 0;
}