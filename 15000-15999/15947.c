#include <stdio.h>

/*
���� : ������ �־��� ��Ģ��� �뷡�� �θ� ��, N(N <= 10^6)��° �ܾ �������� ���Ѵ�.

�ذ� ��� : 14������ �뷡�� �ݺ��ϴ� ���� �� �� �ִ�. ���� 14�� ���� �������� ���� ��츦 ������ ó���ϸ� �ȴ�.
truru...�� ��쿡�� 14�� ���� ���� ���� ������ �˾Ƴ� �� �ְ�, 5�� �̻����� ���ε� �� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : UCPC 2018 J��
*/

int main(void) {
    int n;
    scanf("%d", &n);
    switch ((n - 1) % 14) {
    case 0:
    case 12:
        printf("baby");
        break;
    case 1:
    case 13:
        printf("sukhwan");
        break;
    case 4:
        printf("very");
        break;
    case 5:
        printf("cute");
        break;
    case 8:
        printf("in");
        break;
    case 9:
        printf("bed");
        break;
    case 2:
    case 6:
    case 10:
        if ((n - 1) / 14 < 3) {
            printf("tu");
            for (int i = -2; i < (n - 1) / 14; i++) {
                printf("ru");
            }
        }
        else printf("tu+ru*%d", (n - 1) / 14 + 2);
        break;
    case 3:
    case 7:
    case 11:
        if ((n - 1) / 14 < 4) {
            printf("tu");
            for (int i = -1; i < (n - 1) / 14; i++) {
                printf("ru");
            }
        }
        else printf("tu+ru*%d", (n - 1) / 14 + 1);
        break;
    }
    return 0;
}