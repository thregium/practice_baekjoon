#include <stdio.h>
#include <string.h>

/*
���� : ���� 30 ������ �ҹ��ڷ� �̷���� ���ڿ��� �־��� ��, �� ���ڸ� ���� ȸ���� ���� �� �ִ��� ���ϰ�,
�����ϴٸ� �� �� ���� ���� ���ڸ� ����� ����� ���ڿ��� ���Ѵ�.

�ذ� ��� : ���ڿ��� ���̰� ª���Ƿ� ��� ��츦 ���� �غ��� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����

��ó : NZPC 2016 D��
*/

char s[32], r[32];

int main(void) {
    int res, tmp;
    while (1) {
        scanf("%s", s);
        if (!strcmp(s, "#")) break;
        res = 0;
        for (int i = 0; s[i]; i++) {
            for (int j = 0; j < i; j++) r[j] = s[j];
            for (int j = i + 1; s[j]; j++) r[j - 1] = s[j];
            tmp = 1;
            r[strlen(s) - 1] = '\0';
            for (int j = 0, k = strlen(r) - 1; j < k; j++, k--) {
                if (r[j] != r[k]) tmp = 0;
            }
            if (tmp) {
                res = 1;
                printf("%s\n", r);
                break;
            }
        }
        if (!res) printf("not possible\n");
    }
    return 0;
}