#include <stdio.h>

/*
���� : ī�� ��ȣ�� �־��� ��, �־��� ī�� ��ȣ�� ��ȿ���� ���Ѵ�.

�ذ� ��� : üũ���� ���� ��, �� ���� �´��� Ȯ���غ��� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : �߾Ӵ� 2017C A��
*/

char s[32];

int main(void) {
    int t, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        r = 0;
        for (int i = 0; i < 16; i++) {
            if (i & 1) r += s[i] - '0';
            else r += ((s[i] - '0') * 2) % 10 + ((s[i] - '0') * 2) / 10;
        }
        if (r % 10) printf("F\n");
        else printf("T\n");
    }
    return 0;
}