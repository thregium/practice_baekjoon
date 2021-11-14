#include <stdio.h>

/*
문제 : 길이 100 이하의 소문자로 이루어진 문자열과 N(N <= 20)개 이하의 20 이하 길이인 소문자로 이루어진 단어들이 주어진다.
이때, 카이사르 암호 가운데 한 가지만 단어가 이루어진다면, 그때의 복호화를 출력한다.

해결 방법 : 모든 알파벳 종류에 대해 암호를 풀어본다. 각 복호화마다 단어를 찾고, 단어가 찾아질 때
그러한 복호화를 출력하고 프로그램을 종료하면 된다.

주요 알고리즘 : 브루트 포스

출처 : 고려대 2017 E번
*/

char crypt[128], word[32][32];

int main(void) {
    int n, r = 0, t = 0;
    scanf("%s", crypt);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", word[i]);
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; crypt[j]; j++) {
            for (int k = 0; k < n; k++) {
                t = 1;
                for (int l = 0; word[k][l]; l++) {
                    if ((crypt[j + l] - 'a' + i) % 26 + 'a' != word[k][l]) {
                        t = 0;
                        break;
                    }
                }
                if (t) {
                    for (int l = 0; crypt[l]; l++) {
                        printf("%c", (crypt[l] - 'a' + i) % 26 + 'a');
                    }
                    return 0;
                }
            }
        }
    }
    return 1;
}