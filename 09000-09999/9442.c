#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : N(N <= 20)���� ���� 30 ������ �빮�ڷ� �̷���� ���ڿ��� �����ϵ�, �־��� ������ ������� �켱������ �ٲپ�
������ ����� ����Ѵ�.

�ذ� ��� : �־��� ������ ���������� �� ������ ���� ����, �ش� ������ ���� ���ڿ��� �ٲپ �ش��ϴ� ���ڿ���
�����Ѵ�. �� ����, �־��� ������� �ٽ� ���ڿ��� �ٲپ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : MidC 2013 H��
*/

char perm[32], permr[32], word[32][32];

int main(void) {
    int n;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%s", perm);
        for (int i = 0; i < 26; i++) permr[perm[i] - 'A'] = 'A' + i;
        for (int i = 0; i < n; i++) {
            scanf("%s", word[i]);
            for (int j = 0; word[i][j]; j++) word[i][j] = permr[word[i][j]- 'A'];
        }
        qsort(word, n, sizeof(char) * 32, strcmp);
        for (int i = 0; i < n; i++) {
            for (int j = 0; word[i][j]; j++) word[i][j] = perm[word[i][j] - 'A'];
        }
        printf("year %d\n", tt);
        for (int i = 0; i < n; i++) {
            printf("%s\n", word[i]);
        }
    }
    return 0;
}