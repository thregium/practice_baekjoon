#include <stdio.h>

/*
���� : �� ���� �ƴ� ���� X, Y(X, Y <= 1000)�� �־��� ��, X + Y�� 13���� Ȯ���ϰ� �ƴ϶��
X�� Y�� ���� ����� ����Ѵ�. �̸� X�� Y�� ��� 0�� �� ���� �ݺ��Ѵ�.

�ذ� ��� : ������ �־������ �����Ѵ�.

�ֿ� �˰��� : ����

��ó : VTH 2014 D��
*/

int main(void) {
    int x, y;
    while (1) {
        scanf("%d %d", &x, &y);
        if (x + y == 0) break;
        else if (x + y == 13) printf("Never speak again.\n");
        else if (x == y) printf("Undecided.\n");
        else if (x < y) printf("Left beehind.\n");
        else printf("To the convention.\n");
    }
    return 0;
}