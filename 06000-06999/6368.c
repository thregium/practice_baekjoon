#include <stdio.h>
#include <string.h>

/*
문제 : 4자 이하의 길이를 갖는 모스 부호들이 대응하는 문자들이 전부 있다. 문자열이 주어지면 이 문자열의 문자들을 각각 모스 부호로
변환한 다음 각 부호들의 길이를 뒤집은 다음 다시 그에 대응하는 문자들로 변환한 값을 구한다.

해결 방법 : 각 문자에 대응하는 부호들을 전부 하드코딩한다. 문자열이 주어지면 각 문자에 대응하는 모든 부호들을 얻어낼 수 있고,
부호들의 길이 역시 알아낼 수 있다. 그 다음, 각 부호들의 길이를 뒤집어낸 다음, 역순으로 해당하는 길이와 부호에 대응하는 문자들을 알아내면 된다.

주요 알고리즘 : 구현, 문자열

출처 : GNY 2001 B번
*/

char* morse[30] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
"-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
"..-", "...-", ".--", "-..-", "-.--", "--..", "..--", ".-.-", "---.", "----" };
char* assign = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_,.?";

char buff[128], code[512], tmp[16];
int len[128];

int main(void) {
    int t, x, p;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s", buff);
        for (int i = 0; buff[i]; i++) {
            for (int j = 0; j < 30; j++) {
                if (assign[j] == buff[i]) {
                    strcat(code, morse[j]);
                    len[i] = strlen(morse[j]);
                    break;
                }
            }
        }
        for (int i = 0, j = strlen(buff) - 1; i < j; i++, j--) {
            x = len[i];
            len[i] = len[j];
            len[j] = x;
        }
        p = 0;
        printf("%d: ", tt);
        for (int i = 0; buff[i]; i++) {
            for (int j = 0; j < len[i]; j++) {
                tmp[j] = code[p + j];
            }
            tmp[len[i]] = '\0';
            for (int j = 0; j < 30; j++) {
                if (strcmp(tmp, morse[j])) continue;
                printf("%c", assign[j]);
                break;
            }
            p += len[i];
        }
        printf("\n");
        code[0] = '\0';
    }
    return 0;
}