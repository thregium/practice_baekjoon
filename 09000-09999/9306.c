#include <stdio.h>

/*
���� : �־��� �̸��� �ݴ� ������ ����Ѵ�.

�ذ� ��� : ���ڿ� 2���� �Է¹ް� �ݴ� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : UVaH 2012 P��
*/

char first[32], last[32];

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s%s", first, last);
        printf("Case %d: %s, %s\n", tt, last, first);
    }
    return 0;
}