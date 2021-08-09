#include <stdio.h>

/*
문제 : N개의 박스와 M(M <= 50)개의 책이 있고, 각각의 용량이 주어질 때, 각 박스에 책들을 순서대로 가능한만큼 채워넣는 전략을
사용한다면 낭비하는 박스의 양은 얼만큼인지 구한다. 쓰지 않는 박스도 낭비하는 박스에 포함되고,
항상 전부 넣는 것이 가능한 경우만 주어진다.

해결 방법 : 항상 넣는 것이 가능한 경우만 주어지기 때문에, 전체 박스의 용량에서 책의 용량을 뺀 값이 낭비하는 박스의 용량이다.

주요 알고리즘 : 수학, 사칙연산
*/

int a[64], b[64];

int main(void) {
    int n, m, c = 0, cb = 0, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        r += a[i];
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        r -= b[i];
    }
    printf("%d", r);
    return 0;
}