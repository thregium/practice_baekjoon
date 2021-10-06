#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : ���� N(N <= 100000)�� 'C', 'O', 'W'�� �̷���� ���ڿ��� �־�����. �� ���ڿ����� 'C', 'O', 'W'�� �������
�̷���� �������� ������ ���Ѵ�.

�ذ� ��� : �ڿ������� ���� ���� ���ϸ� W�� ���� ������ ���Ѵ�. �� �������δ� 'O'�� �ִ� ���ڸ���
������ 'W' ������ ���ϸ� 'O', 'W'�� ������ ���Ѵ�. ����������, 'C'�� ���� ������ �ϸ� ù ��° ĭ��
'C' �迭�� ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ���շ�, ���� ��

��ó : USACO 2015F B2��
*/

char s[103000];
int w[103000];
long long o[103000], c[103000];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("cow.in", "r");
        fo = fopen("cow.out", "w");
    }
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = n; i >= 0; i--) {
        w[i] = w[i + 1] + (s[i] == 'W');
    }
    for (int i = n; i >= 0; i--) {
        if (s[i] != 'O') o[i] = o[i + 1];
        else o[i] = o[i + 1] + w[i];
    }
    for (int i = n; i >= 0; i--) {
        if (s[i] != 'C') c[i] = c[i + 1];
        else c[i] = c[i + 1] + o[i];
    }
    printf("%lld", c[0]);
    return 0;
}