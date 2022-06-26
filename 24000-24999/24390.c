#include <stdio.h>
#define INF 1012345678

/*
���� : ���ڷ������� 4���� ��ư�� �ִ�. �ϳ��� 10��, �ϳ��� 1��, �ϳ��� 10���̴�. �� ��ư����
���� ������ ���ο� ���� ���� �ش� �ð���ŭ �����ð��� �þ��. ������ �ϳ��� ���� ���� ��ư����,
0���� �� �Ǵ� �������� �� ������ 30�ʰ� �߰��ǰ�, �������� �ƴ� �� ������ ������ ���۵ȴ�.
�̶�, ���ϴ� ���� �ð�(10�� ����, 60�� �̳�, 10�� �̻�)�� �־����� �ش� ���� �ð��� ���߱� ����
������ �ϴ� ��ư�� �ּ� Ƚ���� ���Ѵ�.

�ذ� ��� : �� �ð� ������ ���� ������ ���θ� ������ �ΰ� �ּ� ��ư Ƚ���� ���̳��� ���α׷�������
���س�����. ���� ���� ��ư���� 30�� �߰��Ǵ� ��쿡 �����Ѵ�.

�ֿ� �˰����� : DP

��ó : �߾Ӵ� 2022 D��
*/

int mem[2][4096];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int m, s;
    for (int i = 0; i < 4096; i++) {
        mem[0][i] = INF;
        mem[1][i] = INF;
    }
    mem[0][0] = 0;
    mem[1][30] = 1;
    for (int i = 0; i <= 3600; i++) {
        mem[1][i] = small(mem[1][i], mem[0][i] + 1);
        mem[0][i + 10] = small(mem[0][i + 10], mem[0][i] + 1);
        mem[0][i + 60] = small(mem[0][i + 60], mem[0][i] + 1);
        if (i <= 3000) mem[0][i + 600] = small(mem[0][i + 600], mem[0][i] + 1);
    }
    for (int i = 0; i <= 3600; i++) {
        mem[1][i + 10] = small(mem[1][i + 10], mem[1][i] + 1);
        mem[1][i + 30] = small(mem[1][i + 30], mem[1][i] + 1);
        mem[1][i + 60] = small(mem[1][i + 60], mem[1][i] + 1);
        if (i <= 3000) mem[1][i + 600] = small(mem[1][i + 600], mem[1][i] + 1);
    }
    scanf("%d:%d", &m, &s);
    printf("%d", mem[1][m * 60 + s]);
    return 0;
}