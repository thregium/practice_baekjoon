#include <stdio.h>
#include <ctype.h>

/*
���� : 50���� ������ ���ڿ��� �־��� ��, �� ���ڿ��� �ص��� ���ڿ��� ���Ѵ�.
'u'�� 'm' �̿��� �ٸ� �����ڰ� ���� �ܾ���� ��� 'u'�� 'm'�� �̾� ���� ��,
7�� ������ �߶� 'u'�� 1, 'm'�� 0���� ��ȯ�ϰ� �̸� �ƽ�Ű �ڵ�� ��ȯ�Ͽ� ����ϴ� ������ ��ģ��.
��ȯ �� 'u'�� 'm'�� 7 �̻��� 7�� ����� ������ŭ �ִ�.

�ذ� ��� : ������ �־������ �����Ѵ�.

�ֿ� �˰��� : ���ڿ�, ����, �Ľ�

��ó : MidC 2019 L��
*/

char buff[524288], um[524288];

int main(void) {
    int m = 0, t;
    while (scanf("%s", buff) != EOF) {
        //if (buff[0] == '@') break;
        t = 1;
        for (int i = 0; buff[i]; i++) {
            if (islower(buff[i]) || isupper(buff[i]) || isdigit(buff[i])) {
                if (buff[i] == 'u' || buff[i] == 'm') continue;
                t = 0;
                break;
            }
        }
        if (!t) continue;
        for (int i = 0; buff[i]; i++) {
            if (buff[i] == 'u' || buff[i] == 'm') um[m++] = buff[i];
        }
    }
    if (m % 7) return 1;
    for (int i = 0; i < m; i += 7) {
        t = 0;
        for (int j = 0; j < 7; j++) {
            if (um[i + j] == 'u') t += (1 << (6 - j));
        }
        printf("%c", t);
    }
    return 0;
}