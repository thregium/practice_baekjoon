#include <stdio.h>

/*
���� : �� ���� ���������� �� �� ���� Ȯ���� �־��� ��, �� �� �� �̱� Ȯ���� �� ���� ����� ã�´�.

�ذ� ��� : �� ���� �̱� Ȯ���� ���� �ڽ��� ���� ���� Ȯ���� ��밡 ���� ���� ���� Ȯ���� ���� ���ϸ� �ȴ�.
�̸� ���� ����, �� ���� Ȯ�� ���� ����(�� 1E-6) ������ ��� ���� ���� ������ ���� =�� ����ϰ�
�� �ܿ��� �� Ȯ���� ���� ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : Spot 2010F 1-3��
*/

double p1[4], p2[4];

double ax(double a) {
    if (a < 0) return -a;
    else return a;
}

int main(void) {
    int z;
    double g, a;
    scanf("%d", &z);
    for (int zz = 0; zz < z; zz++) {
        scanf("%lf%lf%lf", &p1[0], &p1[1], &p1[2]);
        scanf("%lf%lf%lf", &p2[0], &p2[1], &p2[2]);
        if (ax(p1[0] + p1[1] + p1[2] - 1) > 0.000001) return 1;
        if (ax(p2[0] + p2[1] + p2[2] - 1) > 0.000001) return 1;
        g = 0.0, a = 0.0;
        for (int i = 0; i < 3; i++) {
            g += p1[i] * p2[(i + 2) % 3];
            a += p1[i] * p2[(i + 1) % 3];
        }
        if (ax(g - a) < 0.000000001) printf("=");
        else if (g > a) printf("GOSIA");
        else printf("ADAM");
        printf("\n");
    }
    return 0;
}