#include <stdio.h>
#include <string.h>

/*
���� : �־��� �ֻ����� ���� �� ���� �������� ���Ѵ�. ��, �ֻ����� ���� �˸��� ���� ���¶�� unknown�� ����Ѵ�.

�ذ� ��� : �� ������ ���� �� �ִ� ���¸� �̸� �����ϰ� �ֻ����� ���� ����Ͱ� ������ ���Ѵ�.
���� ���� ���ٸ� unknown�� ����Ѵ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : CTU 2018 D��
*/

char s[16], buff[8];
char* dice[9] = { "::::o::::", "o:::::::o", "::o:::o::", "o:::o:::o", "::o:o:o::", "o:o:::o:o", "o:o:o:o:o", "ooo:::ooo", "o:oo:oo:o" };
int dn[9] = { 1, 2, 2, 3, 3, 4, 5, 6, 6 };

int main(void) {
    for (int i = 0; i < 3; i++) {
        scanf("%s", buff);
        strcat(s, buff);
    }
    for (int i = 0; i < 9; i++) {
        if (!strcmp(s, dice[i])) {
            printf("%d", dn[i]);
            return 0;
        }
    }
    printf("unknown");
    return 0;
}