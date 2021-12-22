#include <stdio.h>
#include <ctype.h>

/*
문제 : S * S(S <= 20) 크기의 크로스워드에 모든 알파벳이 있다고 하면, 나오는 알파벳들을 차례로 출력한다.

해결 방법 : 각 알파벳의 등장 여부를 저장한 후, 등장하지 않은 알파벳이 나올 때 마다 차례대로 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : NZPC 2016 F번
*/

char puz[32], chk[26];

int main(void) {
    int s;
    scanf("%d\n", &s);
    for (int i = 0; i < s; i++) {
        fgets(puz, 24, stdin);
        for (int j = 0; puz[j]; j++) {
            if (isupper(puz[j])) {
                if (!chk[puz[j] - 'A']) {
                    chk[puz[j] - 'A'] = 1;
                    printf("%c", puz[j]);
                }
            }
        }
    }
    return 0;
}