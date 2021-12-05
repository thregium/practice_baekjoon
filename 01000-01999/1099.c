#include <stdio.h>
#include <string.h>
#define INF 1012345678

/*
���� : N(N <= 50)���� ���� 50 ������ �ҹ��ڷ� �̷���� �ܾ �־�����. �� �ܾ���� �Ƴ��׷��� �̿��Ͽ� ���� 50 ������
�ҹ��ڷ� �̷���� �־��� �ܾ ������� �� ��, ���� ����� ���� �Ǵ� ����� ����� ���Ѵ�. ����� ���ٸ� -1�� ����Ѵ�.
����� �� �ܾ�� ������ ��ġ���� �ʴ� ������ �����̴�.

�ذ� ��� : ���̳��� ���α׷��� �̿��Ͽ� �ذ��� �� �ִ�. �� ������ ��ġ���� �ش� ��ġ���� ������ �ܾ����
���� ���� �Ƴ��׷����� ���� Ȯ���Ѵ�. �Ƴ��׷��� ��쿡�� ���� ��ġ���� �ʴ� ������ ������ �ܾ� ���� �κ���
���� ���� ���� ���Ͽ� ���� ���� ���� ã�Ƴ�����. �̸� �ݺ��� �� �ܾ� ���� ���� ���ϸ� �� ���� ���� �ȴ�.
��, INF�� ��쿡�� ����� ���� ���̹Ƿ� -1�̴�.

�ֿ� �˰��� : DP

��ó : SRM 411 D1A / D2B
*/

char s[64], word[64][64];
int wlen[64], mem[64], cnt[26], cnt2[26];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, l, t;
    scanf("%s", s);
    l = strlen(s);
    for (int i = 1; i <= l; i++) mem[i] = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", word[i]);
        wlen[i] = strlen(word[i]);
    }
    for (int i = 1; i <= l; i++) {
        for (int j = 0; j < n; j++) {
            if (wlen[j] > i) continue;
            for (int k = 0; k < wlen[j]; k++) {
                cnt[s[i - wlen[j] + k] - 'a']++;
                cnt2[word[j][k] - 'a']++;
            }
            t = 1;
            for (int k = 0; k < 26; k++) {
                if (cnt[k] != cnt2[k]) t = 0;
                cnt[k] = 0, cnt2[k] = 0;
            }
            if (!t) continue;

            t = 0;
            for (int k = 0; k < wlen[j]; k++) {
                t += (s[i - wlen[j] + k] != word[j][k]);
            }
            mem[i] = small(mem[i], mem[i - wlen[j]] + t);
        }
    }
    printf("%d", mem[l] == INF ? -1 : mem[l]);
    return 0;
}