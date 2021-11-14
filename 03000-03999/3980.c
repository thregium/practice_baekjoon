#include <stdio.h>

/*
���� : 11���� ������ ������ �� �ɷ�ġ�� �־��� ��, ��� �������� �� �����ǿ� ��ġ�ϸ� ���� �� �ִ�
�ִ� �ɷ�ġ ���� ���Ѵ�. ��, �ɷ�ġ 0�� ������ ��ġ�� �� ����. �� �������� �ִ� 5���� �������Ը� �����ϴ�.

�ذ� ��� : �� �������� �ִ� 5���Ը� �����ϱ� ������ �� �����Ǹ��� ��Ʈ��ŷ�� �ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ

��ó : GCPC 2010 G��
*/

int arr[16][16], chk[16];
int best = -1;

void track(int x, int r) {
    if (x == 11) {
        if (r > best) best = r;
        return;
    }

    for (int i = 0; i < 11; i++) {
        if (arr[x][i]) {
            if (chk[i]) continue;
            chk[i] = 1;
            track(x + 1, r + arr[x][i]);
            chk[i] = 0;
        }
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        best = -1;
        track(0, 0);
        printf("%d\n", best);
    }
    return 0;
}