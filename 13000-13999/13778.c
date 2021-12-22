#include <stdio.h>
#include <string.h>
#define INF 1012345678

/*
���� : N(N <= 120)���� �ǿ����� ��ȣ�� �̸��� ���� �־����� �� �ൿ�� ���� ���� ��ȭ�� A(A < 200)�� �־��� ��,
���� ������ ���� �ǿ��� ���� �ǿ��� �̸����� ��ȣ ������ ���� ����Ѵ�.

�ذ� ��� : �� �ǿ��� ��ȣ�� �̸����� ������Ų ��, �ൿ�� ���� �� ��ȣ�� �ǿ����� ������ �����Ѵ�.
�� ��, ���� ���� ������ ���� ���� ������ ã��, ��ȣ ������ Ž���ϸ� �׿� ���� ������ �ǿ����� �̸����� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : NZPC 2016 H��
*/

char mp[128][32];
int score[128];

int main(void) {
    int n, x, lo = INF, hi = -INF;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &x);
        fgets(mp[x], 30, stdin);
        if (mp[x][strlen(mp[x]) - 1] == '\n') mp[x][strlen(mp[x]) - 1] = '\0';
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &x, &c);
        if (c == 'S') score[x] += 10;
        else if (c == 'A') score[x] += 7;
        else if (c == 'Q') score[x] += 5;
        else if (c == 'F') score[x] += 4;
        else if (c == 'D') score[x] -= 5;
        else if (c == 'L') score[x] -= 8;
        else if (c == 'E') score[x] -= 10;
    }
    for (int i = 1; i <= 120; i++) {
        if (mp[i][0] == '\0') continue;
        if (score[i] > hi) hi = score[i];
        if (score[i] < lo) lo = score[i];
    }
    printf("%d ", hi);
    for (int i = 1; i <= 120; i++) {
        if (mp[i][0] == '\0') continue;
        if (score[i] < hi) continue;
        printf("%s ", mp[i]);
    }
    printf("\n%d ", lo);
    for (int i = 1; i <= 120; i++) {
        if (mp[i][0] == '\0') continue;
        if (score[i] > lo) continue;
        printf("%s ", mp[i]);
    }
    return 0;
}