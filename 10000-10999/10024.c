#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : ���� N(N <= 100)�� 1���� N������ �ڿ����� �̷���� ���� 2���� �־��� ��, ù ������ �� ��° ������ �ٲٱ� ����
�� ������ ����Ŭ ���·� ������ �Ϸ��� �Ѵ�. ��� ���� �ִٸ� �� ���� �� �ڸ��� �ű�� �� ���� �ִ�
�ڸ��� �ִ� ���� �ٽ� �ű�� ���� �ݺ��Ͽ� �ش��ϴ� ����Ŭ�� �����ϴ� ����̴�.
�̶�, ����Ŭ�� ������ ���� �� ����Ŭ�� ũ�⸦ ���Ѵ�. ���� 1�� ����Ŭ�� �������� �ʴ´�.
����Ŭ�� ���ٸ� �� ��°�� -1�� ����Ѵ�.

�ذ� ��� : ������ �־������ �����Ѵ�. ���� �湮���� ���� ��ġ�� ������ �ű� ��ġ�� �ű�� ���� �ݺ��ؾ� �ϹǷ�
�� ��° ������ ��ġ�� �� ���Һ��� �̸� �����صд�. �湮���� ���� ��ġ�� ���� �� ���� �Űܾ� �ϴ��� Ȯ���ϰ�
�Űܾ� �Ѵٸ� ����Ŭ�� ������ 1 �ø���, ����Ŭ�� ���󰣴�.

�ֿ� �˰��� : ����

��ó : USACO 2014M B1��
*/

int a[128], b[128], order[128], vis[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("reorder.in", "r");
        fo = fopen("reorder.out", "w");
    }
    int n, shift = 0, longest = -1, len = 0, cur, nxt;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        order[b[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        if (order[a[i]] == i) continue;
        cur = i;
        len = 0;
        while (!vis[cur]) {
            nxt = order[a[cur]];
            vis[cur] = 1;
            cur = nxt;
            len++;
        }
        shift++;
        if (len > longest) longest = len;
    }
    printf("%d %d", shift, longest);
    return 0;
}