#include <stdio.h>

/*
���� : N(N <= 10000)�� �̳��� ���̸� ���� ���ڿ��� �־��� ��,
�� ���ڿ����� JOI�� IOI�� ���� �� �� �������� ����Ѵ�.

�ذ� ��� : N�� ã�� ���ڿ��� �����Ƿ� ���� ���� ã�ƺ���.

�ֿ� �˰��� : ���ڿ�
*/

char s[10240];

int main(void) {
    int joi = 0, ioi = 0;
    scanf("%s", s);
    for (int i = 2; s[i]; i++) {
        if (s[i] == 'I' && s[i - 1] == 'O') {
            if (s[i - 2] == 'J') joi++;
            else if (s[i - 2] == 'I') ioi++;
        }
    }
    printf("%d\n%d", joi, ioi);
    return 0;
}