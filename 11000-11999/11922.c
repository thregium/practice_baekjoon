#include <stdio.h>

/*
���� : N * 4���� ī�尡 �־��� ��, �� ī����� ������ ���Ѵ�. (����ǥ ����)

�ذ� ��� : ���ؿ� �°� ������ ���Ѵ�.

�ֿ� �˰��� : ����

��ó : COCI 15/16#6 1��
*/

char cd[8];

int main(void) {
    int n, r = 0;
    char b;
    scanf("%d %c", &n, &b);
    for (int i = 0; i < n * 4; i++) {
        scanf("%s", cd);
        if (cd[1] == b) {
            if (cd[0] == 'A') r += 11;
            else if (cd[0] == 'K') r += 4;
            else if (cd[0] == 'Q') r += 3;
            else if (cd[0] == 'J') r += 20;
            else if (cd[0] == 'T') r += 10;
            else if (cd[0] == '9') r += 14;
        }
        else {
            if (cd[0] == 'A') r += 11;
            else if (cd[0] == 'K') r += 4;
            else if (cd[0] == 'Q') r += 3;
            else if (cd[0] == 'J') r += 2;
            else if (cd[0] == 'T') r += 10;
        }
    }
    printf("%d", r);
    return 0;
}