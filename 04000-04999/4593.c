#include <stdio.h>

/*
���� : 2���� ������������ �� ����� �־��� ��, ������ �¸� Ƚ���� ���Ѵ�. ������������ �ִ� 75�� �Ͽ���.

�ذ� ��� : �� �ºο��� �� ���� Ȯ���ذ��� ù ��° ����� �� ��° ����� �̱� ��찡 ������ ������ �¸� Ƚ���� �ø���.
��� �º��� ����� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰����� : ����

��ó : MidC 2009 F��
*/

char p1[128], p2[128];

int main(void) {
    int r1, r2;
    while (1) {
        scanf("%s%s", p1, p2);
        if (p1[0] == 'E') break;
        r1 = 0, r2 = 0;
        for (int i = 0; p1[i]; i++) {
            if ((p1[i] == 'R' && p2[i] == 'S') || (p1[i] == 'P' && p2[i] == 'R') || (p1[i] == 'S' && p2[i] == 'P')) r1++;
            else if ((p1[i] == 'R' && p2[i] == 'P') || (p1[i] == 'P' && p2[i] == 'S') || (p1[i] == 'S' && p2[i] == 'R')) r2++;
        }
        printf("P1: %d\nP2: %d\n", r1, r2);
    }
    return 0;
}