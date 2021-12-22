#include <stdio.h>

/*
���� : W(W <= 600)���� �ܾ�(25�� ����, �ҹ���)�� �־�����, ���� L(L <= 300)�� ���ڿ�(�ҹ���)�� �־�����.
�̶�, ���ڿ��� �Ϻ� ���ڸ� ���� �ܾ�� ���ڿ��� ���� �� �ֵ��� �ϱ� ���ؼ� ������ �ϴ� ���ڿ��� �ּ� ������ ���Ѵ�.

�ذ� ��� : dp(x)�� x��° ���ڱ����� �ִ� �� �� ������ �� ������ �ּ� ������ �����ϸ� ���� dp(l)�� �ȴ�.
�ܾ ���ٰ� �����ϸ� dp(x) = x�� ���̴�. ���� ù ��° ���ں��� �ش� ���� ���Ŀ��� ���ڸ� ������
���ڿ����� �ش� �ܾ ã�� �� �ִ� ù ��° ��ġ�� ã�´�. �̴� �׸����ϰ� ���� ���� ã�� �� �ִ�.
�� ��ġ ���ķ� ������ ���� �ܾ��� ���̸� p, ���ڿ����� ã�� ������ ��ġ�� i, ������ � ��ġ�� j��� ���� ��
dp(j) = dp(j) �Ǵ� dp(i) + (j - i) - p �� ���� ���� �ȴ�. �̸� ���ڸ��� ��� �ܾ ���� �����ϸ�
���ڿ����� �ش� �ܾ �� �κ��� ���ڸ� ������ �ʵ��� �Ͽ� ����� ������ �ּ� ����(dp(l))�� ���� �� �ִ�.

�ֿ� �˰����� : DP, ���ڿ�

��ó : USACO 2007F S1��
*/

char s[384], word[768][32];
int mem[384];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int w, l, p, r;
    scanf("%d %d", &w, &l);
    scanf("%s", s);
    for (int i = 0; i < w; i++) {
        scanf("%s", word[i]);
    }
    for (int i = 0; i <= l; i++) mem[i] = i;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            p = 0;
            for (int k = i; k < l; k++) {
                if (s[k] == word[j][p]) p++;
                if (word[j][p] == '\0') mem[k + 1] = small(mem[k + 1], mem[i] + k + 1 - i - p);
            }
        }
    }
    printf("%d", mem[l]);
    return 0;
}