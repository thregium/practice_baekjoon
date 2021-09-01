#include <stdio.h>

/*
���� : 2���� �������������� �� ���� N(N < 100)�� �־��� ��, ���� �� ���� �̰���� ���Ѵ�.

�ذ� ��� : 2���� �� ���� �Է¹��� �� ���� ����� Ȯ���ϰ� ������ �̱� Ƚ���� �� ���� �� ���� �̱� ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : PacNW 2007 A��
*/

int main(void) {
    int t, n, p1, p2;
    char c1, c2;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        p1 = 0, p2 = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %c %c", &c1, &c2);
            if ((c1 == 'R' && c2 == 'S') || (c1 == 'S' && c2 == 'P') || (c1 == 'P' && c2 == 'R')) p1++;
            else if ((c1 == 'S' && c2 == 'R') || (c1 == 'P' && c2 == 'S') || (c1 == 'R' && c2 == 'P')) p2++;
        }
        if (p1 > p2) printf("Player 1\n");
        else if (p1 < p2) printf("Player 2\n");
        else printf("TIE\n");
    }
    return 0;
}