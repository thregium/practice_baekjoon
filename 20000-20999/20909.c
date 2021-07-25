#include <stdio.h>

/*
���� : ���ﰢ�� �Ѱ��� N(N <= 1000)���� ���ﰢ������ ������ ����� ����Ѵ�. ��, ���ﰢ���� �� ���� ���̴� �ִ� 2������ �� �� �ִ�.

�ذ� ��� : �� ������ ���� �ﰢ��, �� ���� ū �ﰢ������ �����ٰ� �ϸ�, ū �ﰢ���� ���̰� 1 �þ �� ���� ���� �ﰢ���� ����
2���� �þ�� ���� �� �� �ִ�. ū �ﰢ���� 1���� ��쿡�� 4 �̻��� ��� ¦���� ���� �ش� ��츦 ���� �� �ְ�,
4���� ���(1���� ��쿡�� ���� �ﰢ���� 4����� ���)���� 7 �̻��� ��� Ȧ���� ���� ���� �� �ִ�.
����, 1�� ��쿡�� �� ��ü�� �θ� �ȴ�. �� ���� ��쿡�� ������ ���� �Ұ����ϴ�.

�ֿ� �˰����� : ������, ������, ���̽� ��ũ

��ó : GCPC 2020 I��
*/

int main(void) {
    int n, x;
    scanf("%d", &n);
    if (n % 2 == 0 && n > 2) {
        printf("1 %d %d\n", n / 2 - 1, n / 2);
        printf("B 0 1 U\n");
        for (int i = 0; i < (n >> 1); i++) {
            printf("A %d 0 U\n", i);
        }
        for (int i = 0; i < (n >> 1) - 1; i++) {
            printf("A %d 1 D\n", i);
        }
    }
    else if (n > 5) {
        x = (n - 5) / 2;
        printf("2 %d %d\n", x, n - 3);
        printf("B 0 2 U\nB 0 %d U\nB 0 %d D\nB %d 2 U\n", 2 + x, 2 + x, x);
        for (int i = 0; i < (n >> 1) - 1; i++) {
            printf("A %d 0 U\n", i * 2);
        }
        for (int i = 0; i < (n >> 1) - 2; i++) {
            printf("A %d 2 D\n", i * 2);
        }
    }
    else if (n == 1) printf("1 1 1\nA 0 0 U");
    else printf("impossible");
    return 0;
}