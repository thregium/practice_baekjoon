#include <stdio.h>

/*
���� : N(N <= 48, 3�� ���)���� ī�尡 �ְ�, �� ī�带 3���� ������� �й��Ѵ�.
�̶�, ī�带 ���� ����� ��ǥ ���°� �־����� ī�带 �־��� ������� ���� ���� �ݺ��Ͽ�
���ϴ� ���·� ī�带 �й��� �� �ִ� �� ���ϰ�, �����ϴٸ� �׷��� �ϱ� ���� ����� �ϴ� �ּ� Ƚ���� ���Ѵ�.
�Ұ����ϴٸ� -1�� ����Ѵ�.

�ذ� ��� : ��� ���¿��� ���ƾ� ����-���鸸 �� ���� �Ŀ��� ���� ���·� ���ƿ��� �ȴ�. (���� ����)
����, ���� ���·� ���ƿ� �� ���� ���� �۾��� �ݺ��ϸ� ��ǥ ���°� ������ ù Ƚ���� ã���� �ȴ�.
���� ���·� ���ƿ� �� ���� �׷��� ��찡 ���ٸ� -1�� ����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : SRM 415D2 3��
*/

int orig[64], cur[64], nxt[64], goal[64], shuf[64];

int compcard(int n, int* a, int* b) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

void shuffling(int n) {
    for (int i = 0; i < n; i++) nxt[i] = cur[shuf[i]];
    for (int i = 0; i < n; i++) cur[i] = nxt[i];
}

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &goal[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &shuf[i]);
    }
    for (int i = 0; i < n; i++) {
        orig[i] = i % 3;
        cur[i] = orig[i];
    }
    if (compcard(n, cur, goal)) {
        printf("0");
        return 0;
    }
    shuffling(n);
    while (!compcard(n, orig, cur)) {
        if (compcard(n, cur, goal)) {
            printf("%d", r);
            return 0;
        }
        shuffling(n);
        r++;
    }
    printf("-1");
    return 0;
}