#include <stdio.h>
#include <string.h>

/*
문제 : 테트스의 7가지 테트로미노의 종류로 이루어진 길이 1000 이하의 문자열이 주어진다.
이 순서가 현대 테트리스에서 가능한 순서의 일부인 지 구한다.
현대 테트리스에서는 7가지 테트로미노 단위로 순서를 섞어서 테트로미노들이 나온다.

해결 방법 : 7가지 테트로미노가 나오는 단위의 시작점을 하나씩 가정해보면서 가능한 경우가 있는 지 찾는다.
가능한 경우가 있다면 가능한 순서의 일부이고, 없다면 가능한 순서가 아니다.

주요 알고리즘 : 브루트 포스, 구현

출처 : PacNW 2021 Q번 // SCUSA 2021D1 H번 / 2021D2 I번 // MidC 2021 G번 // NENA 2021 C번
*/

char s[1024], chk[26];

int main(void) {
    int t, l, r, rt;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        l = strlen(s);
        r = 0;
        for (int i = 0; i < 7; i++) {
            rt = 1;
            for (int j = i; j < l; j += 7) {
                for (int k = 0; k < 7 && j + k < l; k++) {
                    if (chk[s[j + k] - 'A']) rt = 0;
                    chk[s[j + k] - 'A'] = 1;
                }
                for (int k = 0; k < 26; k++) chk[k] = 0;
            }
            for (int j = 0; j < i; j++) {
                if (chk[s[j] - 'A']) rt = 0;
                chk[s[j] - 'A'] = 1;
            }
            for (int k = 0; k < 26; k++) chk[k] = 0;
            if (rt) r = 1;
        }
        printf("%d\n", r);
    }
    return 0;
}