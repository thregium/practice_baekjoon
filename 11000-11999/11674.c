#include <stdio.h>
#include <string.h>

/*
���� : 4������ �ݺ��� ������ ���� ������ �־��� ��, �ش� ������ ��ǥ�� ���Ѵ�.

�ذ� ��� : ������ Ȯ���ϰ� 1ĭ�� �̵��� �� ��ǥ�� 2��� �ϴ� ���� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : NWERC 2015 I��
*/

char s[32];

int main(void) {
    int l, x = 0, y = 0;
    scanf("%s", s);
    l = strlen(s);
    for (int i = 0; i < l; i++) {
        x *= 2, y *= 2;
        if (s[i] == '1') x++;
        else if (s[i] == '2') y++;
        else if (s[i] == '3') {
            x++;
            y++;
        }
    }
    printf("%d %d %d", l, x, y);
    return 0;
}