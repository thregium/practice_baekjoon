#include <stdio.h>
#include <string.h>

/*
���� : 2���� 1���� 9������  ī�� ��� ���� �ٸ� 2�徿�� �̾Ҵ�.(���� ī��� ��� �ٸ���).
1���� ���� ī��� ���� ī����� �������� ������ �־��� ��, �ٸ� 1���� ���� ī�带 �����ϰ� �� �� �ִٸ�
�� ī�����, ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : ������ ���� ��츦 ������ �����ϰ� �� �� �ִ� ���� ���� ��쿡 ���� ���� ����Ѵ�.

�ֿ� �˰��� : ���̽� ��ũ

��ó : MidAtl 2021 J�� // NCNA 2021 G��
*/

char s[8];

int main(void) {
    int p, q;
    scanf("%d %d", &p, &q);
    scanf("%s", s);
    if (!strcmp(s, "AABB")) {
        if (q == 7) printf("8 9");
        else printf("-1");
    }
    else if (!strcmp(s, "ABAB")) {
        if (p == 6 && q == 8) printf("7 9");
        else printf("-1");
    }
    else if (!strcmp(s, "ABBA")) {
        if (q - p == 3) printf("%d %d", p + 1, p + 2);
        else printf("-1");
    }
    else if (!strcmp(s, "BAAB")) {
        if (p == 2 && q == 8) printf("1 9");
        else printf("-1");
    }
    else if (!strcmp(s, "BABA")) {
        if (p == 2 && q == 4) printf("1 3");
        else printf("-1");
    }
    else if (!strcmp(s, "BBAA")) {
        if (p == 3) printf("1 2");
        else printf("-1");
    }
    else return 1;
    return 0;
}