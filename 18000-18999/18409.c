#include <stdio.h>

/*
���� : ���� N(N <= 50)�� �ҹ��ڷ� �̷���� ���ڿ����� ������ �� �� �ִ��� ���Ѵ�.

�ذ� ��� : �� ���ڵ��� Ȯ���ϸ� a, e, i, o, u �� ������ ���� �ȴ�.

�ֿ� �˰��� : ����

��ó : JOI 2020��1 1-2��
*/

char s[64];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') r++;
    }
    printf("%d", r);
    return 0;
}