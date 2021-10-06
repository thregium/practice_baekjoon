#include <stdio.h>
#include <algorithm>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)
using namespace std;

/*
���� : N(N <= 1000)���� ���� �ٸ� �ڿ����� �־��� ��, ������ �����ϴ� �� �ڿ��� (X, Y, Z)�� ���� ���Ѵ�.
X < Y < Z�̸� Y - X <= Z - Y <= (Y - X) * 2�� �����ؾ� �Ѵ�.

�ذ� ��� : ����, �־��� ������ �����Ѵ�. �� ����, X�� Y�� ��� ��쿡 ���� �����ϴ� Z�� ������ �̺� Ž���� �̿��� ���Ѵ�.
upper_bound�� lower_bound �Լ��� ����ϴ� ���� ����.

�ֿ� �˰��� : �̺� Ž��, ����

��ó : USACO 2013D B2��
*/

long long cow[1024];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("baseball.in", "r");
        fo = fopen("baseball.out", "w");
    }
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &cow[i]);
    }
    sort(cow, cow + n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            r += upper_bound(cow + j + 1, cow + n, cow[j] * 3 - cow[i] * 2) - lower_bound(cow + j + 1, cow + n, cow[j] * 2 - cow[i]);
        }
    }
    printf("%d", r);
    return 0;
}