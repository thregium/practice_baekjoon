#include <stdio.h>
#include <string.h>

/*
���� : ���� 250 ������ ���ڿ��� �־��� ��, ���� ������ ������ �ܾ���� ������ ������ ����Ѵ�.

�ذ� ��� : �� ���ڿ��� fgets()�Լ��� �̿��� ���� ����, ���� ���ڸ� �����Ѵ�. �� �ķδ� strtok()�Լ��� ����
���� ������ �ܾ �и��س� ���� �� �ܾ���� ������ �ܾ ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �Ľ�

��ó : NZPC 2004 Z��
*/

char s[256], t[256];

int main(void) {
    char* c;
    while (1) {
        fgets(s, 254, stdin);
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        if (s[0] == '#' && strlen(s) == 1) break;
        c = strtok(s, " ");
        while (c) {
            t[strlen(c)] = '\0';
            for (int i = 0, j = strlen(c) - 1; i <= j; i++, j--) {
                t[i] = c[j];
                t[j] = c[i];
            }
            printf("%s ", t);
            c = strtok(NULL, " ");
        }
        printf("\n");
    }
    return 0;
}