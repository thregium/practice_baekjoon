#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 100)���� ���ڿ��� ���� ���ڿ��� ���۰� ���� �̾��� �� ã������ ���ڿ��� �����ϴ� ���ڿ��� ���� ���Ѵ�.
��, �� ���ڿ��� ���̴� 10�̰�, ã������ ���ڿ��� ���̴� 10 �����̴�.

�ذ� ��� : ���ڿ��� 2�� �ݺ���Ű�� ������ �������� ���ƿ��� ���� �����ϴ� ��� ������ Ž�� �����ϴ�.
�ش��ϴ� ������ strstr�� ���� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����

��ó : JOI 2011P 2��
*/

char find[16], rings[128][32];

int main(void) {
    int n, r = 0;
    char tmp[16];
    scanf("%s", find);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", rings[i]);
        strcpy(tmp, rings[i]);
        strcat(rings[i], tmp);
        if (strstr(rings[i], find)) r++;
    }
    printf("%d", r);
    return 0;
}