#include <stdio.h>
#include <string.h>

/*
���� : 10���� �����ǰ��� ����� �� �������� ����, ����, ���� �־��� ��, �� ������ �ó�����
���� �� �̻��� �ǵ��� �������� © �� �ִ� �� ���Ѵ�. (���ѽð� 4��)
����, ����, ���� 15�� ������ ��ҹ��� �� '-'�� �־�����.
�������� ���� ������ �ٴ� ��� �ó��� 2, ���� ���� �ƴ����� ���� ������ ��� �ó��� 1,
���� ������ ��� �ó��� 1�� �־�����.

�ذ� ��� : 10!������ ��� ��쿡 ���� Ȯ���� ���鼭 �� �������� ��ġ���� ��
�ó����� ���� �� �̻��� �Ǵ� ��찡 �ִ� �� �Ź� Ȯ���� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���Ʈ ����

��ó : VTH 2016 I��
*/

char info[16][4][32];
int pos[16], vis[16], ed[16][16];
int res = 0;

void track(int x) {
    int syn;
    if (x == 10) {
        for (int i = 0; i < 10; i++) {
            syn = 0;
            for (int j = 1; j <= ed[i][0]; j++) {
                if (!strcmp(info[pos[i]][3], info[pos[ed[i][j]]][3])) syn += 2;
                else if (!strcmp(info[pos[i]][2], info[pos[ed[i][j]]][2])) syn += 1;
                if (!strcmp(info[pos[i]][1], info[pos[ed[i][j]]][1])) syn += 1;
            }
            if (syn < ed[i][0]) return;
        }
        res = 1;
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (vis[i]) continue;
        pos[x] = i;
        vis[i] = 1;
        track(x + 1);
        vis[i] = 0;
    }
}

int main(void) {
    int c, a, b;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        scanf("%d %d", &a, &b);
        ed[a][++ed[a][0]] = b;
        ed[b][++ed[b][0]] = a;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%s", info[i][j]);
        }
    }
    track(0);
    printf("%s", res ? "yes" : "no");
    return 0;
}