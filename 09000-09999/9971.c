#include <stdio.h>
#include <ctype.h>

/*
���� : ī�̻縣 ��ȣ�� �� 200�� ������ ���ڿ��� �־��� ��, �̸� ������ ��ȯ�� ���ڿ��� ���Ѵ�.

�ذ� ��� : �־��� ���ڿ��� ���� ������ ���캻��. ���� ���ڰ� ���ĺ��� �ƴ϶�� �״�� ����ϰ�, ���ĺ��̶��
5ĭ �о ���ĺ��� ����ϸ� �ȴ�. �̴� (buff[i] - 'A' + 21) % 26 + 'A'��� ���� ���� ������ �� �ִ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : SCUSA 2002 1��
*/

char buff[256];

int main(void) {
    while (1) {
        scanf("%s\n", &buff);
        if (buff[0] == 'E') break;
        fgets(buff, 250, stdin);
        for (int i = 0; buff[i]; i++) {
            if (isupper(buff[i])) printf("%c", (buff[i] - 'A' + 21) % 26 + 'A');
            else printf("%c", buff[i]);
        }
        scanf("%s", buff);
    }
    return 0;
}