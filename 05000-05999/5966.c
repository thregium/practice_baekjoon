#include <stdio.h>

/*
문제 : N(N <= 1000)개의 길이 K_i(K_i <= 200)인 '>'와 '<'로 이루어진 문자열이 주어진다.
모든 '>'와 '<'를 서로 순서를 유지하며 짝지을 수 있는지 구한다.

해결 방법 : 현재까지의 '>'의 개수를 저장하는 변수를 둔다. '>'가 들어올 때 마다 1씩 올리고, '<'가 들어올 때 마다 1씩 줄인다.
이때, 중간에 이 값이 음수로 내려가면 불가능한 경우이다. 또한, 마지막에 이 값이 0이 아니더라도 불가능한 경우가 된다.
그 외의 경우에는 가능하다.

주요 알고리즘 : 자료 구조, 스택

출처 : USACO 2011F B1번
*/

char p[256];

int main(void) {
    int n, k, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &k, p);
        t = 0;
        for (int j = 0; j < k; j++) {
            if (p[j] == '>') t++;
            else {
                if (t > 0) t--;
                else {
                    t = -1;
                    break;
                }
            }
        }
        if (t == 0) printf("legal\n");
        else printf("illegal\n");
    }
    return 0;
}