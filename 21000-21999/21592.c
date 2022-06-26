#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 1000)���� ���� 100 ���� �ҹ��ڷ� �̷���� ���ڿ����� �־�����.
�� ���ڿ��鿡 ���� ��� ���ڿ��� ���ԵǴ� ���� �� �κ� ���ڿ��� ���̸� ���Ѵ�.

�ذ� ��� : ���ڿ��� ���̿� ������ �����Ƿ� ù ��° ���ڿ��� ��� �κ� ���ڿ����� ����� ���鼭
�� �� ��� ���ڿ��� ���ϴ� ���� �� ���ڿ��� ���̸� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����

��ó : NADC 2021 H��
*/

char s[1024][128], t[128];

int main(void) {
    int n, l, res = 0, ok;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    l = strlen(s[0]);
    for (int i = 0; i < l; i++) {
        for (int j = i; j < l; j++) {
            for (int k = i; k <= j; k++) t[k - i] = s[0][k];
            t[j - i + 1] = '\0';
            ok = 1;
            for (int k = 0; k < n; k++) {
                if (!strstr(s[k], t)) ok = 0;
            }
            if (ok && j - i + 1 > res) res = j - i + 1;
        }
    }
    printf("%d", res);
    return 0;
}