#include <stdio.h>
#include <ctype.h>

/*
문제 : 250자 이하의 문자열과 키값이 주어질 때, 암호화된 변형 카이사르 암호
(알파벳이 나오면 돌리는 칸수를 주어진 키값에서 1씩 늘려감. 25 다음에는 1로 초기화)를 복호화한다.

해결 방법 : 암호화의 역순으로 계산해 나가면 된다. 26 - 키값을 첫 키값으로 하고, 1씩 돌리는 칸 수를 줄여간다.
0칸이 되면 다시 25로 바꾸고 이를 반복해 나간다.

주요 알고리즘 : 문자열, 구현

출처 : NZPC 2016 E번
*/

char txt[256];

int main(void) {
    int k;
    scanf("%d", &k);
    getchar();
    k = 26 - k;
    fgets(txt, 253, stdin);
    for (int i = 0; txt[i]; i++) {
        if (islower(txt[i])) {
            printf("%c", (txt[i] - 'a' + k) % 26 + 'a');
            k--;
            if (k == 0) k = 25;
        }
        else printf("%c", txt[i]);
    }
    return 0;
}