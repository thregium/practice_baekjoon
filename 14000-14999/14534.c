#include <stdio.h>
#include <string.h>

/*
���� : ���� 5 ������ ���ڿ��� �־��� ��, �� ���ڿ��� ���� �� �ִ� ��� ������ �ε��� ������ ����Ѵ�.

�ذ� ��� : ���̰� �ſ� �۱� ������ ����� ���� ������ for���� ������

�ֿ� �˰��� : ����, ���̽� ��ũ...?

��ó : Khawarizmi 2016 B��
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