#include <stdio.h>
#include <string.h>

/*
���� : "������ ����� ��"�� ������ ������ "����"�� ������ ������ ���� 1 �ø���, "������"�� ������ ������ �ִٸ�
���� 1 ���̰�, ���� ��� ���� 2 �ø���. �������� ������ ������ 0������ Ȯ���Ѵ�.

�ذ� ��� : ������ ������ ������ �ϴ� ���� ���� ������ �ȴ�. ���� Ȯ���� strcmp() �Լ��� �̿��Ѵ�.

�ֿ� �˰��� : ����

��ó : �泲�� 4ȸ A��
*/

char s[64];

int main(void) {
    int cnt = 0;
    while (1) {
        fgets(s, 48, stdin);
        //if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] == '\0';
        if (!strcmp(s, "����\n")) cnt++;
        else if (!strcmp(s, "������\n")) {
            if (cnt == 0) cnt += 2;
            else cnt--;
        }
        else if (!strcmp(s, "������ ����� ��\n")) break;
    }
    if (cnt) printf("����\n");
    else printf("�������� �����\n");
    return 0;
}