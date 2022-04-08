#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : N(N <= 100)가지 언어의 이름과 각 언어의 단어들이 줄마다 주어진다. 각 줄의 길이는 최대
256자 이하다. 이후 1000개 이하의 줄이 주어질 때, 위 언어 가운데 하나의 언어에 있는 단어 또는
위 언어에 포함되지 않는 단어들로 이루어진 문장이 주어지면 어떤 언어의 문장인 지 구한다.
단어는 띄어쓰기 또는 문장부호('과 - 제외)를 단위로 나뉘며, 대소문자를 구별하지 않는다.

해결 방법 : strtok 함수를 통해 각 언어의 이름과 단어들을 나누어 나간 다음,
각 단어들을 소문자로 바꾸어 준다.
다시 문장들을 입력받은 다음 문장부호 단위로 나누고 소문자로 바꾼 다음, 각 언어의 각 단어 가운데
하나와 일치할 때 까지 찾아보면서 일치하는 문장을 구하면 된다.

주요 알고리즘 : 문자열, 파싱

출처 : PacNW 2013 L번
*/

char buff[512], word[128][128][256];
int wcnt[128];

int main(void) {
    int n, r;
    char* c;
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2013\\_IO\\Languages.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2013\\_IO\\Languages_t.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s ", word[i][0]);
        fgets(buff, 500, stdin);
        if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
        c = strtok(buff, " ,.!?;:()[]{}<>");
        for (int j = 1; c; j++) {
            for (int i = 0; c[i]; i++) c[i] = tolower(c[i]);
            strcpy(word[i][j], c);
            wcnt[i] = j;
            c = strtok(NULL, " ,.!?;:()[]{}<>");
        }
    }

    while (1) {
        if (!fgets(buff, 500, stdin)) break;
        if (strlen(buff) == 1) continue;
        if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
        c = strtok(buff, " ,.!?;:()[]{}<>");
        r = 0;
        while (c) {
            for (int i = 0; c[i]; i++) c[i] = tolower(c[i]);
            for (int i = 0; i < n; i++) {
                for (int j = 1; j <= wcnt[i]; j++) {
                    if (!strcmp(word[i][j], c)) {
                        printf("%s\n", word[i][0]);
                        r = 1;
                        break;
                    }
                }
                if (r) break;
            }
            if (r) break;
            c = strtok(NULL, " ,.!?;:()[]{}<>");
        }
        if (!r) return 1;
    }
    return 0;
}