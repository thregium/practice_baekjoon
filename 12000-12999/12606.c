#include <stdio.h>
#include <string.h>

/*
���� : 1000�� ������ ���ڿ��� �־�����. �� ���ڿ��� ���ĺ������� ������ �ܾ��� �̷���� �ִ�.
�ܾ� ���̿��� ���� 1������ ����. �̶�, �� �ܾ���� ������ ������ ����Ѵ�.

�ذ� ��� : strtok �Լ��� ���� �� �ܾ �и��س� �� ���� �����Ѵ�.
�� ����, ������ �ܾ �������� �ҷ����� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�

��ó : GCJ 2010A QB2��
*/

char s[1024], s2[1024][1024];

int main(void) {
    int n, p;
    char* t;
    scanf("%d\n", &n);
    for (int nn = 1; nn <= n; nn++) {
        fgets(s, 1013, stdin);
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        p = 0;
        while (1) {
            if (p == 0) t = strtok(s, " ");
            else t = strtok(NULL, " ");
            if (t == NULL) break;
            strcpy(s2[p], t);
            p++;
        }
        printf("Case #%d: ", nn);
        for (int i = p - 1; i >= 0; i--) {
            printf("%s", s2[i]);
            if (i > 0) printf(" ");
        }
        printf("\n");
    }
    return 0;
}