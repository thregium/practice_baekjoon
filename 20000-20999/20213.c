#include <stdio.h>

/*
���� : ��밡 ������ ������� ��� ī����� ����� ¦�� ���߷��� �� ��,
������ ī����� ������ ������ �� �ִٸ� ��� �ؾ� �׻� �־��� ���((N * 2 - 1) * 2ȸ ������)�� ���� �� �ִ����� ���α׷����Ѵ�.

�ذ� ��� : ù ��°�� ������ ���� ���, �̹� ��� ���� ������ ��찡 �ƴ� �̻�, ���ݱ��� �������� ���� ���� �����־�� �Ѵ�.
�̹� ��� ���� ������ٸ� 1���� ������� �� ��� �ϳ��� �����ش�. ���� �̹� ������ ī�尡 ���� ��쿡�� �� ī�忡 �ִ� ���� ������� �Ѵ�.
�� ��°�� ������ ������ �� ���� ������ ���� �ִٸ�, �� ���� �����ְ�, �ƴ� ��쿡�� ���ο� ���� �����ָ� �ȴ�.
���� �̶��� �̹� ������ ī�尡 ���� ��쿡�� �� ī�忡 �ִ� ���� ������� �Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : BAPC 2020P A��
*/

int cards[20480], cc[10240];

int main(void) {
    int n, x, y, cnt = 1, toshow = 1;
    scanf("%d", &n);
    for (int i = 0; i < n * 2 - 1; i++) {
        scanf("%d", &x);
        if (cards[x]) printf("%d\n", cards[x]);
        else {
            if (cnt > n) {
                cards[x] = toshow++;
                printf("%d\n", cards[x]);
            }
            else {
                cards[x] = cnt++;
                printf("%d\n", cards[x]);
            }
            cc[cards[x]]++;
        }
        fflush(stdout);
        scanf("%d", &y);
        if (cards[y]) printf("%d\n", cards[y]);
        else {
            if (toshow + 1 >= cnt && cnt <= n) {
                cards[y] = cnt++;
                printf("%d\n", cards[y]);
            }
            else {
                cards[y] = toshow++;
                printf("%d\n", cards[y]);
            }
            cc[cards[y]]++;
        }
        fflush(stdout);
        //while (cards[x] > n || cards[x] < 0) n = n;
        //while (cards[y] > n || cards[y] < 0) n = n;
        //while (cc[cards[x]] > 2 || cc[cards[y]] > 2) n = n;
    }
    return 0;
}