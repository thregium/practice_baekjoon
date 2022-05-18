#include <stdio.h>

/*
문제 : 길이 N(N <= 10^6)의 카이사르 암호가 있다. 가장 많이 등장하는 유일한 문자의
원래 값이 주어지면, 원문을 해독해 출력한다.

해결 방법 : 각 문자의 등장 횟수를 센 다음, 가장 많이 등장하는 문자를 찾아나간다.
그 다음, 그 값과 주어진 문자를 바탕으로 돌릴 횟수를 구하고, 그 횟수만큼 돌리면 된다.

주요 알고리즘 : 구현, 문자열

출처 : JPOI 2009 1-5번
*/

char s[1048576];
int cnt[26];

int main(void) {
    int n, best = -1, bchr = -1, rot = -1;
    char c;
    scanf("%d %c", &n, &c);
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        cnt[s[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > best) {
            best = cnt[i];
            bchr = i;
        }
    }
    rot = (c - 'A') - bchr;
    rot = (rot + 2600) % 26;
    for (int i = 0; s[i]; i++) {
        s[i] = ((s[i] - 'A') + rot) % 26 + 'A';
    }
    printf("%s", s);
    return 0;
}