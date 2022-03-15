#include <stdio.h>

/*
���� : N(N <= 10)���� �ٿ� ���ĺ����� �̷���� �ܾ���� �־�����. �̶�, �� ���ĺ��� ���� �ٸ�
���ڷ� ġȯ�Ͽ��� ��, �������� ������ �ܾ��� ���� ������ �ܾ�� ���� �� ���Ѵ�.
�� �ܾ��� ���̴� 10 ���ϰ�, ���� �ٸ� ���ڴ� ���ƾ� 10���̴�.
��, 0�� �ƴ� ���� 0���� ������ �� ����.

�ذ� ��� : �� ���ڵ��� 'A'���� 'J'������ �켱 �����صд�.
�׷� ����, 'A'���� 'J'���� �� �ܾ �����ϰ�, ���� ���� �� Ȯ���ϸ� �ȴ�.
�̰��� ������ ��� ���� ���ƾ� 10!���� ���̹Ƿ� �ϳ��� �غ� �� �ִ�.
�� �������� �� �տ� ���� ���ڵ��� �����صΰ� 0�� �� ���ڿ� ���� �ʵ��� �̸� ��ġ����� �Ѵ�.

�ֿ� �˰��� : ����, ���ڿ�, ��Ʈ��ŷ

��ó : SWERC 2014 A��
*/

char word[16][16], chk[26], chk2[16], isfirst[16];
int num[16];

int track(int a, int x, int n) {
    if (a == x) {
        long long sum = 0, wdn = 0, rsum = 0;
        for (int i = 0; i < n; i++) {
            wdn = 0;
            for (int j = 0; word[i][j]; j++) {
                wdn *= 10;
                wdn += num[word[i][j] - 'A'];
            }
            sum += wdn;
        }
        for (int j = 0; word[n][j]; j++) {
            rsum *= 10;
            rsum += num[word[n][j] - 'A'];
        }
        return (rsum == sum);
    }
    int r = 0;
    for (int i = 0; i <= 9; i++) {
        if (chk2[i]) continue;
        if (i == 0 && isfirst[x]) continue;
        chk2[i] = 1;
        num[x] = i;
        r += track(a, x + 1, n);
        chk2[i] = 0;
    }
    return r;
}

int main(void) {
    int n, r;
    for (int tt = 0;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", word[i]);
            for (int j = 0; word[i][j]; j++) {
                chk[word[i][j] - 'A'] = 1;
            }
        }
        for (int i = 1; i < 26; i++) chk[i] += chk[i - 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; word[i][j]; j++) {
                word[i][j] = chk[word[i][j] - 'A'] + 'A' - 1;
            }
            if (word[i][1] != '\0') isfirst[word[i][0] - 'A'] = 1;
        }
        printf("%d\n", track(chk[25], 0, n - 1));

        for (int i = 0; i < 26; i++) chk[i] = 0;
        for (int i = 0; i < 16; i++) isfirst[i] = 0;
    }
    return 0;
}