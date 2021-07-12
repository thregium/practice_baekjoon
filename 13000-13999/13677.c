#include <stdio.h>

char s[524288], st[524288];
int sttop = 0;

/*
문제 : N자리 수에서 K(K < N <= 100)개의 숫자를 지워 만들 수 있는 가장 큰 수를 구한다.

해결 방법 : 스택을 이용해 맨 앞쪽부터 뒷 자리보다 작은 수들을 지워가기 시작한다. 수가 비오름차순이 되어도
지울 숫자가 남은 경우 다시 뒤쪽부터 숫자들을 지워가면 된다.

주요 알고리즘 : 그리디 알고리즘, 스택

출처 : Brasil 2008 A번
*/

int main(void) {
    int n, k, l;
    while (1) {
        scanf("%d %d", &n, &k);
        if (n == 0) break;
        scanf("%s", s);
        sttop = 0;
        l = 0;
        for (int i = 0; i < n; i++) {
            while (l < k && sttop > 0 && st[sttop - 1] < s[i]) {
                l++;
                sttop--;
            }
            st[sttop++] = s[i];
        }
        while (l < k) {
            st[--sttop] = '\0';
            l++;
        }
        st[sttop] = '\0';
        printf("%s\n", st);
    }
    return 0;
}