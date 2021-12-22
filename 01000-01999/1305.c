#include <stdio.h>

/*
���� : ���� L(L <= 10^6)�� ���ڿ��� �־��� ��, �� ���ڿ��� ���� ª�� �ݺ��� ���̸� ���Ѵ�.

�ذ� ��� : �̴� L���� ���ڿ��� ���̻�� ���λ��� ���� �κ��� ���̸� �� �Ͱ� ����.
KMP�� ���� �Լ��� �̿��ϸ� ������ ������ ���� �Լ��� ��� ���� �ǹǷ� ������ �ذ� �����ϴ�.

�ֿ� �˰����� : ���ڿ�, KMP
*/

char s[1048576];
int f[1048576];

int main(void) {
    int l, p = -1;
    scanf("%d%s", &l, s);
    f[0] = -1;
    for (int i = 0; i < l; i++) {
        while (p > -1 && s[i] != s[p]) p = f[p];
        f[i + 1] = ++p;
    }
    printf("%d", l - f[l]);
    return 0;
}