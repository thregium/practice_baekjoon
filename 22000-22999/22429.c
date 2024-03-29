#include <stdio.h>

/*
문제 : N(N <= 1000)개의 댓글과 대댓글 목록이 주어진다. 댓글의 단계는 .으로 표시되며,
각 댓글은 50자 이하의 소문자로 주어진다. 이때, 각 댓글과 대댓글을 묶어서 출력한다.
댓글의 앞 글자는 '+'가 되어야 하며, 같은 글에 달린 댓글들은 '|'로 묶어 놓아야 한다.
또한, 나머지 '.'들은 공백(' ')으로 표시한다.

해결 방법 : 우선 댓글의 앞 글자들을 전부 '+'로 바꾸어 둔다. 그리고 각 줄마다 '+' 사이가 전부 '.'인 경우
그 '.'들을 '|'로 바꾸어준다. 나머지 '.'들을 공백으로 바꾸면 답이 된다.

주요 알고리즘 : 구현, 문자열, 투 포인터

출처 : JAG 2014D B번
*/

char s[1024][1280];

int main(void) {
    int n, e;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i]);
            for (int j = 0; j < 1279; j++) {
                if (s[i][j] == '.' && s[i][j + 1] != '.') s[i][j] = '+';
            }
        }
        for (int i = 0; i < 1280; i++) {
            for (int j = 0; j < n; j++) {
                if (s[j][i] != '+') continue;
                e = j + 1;
                while (s[e][i] == '.') e++;
                if (s[e][i] == '+') {
                    for (int k = j + 1; k < e; k++) s[k][i] = '|';
                }
                j = e - 1;
            }
            for (int j = 0; j < n; j++) {
                if (s[j][i] == '.') s[j][i] = ' ';
            }
        }

        for (int i = 0; i < n; i++) {
            printf("%s\n", s[i]);
            for (int j = 0; j < n; j++) s[i][j] = '\0';
        }
    }
    return 0;
}