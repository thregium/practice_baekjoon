#include <stdio.h>
#include <string.h>

/*
���� : ���� �� �ٸ��� ������ ������ŭ �־��� ��, �ٸ��� ���� ����Ѵ�.

�ذ� ��� : �� ������ ���� �Է¹��� �� ���� ������ �߶� �Ľ��Ѵ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�
*/

char s[1024], *tok;

int main(void) {
    int t, x, r;
    scanf("%d\n", &t);
    for (int tt = 0; tt < t; tt++) {
        fgets(s, 1024, stdin);
        r = 0;
        tok = strtok(s, " ");
        while (tok != NULL) {
            sscanf(tok, "%d", &x);
            r += x;
            tok = strtok(NULL, " ");
        }
        printf("%d\n", r);
    }
    return 0;
}