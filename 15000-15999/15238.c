#include <stdio.h>

/*
���� : ���ڿ����� ���� ���� ������ ���ڿ� ���� Ƚ���� ã�´�.

�ذ� ��� : �� ������ ����Ƚ���� ���� �� �� ���� ���� ������ ���� ã���� �ȴ�.

�ֿ� �˰��� : ���ڿ�

��ó : AIPO 2017F 1��
*/

char s[1024];
int a[26];

int main(void) {
    int n, r = 0;
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; i++) {
        a[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] > a[r]) r = i;
    }
    printf("%c %d", r + 'a', a[r]);
    return 0;
}
