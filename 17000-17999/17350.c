#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 1000)���� ���ڿ� ��� "anj"��� ���ڿ��� �ִ��� Ȯ���Ѵ�.

�ذ� ��� : strcmp() �Լ��� ����Ѵ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : ���� 3ȸ B��
*/

char buff[128];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (!strcmp(buff, "anj")) r = 1;
    }
    if (r) printf("����;");
    else printf("����?");
    return 0;
}