#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 5글자의 단어가 대문자로 주어지고, 도전자는 최대 5회의 도전 기회를 갖는다. 맨 처음에는 단어의 첫 자를 알려주고,
이후로는 도전자가 주는 단어에 따라 도전자가 말한 단어와 위치가 일치하는 문자는 대문자로, 말한 단어에 있지만 위치가 일치하지 않는 문자는 소문자로,
완전히 일치하지 않는 문자는 .으로 나타낸다. 만약 도전자가 단어를 제대로 말하지 못한 경우 이전에 말한 단어를 그대로 알려준 다음 도전 횟수를 1회 차감시킨다.
도전자가 5회 이내에 성공한 경우 이후 입력은 무시한다. 반대로, 도전자가 5회동안 성공하지 못하거나 조기에 포기한 경우 소문자로 단어를 알려준 다음
이후 입력은 무시한다.
단, 소문자 여부를 확인할 때에는 대문자로 출력했거나 이미 앞에서 소문자로 말한 경우 해당 문자는 무시한다.

해결 방법 : 먼저 단어를 입력받은 다음, 이후로 도전자가 주는 단어를 입력받고 위 조건에 따라 출력한다.

주요 알고리즘 : 문자열, 케이스 워크, 구현

출처 : GNY 2002 C번
*/

char word[8], buff[16], review[8];

int main(void) {
    int attempt = 0, ans, t, t2;
    //freopen("C:\\1_공부\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2002\\problemc.in", "r", stdin);
    //freopen("C:\\1_공부\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2002\\problemc_check.out", "w", stdout);
    while (1) {
        fgets(word, 8, stdin);
        if (word[0] == '\n') {
            printf("\n");
            continue;
        }
        word[strlen(word) - 1] = '\0';
        if (!strcmp(word, "LINGO")) break;
        printf("%c....\n", word[0]);
        strcpy(review, ".....");
        review[0] = word[0];
        attempt = 0;
        ans = 0;
        while (1) {
            fgets(buff, 12, stdin);
            if (buff[0] == '\n') break;
            buff[strlen(buff) - 1] = '\0';
            if (ans || attempt >= 5) continue;
            if (strlen(buff) != 5 || !isupper(buff[0]) || !isupper(buff[1]) || !isupper(buff[2]) || !isupper(buff[3]) || !isupper(buff[4])) {
                attempt++;
                printf("%s\n", review);
                continue;
            }
            if (!strcmp(word, buff)) {
                ans = 1;
                printf("%s\n", buff);
                continue;
            }
            for (int i = 0; i < 5; i++) {
                if (word[i] == buff[i]) {
                    review[i] = buff[i];
                    printf("%c", buff[i]);
                    continue;
                }
                t = 0;
                for (int j = 0; j < 5; j++) {
                    if (word[j] == buff[i] && word[j] != buff[j]) {
                        t2 = 0;
                        for (int k = 0; k < i; k++) {
                            if (toupper(review[k]) == buff[i]) t2 = 1;
                        }
                        if (t2) continue;
                        printf("%c", tolower(buff[i]));
                        review[i] = tolower(buff[i]);
                        t = 1;
                        break;
                    }
                }
                if (!t) {
                    review[i] = '.';
                    printf(".");
                }
            }
            printf("\n");
            attempt++;
        }
        if (!ans) printf("%c%c%c%c%c\n", tolower(word[0]), tolower(word[1]), tolower(word[2]), tolower(word[3]), tolower(word[4]));
        printf("\n");
    }
    return 0;
}