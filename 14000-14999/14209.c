#include <stdio.h>

/*
���� : N(N <= 10000)���� ī�� 13�� ������ �־��� ��, ��� ī���� ���� ���� ���Ѵ�.
���̽��� 4��, ŷ�� 3��, ���� 2��, ���� 1���̴�.

�ذ� ��� : N * 13���� ī�忡 ���� �� ī���� ������ Ȯ���ϰ� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : COCI 16/17#4 1��
*/

int main(void) {
    int n, r = 0;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 13; j++) {
            scanf(" %c", &c);
            if (c == 'A') r += 4;
            else if (c == 'K') r += 3;
            else if (c == 'Q') r += 2;
            else if (c == 'J') r++;
            else if (c == 'X') continue;
            else return 1;
        }
    }
    printf("%d", r);
    return 0;
}