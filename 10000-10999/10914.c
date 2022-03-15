#include <stdio.h>
#include <string.h>

/*
문제 : 문제에 주어진 방식으로 암호화된 100개 이하의 101자 이하 단어로 이루어진 문자열이 주어질 때,
이를 복호화한 것을 구한다.

해결 방법 : 문자열을 받아서 단어 단위로 쪼갠 다음 단어마다 복호화하여 출력하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : Kriii 2회 V번
*/

char s[16384], word[128][128];

int main(void) {
    int n, wc = 0;
    char* c;
    scanf("%d\n", &n);
    fgets(s, 15000, stdin);
    if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
    c = strtok(s, " ");
    while (c) {
        strcpy(word[wc++], c);
        c = strtok(NULL, " ");
    }
    for (int i = 0; i < wc; i++) {
        for (int j = 0; word[i][j + 1]; j += 2) {
            printf("%c", (word[i][j] + word[i][j + 1] - 'a' * 2 - n + 2600) % 26 + 'a');
        }
        printf(" ");
    }
    return 0;
}