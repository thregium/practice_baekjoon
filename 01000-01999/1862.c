#include <stdio.h>
#include <stdlib.h>

/*
���� : 4�� ǥ������ �ʴ� ǥ����� �ڿ��� N(N <= 999999999)�� �־��� ��, ���������� ��Ÿ�� ���� ���Ѵ�.

�ذ� ��� : 5 �̻��� ���ڸ� 1�� ���� ���� strtoll �Լ��� ���� 9���� ���� ���������� ��ȯ�Ͽ� ����ϸ� �ȴ�.

�ֿ� �˰����� : ����, ������
*/

char s[16];

int main(void) {
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] >= '5') s[i]--;
    }
    printf("%lld", strtoll(s, NULL, 9));
    return 0;
}