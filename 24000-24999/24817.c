#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : N(N <= 100000)���� ��� �̸���, M(M <= 200000)���� ��� �̸��� ���� ��ϵ��� �־��� ��,
��� ���� P(P <= 10001) �̻��� ������� �޼��� ������� ����Ѵ�. ���� ��쿡�� "No winner!"�� ����Ѵ�.
�� ����� �̸��� 20�� ������ ��ҹ��ڷ� �־�����.

�ذ� ��� : �� ��� �̸����� ������ ����, ����� �־��� �� ���� ��ġ�� ã�Ƴ���,
�� ��ġ�� ������ �÷� �����ٰ� P �̻��� �Ǵ� ���� �̸��� ����Ѵ�. �ѹ� ����� ����� �ٽ� ������� �ʴ´�.
�׸��� ����� ����� ���ٸ� "No winner!"�� ����ϴ� �͵� ���� �ʾƾ� �Ѵ�.

�ֿ� �˰��� : ���ڿ�, ����, �̺� Ž��

��ó : VTH 2018 M��
*/

char name[103000][32], buff[32];
int score[103000], win[103000];

int main(void) {
    int n, p, m, t, pos, wc = 0;
    scanf("%d %d %d", &n, &p, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", name[i]);
    }
    qsort(name, n, sizeof(char) * 32, strcmp);
    for (int i = 0; i < m; i++) {
        scanf("%s %d", buff, &t);
        pos = (char*)bsearch(buff, name, n, sizeof(char) * 32, strcmp) - (char*)name;
        if (pos < 0) return 1;
        pos >>= 5;
        score[pos] += t;
        if (score[pos] >= p && !win[pos]) {
            win[pos] = 1;
            wc++;
            printf("%s wins!\n", name[pos]);
        }
    }
    if (wc == 0) printf("No winner!");
    return 0;
}
