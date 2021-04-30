#include <stdio.h>
#include <math.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : ������ ���� ��ǥ A���� B�� �̵��� ��, ��ǥ C�� D�� �ִ� �ڷ����͸� �̿� �����ϴٰ� �Ѵ�.
�ڷ����͸� �̿��ϸ� ��� C�� D ���̸� �̵� �����ϰ�, ��ǥ 1��ŭ �����̴µ� �ð��� 1�� ��ٰ� �ϸ�, A�� B�� �̵��ϴµ� �ɸ��� �ּ� �ð��� ���Ѵ�.

�ذ� ��� : A���� B�� ���� ������δ� A���� �������� B�� ���ų�, A���� C�� �� ���� D���� B�� ���ų�, A���� D�� �� ���� C���� B�� ���� 3������ �ִ�.
�� �� ������ �Ÿ��� �� ���� ��ǥ�� �� ���� ���밪�� �����Ƿ�, �� 3������ ������ ��� �����ϴ�. �� ���� �� ���� ���� ���� ������ �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : USACO 2018F B1��
*/

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("teleport.in", "r");
        fo = fopen("teleport.out", "w");
    }
    int a, b, c, d, r1, r2, r3;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    r1 = abs(a - c) + abs(b - d);
    r2 = abs(a - d) + abs(b - c);
    r3 = abs(a - b);
    printf("%d", r1 < r2 && r1 < r3 ? r1 : r2 < r3 ? r2 : r3);
    return 0;
}