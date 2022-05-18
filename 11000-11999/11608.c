#include <stdio.h>
#include <string.h>

/*
문제 : 100자 이하의 소문자로 이루어진 문자열이 주어질 때, 문자열의 문자 가짓수를 2가지 이하로
줄이기 위해 지워야 하는 문자의 최소 개수를 구한다.

해결 방법 : 남길 문자의 종류를 브루트 포스를 통해 하나씩 해보면서 가장 적게 지울 수 있는 경우의
지우는 문자 개수를 구하면 된다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : PacNW 2015 P번 // SEUSA 2015D1 I번 / 2015D2 J번
*/

char s[128];

int main(void) {
    int len, cnt, best = 103000;
    scanf("%s", s);
    len = strlen(s);
    for (int i = 'a'; i <= 'z'; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            cnt = 0;
            for (int k = 0; k < len; k++) {
                if (s[k] != i && s[k] != j) cnt++;
            }
            if (cnt < best) best = cnt;
        }
    }
    if (best == 103000) return 1;
    printf("%d", best);
    return 0;
}