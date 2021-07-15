#include <stdio.h>

/*
���� : �־��� ���ڿ��� ��Ģ�� �°� �ڵ�� ��ȯ�� ���� ���Ѵ�. (��Ģ ����)

�ذ� ��� : ��Ģ�� �°� �����Ѵ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : MidC 1993 6��
*/

char name[32], sdx[8];
int code[26] = { 0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2 };

int main(void) {
    int p;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1993\\soundex.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1993\\soundex_t.out", "w", stdout);
    printf("         NAME                     SOUNDEX CODE\n");
    while (scanf("%s", name) != EOF) {
        sdx[0] = name[0];
        for (int i = 1; i <= 3; i++) sdx[i] = '0';
        p = 1;
        for (int i = 1; name[i] && p <= 3; i++) {
            if (code[name[i] - 'A'] == 0 || code[name[i] - 'A'] == code[name[i - 1] - 'A']) continue;
            sdx[p++] = code[name[i] - 'A'] + '0';
        }
        printf("         %-25s%s\n", name, sdx);
    }
    printf("                   END OF OUTPUT");
    return 0;
}