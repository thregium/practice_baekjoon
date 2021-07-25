#include <stdio.h>

/*
���� : B�� R�� �̷���� 100000�� ������ ���ڿ��� �־��� ��, B�� R�� ���� ���� ���� ū ������ ���Ѵ�.

�ذ� ��� : B�� R�� ���� -1, 1�� �� ����, ���� ���� �����ش�. ���� ���� ���� ū ������ ���� ���� ������ ã�� ����
[���� ������ ���� + 1, ���߿� ������ ����] ������ ���ϸ� ���� �� ���� ���� ū ���̷� ���� ���̵� ���� ū ���� �ȴ�.

�ֿ� �˰��� : ���� ��

��ó : PacNW 2017 G/S��
*/

char s[103000];
int sum[103000];

int main(void) {
    int highest = 0, lowest = 0;
    scanf("%s", s + 1);
    for (int i = 1; s[i]; i++) {
        if (s[i] == 'R') sum[i] = sum[i - 1] + 1;
        else sum[i] = sum[i - 1] - 1;
        if (sum[i] > sum[highest]) highest = i;
        if (sum[i] < sum[lowest]) lowest = i;
    }
    if (lowest < highest) printf("%d %d", lowest + 1, highest);
    else printf("%d %d", highest + 1, lowest);
    return 0;
}