#include <stdio.h>

/*
문제 : L, R, A가 주어질 때, A를 L과 R 중 아무 것으로나 쓸 수 있다면, L과 R을 같은 수로 맞추려고 할 때,
최대 합이 몇이 될 수 있는지 구한다.

해결 방법 : A를 둘 중 작은 것으로 몰아준 다음, 남는다면 균등하게 분배해주는 것이 최선이다. 이 과정에서 A가 모자라진다면
거기서 바로 종료하면 된다.

주요 알고리즘 : 수학

출처 : 한양대E 2018 P2번
*/

int main(void) {
    int l, r, a;
    scanf("%d %d %d", &l, &r, &a);
    if (l > r) {
        if (a < l - r) {
            printf("%d", (r + a) * 2);
            return 0;
        }
        else {
            a -= l - r;
            r = l;
        }
    }
    else if (r > l) {
        if (a < r - l) {
            printf("%d", (l + a) * 2);
            return 0;
        }
        else {
            a -= r - l;
            l = r;
        }
    }
    if (a & 1) printf("%d", l + r + a - 1);
    else printf("%d", l + r + a);
    return 0;
}