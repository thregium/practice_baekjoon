#include <stdio.h>

/*
���� : 100�� ������ �빮�ڷ� �̷���� ���ڿ��� �־��� ��, ���ǿ� ���� �빮�ڵ��� �̿��� ���ڿ��� ǥ���ϱ� ����
�ּҷ� ������ �ϴ� ���� ĭ ���� ���Ѵ�.

�ذ� ��� : ���� ��� �������� ���ڸ� �Է��� ���� ���� ��ġ�� �׻� �����ϴ�.
����, ���� ������ ���� ������ �������� ������ ���� ����, ���ʰ� ���������� ���� ������ ����
�� ���� �����̴� ���� �����ϸ� �ȴ�.

�ֿ� �˰����� : �׸��� �˰�����, ����

��ó : �Ѿ��E 2019Z A��
*/

char s[128];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int r = 0, lr, rr;
    char l = 'A';
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        lr = (s[i] - l + 26) % 26;
        rr = (l - s[i] + 26) % 26;
        r += small(lr, rr);
        l = s[i];
    }
    printf("%d", r);
    return 0;
}