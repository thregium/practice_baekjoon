#include <stdio.h>

/*
문제 : 문제에서 주어진 형태의 높이 H(H <= 30)의 트리에서 루트부터 움직인 기록이 주어질 때, 해당 노드의 번호를 구한다.

해결 방법 : N에서 노드의 번호를 빼보면 힙의 번호와 같아진다. 따라서, 힙의 번호를 구한 다음, 2^(H + 1)에서 그 값을 빼면 된다.

주요 알고리즘 : 수학, 트리

출처 : KTH 2014 A번
*/

char s[32];

int main(void) {
    int h, r = 1;
    scanf("%d %s", &h, s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'L') r <<= 1;
        else if (s[i] == 'R') r = (r << 1) + 1;
        else return 1;
    }
    printf("%lld", (1LL << (h + 1)) - r);
    return 0;
}