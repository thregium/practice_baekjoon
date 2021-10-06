#include <stdio.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100000)���� '1'�� '0'���� �̷���� ���ڿ��� �־�����. �� ���ڿ����� '0' �ΰ��� '1'�� �ٲپ�
���� ����� '1' ������ �Ÿ��� ���� �ֵ��� �� ���� �Ÿ��� ���Ѵ�. ���ڿ����� '0'�� �ּ��� 2�� �̻� �ִ�.

�ذ� ��� : ���� ���� �� '1' ������ �Ÿ��� �� ��°�� �� '1' ������ �Ÿ�, �׸��� �׵� ������ ���� ��ġ��
ù ��° '1', ������ '1'�� ��ġ�� ���Ѵ�. ���� �� '1' ������ �Ÿ� / 3�� �� ��°�� �� '1' ������ �Ÿ� / 2��
���� ��ġ, N - 1 - ������ ��ġ���� ���� ũ�ٸ� �� '1' ���̿� �� '1'�� ����ִ� ���� �����̴�.
�ƴ� ��쿡�� ���� �� '1'�� ���� ��ġ, N - 1 - ������ ��ġ�� ���� ���� ū ������ ���� �ָ� ���������� '1'�� �ְ�
���� ������� �� �� �� �ִ´�.
'1'�� ����־����� ���� ���� ����� '1'�� �Ÿ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ���̽� ��ũ

��ó : USACO 2019O B1��
*/

char s[103000];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("socdist1.in", "r");
        fo = fopen("socdist1.out", "w");
    }
    int n, first, last, small, big, big2, bn, b2n;
    scanf("%d", &n);
    scanf("%s", s);
    first = -1, last = -1, small = INF, big = -1, big2 = -1, bn = -1, b2n = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (first < 0) first = i;
            if (last >= 0 && (i - last) > big) {
                big2 = big;
                b2n = bn;
                big = i - last;
                bn = last;
            }
            else if (last >= 0 && (i - last) > big2) {
                big2 = i - last;
                b2n = last;
            }
            last = i;
        }
    }
    if (last < 0) {
        printf("%d", n - 1);
        return 0;
    }

    if (big / 3 > big2 / 2 && big / 3 > first && big / 3 > n - last - 1) {
        s[bn + big / 3] = '1';
        s[bn + big / 3 * 2] = '1';
        first = -1, last = -1, small = INF, big = -1, bn = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (first < 0) first = i;
                if (last >= 0 && (i - last) < small) {
                    small = i - last;
                }
                last = i;
            }
        }
        printf("%d", small);
        return 0;
    }

    big >>= 1;
    if (first > big) {
        if (n - last - 1 > first) s[n - 1] = '1';
        else s[0] = '1';
    }
    else if (n - last - 1 > big) s[n - 1] = '1';
    else s[bn + big] = '1';

    first = -1, last = -1, small = INF, big = -1, big2 = -1, bn = -1, b2n = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (first < 0) first = i;
            if (last >= 0 && (i - last) > big) {
                big2 = big;
                b2n = bn;
                big = i - last;
                bn = last;
            }
            else if (last >= 0 && (i - last) > big2) {
                big2 = i - last;
                b2n = last;
            }
            last = i;
        }
    }
    big >>= 1;
    if (first > big) {
        if (n - last - 1 > first) s[n - 1] = '1';
        else s[0] = '1';
    }
    else if (n - last - 1 > big) s[n - 1] = '1';
    else s[bn + big] = '1';


    first = -1, last = -1, small = INF, big = -1, bn = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (first < 0) first = i;
            if (last >= 0 && (i - last) < small) {
                small = i - last;
            }
            last = i;
        }
    }
    printf("%d", small);
    return 0;
}