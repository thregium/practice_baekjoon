#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
���� : ���ڿ� �ȿ��� ���ڷ� �̷���� �κ� ���ڿ����� ���� ��ȯ�� ���� ���� ���Ѵ�. ���ڷ� �̷���� �κ� ���ڿ���
�ִ� 6�ڷ� �̷���� �ִ�.

�ذ� ��� : ���ڿ��� Ȯ���ϸ� ���ڰ� ������ �ӽ� ���ڿ��� �� ���ڸ� �߰��Ѵ�. ���ڰ� �ƴ� ���� ������
�ӽ� ���ڿ��� ���� strtoll �Լ��� �̿��� ���� ��ȯ�� �� ���ڿ��� �ʱ�ȭ�Ѵ�.
�̸� ���ڿ� ��ü�� ���� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�

��ó : JPOI 2010 13��
*/

char s[5242880], tmp[16];

int main(void) {
    int n, p = 0;
    long long r = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) tmp[p++] = s[i];
        else {
            r += strtoll(tmp, NULL, 10);
            p = 0;
            for (int j = 0; j < 16; j++) tmp[j] = '\0';
        }
    }
    r += strtoll(tmp, NULL, 10);
    printf("%lld", r);
    return 0;
}