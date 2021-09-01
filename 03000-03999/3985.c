#include <stdio.h>

/*
���� : L(L <= 1000)������ �ڿ����� �ִ�. N(N <= 1000)���� ������ �־�����, �� ������ ���ʷ� ���� ������� ���� ���� ����
�ڿ������� ���� ����Ѵ�. �̶�, ���� �� ������ ���� ���� �ڿ����� ��й��� ������ ���Ѵ�. ������ ���� ���,
���� ���� ������ �켱�Ѵ�.

�ذ� ��� : L�� N�� ũ�� �ʱ� ������ �ڿ��� ����� ���� �ùķ��̼��� ���� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : COCI 12/13#4 1��
*/

int cake[1024], people[1024][3];

int main(void) {
    int l, n, longest = -1, lsz = -1, much = -1, msz = -1;
    scanf("%d%d", &l, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &people[i][0], &people[i][1]);
        if (people[i][1] - people[i][0] > lsz) {
            lsz = people[i][1] - people[i][0];
            longest = i;
        }
    }
    if (longest < 0) return 1;
    for (int i = 0; i < n; i++) {
        for (int j = people[i][0]; j <= people[i][1]; j++) {
            if (cake[j]) continue;
            cake[j] = 1;
            people[i][2]++;
        }
        if (people[i][2] > msz) {
            msz = people[i][2];
            much = i;
        }
    }
    if (much < 0) return 2;
    printf("%d\n%d", longest + 1, much + 1);
    return 0;
}