#include <stdio.h>
#include <string.h>

/*
문제 : 길이 5 이하의 문자열이 주어질 때, 이 문자열로 만들 수 있는 모든 순열을 인덱스 순서로 출력한다.

해결 방법 : 길이가 매우 작기 때문에 경우의 수를 나누어 for문을 돌린다

주요 알고리즘 : 구현, 케이스 워크...?

출처 : Khawarizmi 2016 B번
*/

char s[8];

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        n = strlen(s);
        printf("Case # %d:\n", tt + 1);
        if (n == 1) printf("%s\n", s);
        else if (n == 2) printf("%s\n%c%c\n", s, s[1], s[0]);
        else if (n == 3) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == j) continue;
                    for (int k = 0; k < 3; k++) {
                        if (i == k || j == k) continue;
                        printf("%c%c%c\n", s[i], s[j], s[k]);
                    }
                }
            }
        }
        else if (n == 4) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (i == j) continue;
                    for (int k = 0; k < 4; k++) {
                        if (i == k || j == k) continue;
                        for (int l = 0; l < 4; l++) {
                            if (i == l || j == l || k == l) continue;
                            printf("%c%c%c%c\n", s[i], s[j], s[k], s[l]);
                        }
                    }
                }
            }
        }
        else if (n == 5) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (i == j) continue;
                    for (int k = 0; k < 5; k++) {
                        if (i == k || j == k) continue;
                        for (int l = 0; l < 5; l++) {
                            if (i == l || j == l || k == l) continue;
                            for (int m = 0; m < 5; m++) {
                                if (i == m || j == m || k == m || l == m) continue;
                                printf("%c%c%c%c%c\n", s[i], s[j], s[k], s[l], s[m]);
                            }
                        }
                    }
                }
            }
        }
        else return 1;
    }
    return 0;
}