#include <stdio.h>
#include <ctype.h>

/*
문제 : 주어진 문자열(50자 이하, 대문자 + 특수문자(공백 제외, 시프트 사용 문자 제외))이 주어질 때,
각 손가락이 문자열을 치는 횟수를 구한다.

해결 방법 : 각 손가락 별로 치는 문자열들을 나열해둔 다음, 해당 문자가 나오면
해당 문자에 대응하는 손가락 사용 횟수를 1씩 늘린다. 모든 문자를 확인한 다음 각 손가락의 사용 횟수를 출력한다.

주요 알고리즘 : 구현

출처 : COCI 14/15#3 1번
*/

char s[64];
int cnt[8];
const char* key[] = { "`1qaz", "2wsx", "3edc", "45rtfgvb", "67yuhjnm", "8ik,", "9ol.", "0-=p[];'/" };

int main(void) {
    int t;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        t = 1;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; key[j][k]; k++) {
                if (key[j][k] == tolower(s[i])) {
                    t = 0;
                    cnt[j]++;
                }
            }
        }
        if (t) return 1;
    }
    for (int i = 0; i < 8; i++) {
        printf("%d\n", cnt[i]);
    }
    return 0;
}