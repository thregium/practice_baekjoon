#include <stdio.h>

/*
문제 : 체스판에서 두 칸의 좌표가 알파벳-숫자 형태와 수 형태로 주어질 때, 두 칸이 같은 색인지 구한다.

해결 방법 : 두 가지 방법의 가로줄과 세로줄을 찾은 뒤 둘의 합이 홀수인지 짝수인지를 통해 색을 구할 수 있다.
이들이 같은지 확인해 보면 된다.

주요 알고리즘 : 수학
*/

char s[8];

int main(void) {
    int t, n, c1, c2;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s %d", s, &n);
        c1 = (((s[0] - 'A') + (s[1] - '1')) & 1);
        c2 = ((((n - 1) >> 3) + ((n - 1) & 7)) & 1);
        if (c1 == c2) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}