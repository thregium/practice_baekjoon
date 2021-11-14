#include <stdio.h>

/*
���� : 90�а� �ϴ� �౸���� 5�� ���� �� ���� ���� Ȯ���� ������� �־��� ��, �� �� �� �� ���̶�
���� ���� �Ҽ��� Ȯ���� ���Ѵ�.

�ذ� ��� : �ð��� �� ���� ���� Ƚ���� ��͸� �Ѵ�. �̶�, �ѹ� Ȯ���� ���� �ٽ� Ȯ������ �ʵ���
�޸������̼��� ����� �Ѵ�. �ִ� ���� ���� ���� 18���� �Ұ��ϹǷ� �Ҽ� ���δ� �ϵ��ڵ��ص� �ȴ�.
�� Ȯ���� 4������ ������ �� ���� ���� ���ο� ���� ���� �ȴ�.

�ֿ� �˰��� : DP, Ȯ����

��ó : SRM 422 D1A / D2B
*/

int isodd[20] = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1 };
double mem[32][32][32];
char chk[32][32][32];

double getprob(int t, int a, int b, int ag, int bg, double p) {
    if (t == 18) return (isodd[ag] | isodd[bg]) * p;
    if (chk[t][ag][bg]) return mem[t][ag][bg];
    chk[t][ag][bg] = 1;
    return mem[t][ag][bg] = getprob(t + 1, a, b, ag, bg, p * (100 - a) * (100 - b) / 10000.0)
        + getprob(t + 1, a, b, ag, bg + 1, p * (100 - a) * b / 10000.0)
        + getprob(t + 1, a, b, ag + 1, bg, p * a * (100 - b) / 10000.0)
        + getprob(t + 1, a, b, ag + 1, bg + 1, p * a * b / 10000.0);
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%.9f", getprob(0, a, b, 0, 0, 1.0));
    return 0;
}