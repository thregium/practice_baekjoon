#include <stdio.h>
#include <ctype.h>

/*
���� : �빮�ڿ� �������� �̷���� 100�� ������ ���ڿ��� ���� ������ �̿��� �빮�ڵ��� ���� �ٲ㼭 ���� ���ڿ��� �־�����.
���� ������ ���� �־����� ������ ���ڿ��� ����Ѵ�.

�ذ� ��� : ������ ���ڿ��� ������ �Է� ���� ��, ���ĺ�(�빮��)�� ������ ������ �̿��� ���ڿ��� �ٲپ� ����ϰ�,
�� ���� ���� ������ �״�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : GNY 2008 B��
*/

char mess[128], conv[32];

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        fgets(mess, 120, stdin);
        if (mess[0] == '\n') {
            tt--;
            continue;
        }
        scanf("%s", conv);
        for (int i = 0; mess[i]; i++) {
            if (isupper(mess[i])) printf("%c", conv[mess[i] - 'A']);
            else printf("%c", mess[i]);
        }
    }
    return 0;
}