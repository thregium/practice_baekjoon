#include <stdio.h>
#include <string.h>

/*
문제 : 50만자 이하의 문자열이 주어질 때, 각 문자마다 키보드에서의 위치를 각각 출력한다.

해결 방법 : 각 위치별 문자를 저장한 다음, 각 문자를 위치에 맞는 숫자로 바꾼 뒤 출력하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : PA 2008 0-1번
*/

char s[524288];
char* key[5] = { "`1234567890-=~!@#$%^&*()_+", "qwertyuiop[]\\QWERTYUIOP{}|", "asdfghjkl;'ASDFGHJKL:\"",
"zxcvbnm,./ZXCVBNM<>?", " " };
int trans[128];

int main(void) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; key[i][j]; j++) trans[key[i][j]] = i + 1;
    }
    fgets(s, 512000, stdin);
    if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
    for (int i = 0; s[i]; i++) {
        s[i] = trans[s[i]] + '0';
    }
    printf("%s", s);
    return 0;
}