#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 50)���� �̸�(�ҹ���, 10�� ����)�� Ű(�Ҽ��� �Ʒ� 2�ڸ�����)�� �־��� ��, ���� Ű�� ū ������� �̸���
������� ����Ѵ�.

�ذ� ��� : ������� Ű�� ���� ū ����� �̸��� �迭�� ������� �����صΰ�, ���� ū Ű�� �׷��� ����� ����
�������ָ鼭 Ȯ���Ѵ�. �� ���� ���������� �ٲپ� ���ϵ� �Ǽ� ������ �����Ѵ�.
���� ���� ���� ����� ���� ū Ű�� ���ٸ� ���� ū ����� ���� 1 �ø���, �迭 �� �ڿ� �̸��� �߰��Ѵ�.
�� ũ�ٸ� ���� ū ����� ���� 1�� �ʱ�ȭ�ϰ� �迭�� �� ����� �̸��� �־�� ���� ���� ū Ű�� �������ָ� �ȴ�.
��� ����� ������ ������ ������ ���� ū ����� �迭�� ����Ѵ�.

�ֿ� �˰��� : ����

��ó : NZPC 2015 A��
*/

char bestname[64][16], buf[16];

int main(void) {
    int n, best, bcnt, heint;
    double height;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        best = -1;
        bcnt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s %lf", buf, &height);
            heint = height * 100 + 0.1;
            if (heint == best) {
                strcpy(bestname[bcnt++], buf);
            }
            else if (heint > best) {
                strcpy(bestname[0], buf);
                bcnt = 1;
                best = heint;
            }
        }
        if (best < 0) return 1;
        for (int i = 0; i < bcnt; i++) {
            printf("%s ", bestname[i]);
        }
        printf("\n");
    }
    return 0;
}