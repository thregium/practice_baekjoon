#include <stdio.h>
#include <string.h>

/*
문제 : 키보드로 칠 수 있는 문자열이 주어질 때,
이 문자열을 한칸 왼쪽에 손을 두고 쳐서 나오는 문자열을 구한다. 단, 스페이스 바는 그대로 출력된다.

해결 방법 : 키보드의 배열을 하드코딩한 다음, 각 문자마다 현재 문자의 한칸 왼쪽의 키를 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : Waterloo 20010117 C번
*/

char buff[103000];
const char* key = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main(void) {
    int t;
    while (fgets(buff, 101300, stdin)) {
        if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
        for (int i = 0; buff[i]; i++) {
            if (buff[i] == ' ') {
                printf(" ");
                continue;
            }
            t = 0;
            for (int j = 0; key[j]; j++) {
                if (key[j] == buff[i]) {
                    printf("%c", key[j - 1]);
                    t = 1;
                    break;
                }
            }
            if (!t) return 1;
        }
        printf("\n");
    }
    return 0;
}