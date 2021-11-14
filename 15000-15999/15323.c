#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : K(K <= 100000)���� ���ڿ�(�ҹ���, 21��)�� �־�����, N(N <= 100000)���� �ҹ��ڰ� �־�����.
�� ���ڰ� �־��� �� ���� �� ���ڷ� �����ϴ� ���ڿ� ��� ���������� �� ���ڰ� �־��� ��°�� ���ڿ��� ���Ѵ�.

�ذ� ��� : �� ���ڿ��� �Է¹��� ����, ù ���ں��� �з��ϰ� ���� �����Ѵ�. �� �ķδ� �� ���ں��� ������ ���� Ƚ����
�����صΰ� ���ڰ� �־��� �� ���� �׶��� �ܾ ����ϰ� ���� Ƚ���� �ٲٸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : COCI 17/18#2 2��
*/

char buff[24], s2[26][103000][24];
int cnt[26], pos[26];

int main(void) {
    int k, n;
    char c;
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) {
        scanf("%s", buff);
        strcpy(s2[buff[0] - 'a'][cnt[buff[0] - 'a']++], buff);
    }
    for (int i = 0; i < 26; i++) {
        qsort(s2[i], cnt[i], sizeof(char) * 24, strcmp);
    }
    for (int i = 0; i < n; i++) {
        scanf(" %c", &c);
        printf("%s\n", s2[c - 'a'][pos[c - 'a']]);
        pos[c - 'a'] = (pos[c - 'a'] + 1) % cnt[c - 'a'];
    }
    return 0;
}