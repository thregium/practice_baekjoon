#include <stdio.h>
#include <string.h>

/*
���� : ��� ������ ���ڵ�� �̷���� ���� 100 ������ ���ڿ��� �־��� ��,
�� ���ڿ��� ���� ������ �ƽ�Ű�ڵ� ��հ�(����)�� ���ڸ� ����Ѵ�.

�ذ� ��� : �� ������ ���� ���������� ���� ��, ���̷� ���� ���� ���ϸ� �ȴ�. ���� ó���� �����Ѵ�.

�ֿ� �˰��� : ���ڿ�, ��Ģ����

��ó : SCUSA 2021D2 A�� // MidC 2021 A��
*/

char s[128];

int main(void) {
    int l, sum = 0;
    fgets(s, 120, stdin);
    if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
    l = strlen(s);
    for (int i = 0; i < l; i++) {
        if (s[i] < 32 || s[i] > 126) return 1;
        sum += s[i];
    }
    printf("%c", sum / l);
    return 0;
}