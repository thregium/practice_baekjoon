#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : ���� 200 ������ �ùٸ� ��ȣ�� ���Ե� ������ �־�����. �� ���Ŀ��� ���� �̷�� ��ȣ�� �ϳ� �̻�
�����Ͽ� ���� �� �ִ� ��� ���� �ٸ� ���ĵ��� ���������� ����Ѵ�.

�ذ� ��� : �־��� ���ڿ��� �� ��ȣ�� ������ �̿��Ͽ� ��ȣ�� �ű��.
�� ����, ��ȣ�� ����� ��� ����� ���ڿ��� ������ �����ϰ� �ߺ��� �����Ͽ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �ڷ� ����, ����, ���Ʈ ����, ����

��ó : COCI 11/12#6 3��
*/

char s[256], res[1024][256];
int pnum[256], stk[16];

int main(void) {
    int level = 0, pcnt = 0, pos;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            stk[level++] = pcnt++;
            pnum[i] = pcnt - 1;
        }
        else if (s[i] == ')') {
            level--;
            pnum[i] = stk[level];
        }
        else pnum[i] = -1;
    }

    if (pcnt > 10) return 1;
    for (int i = 0; i < (1 << pcnt) - 1; i++) {
        pos = 0;
        for (int j = 0; s[j]; j++) {
            if (pnum[j] < 0 || ((i >> pnum[j]) & 1)) res[i][pos++] = s[j];
        }
    }
    qsort(res, (1 << pcnt) - 1, sizeof(char) * 256, strcmp);
    for (int i = 0; i < (1 << pcnt) - 1; i++) {
        if (i > 0 && !strcmp(res[i], res[i - 1])) continue;
        printf("%s\n", res[i]);
    }
    return 0;
}