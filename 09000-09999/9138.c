#include <stdio.h>
#include <string.h>

/*
���� : R * S(R, S <= 250) ũ���� ���ڿ� ���ĺ����� �ִ�. �� ���ĺ��� C(C <= 26)���� �̸��� �̴ϼ��̰�,
�� ����� �̴ϼ��� ���� �ٸ���. �� ����� �̸��� 61�� ������ ��ҹ��ڷ� �̷���� ������,
ù �ڴ� �빮���̴�. �̶�, ���� �ڱ� �̴ϼ��� ���ĺ��� ���� ����� �̸��� ����Ѵ�.
�׷��� ����� �׻� �����ϰ� �־�����.

�ذ� ��� : �� �̴ϼȺ��� �̸��� �����ϰ� ������ ���ĺ� ������ �� ����, ���� ���� ���� ���ϸ� �ȴ�.
��, C�� 1�� ��� ���ĺ��� ������ �� ����� �̸��� ����ؾ� �Կ� �����Ѵ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : CTU 2001 D��
*/

char worm[26][64], buff[256];
int cnt[26];

int main(void) {
    int r, s, c, best, bw = -1;
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2001\\d.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2001\\d_t.out", "w", stdout);
    while (1) {
        scanf("%d %d %d", &r, &s, &c);
        if (r == 0) break;
        for (int i = 0; i < c; i++) {
            scanf("%s", buff);
            strcpy(worm[buff[0] - 'A'], buff);
            cnt[buff[0] - 'A'] = 103000;
        }
        for (int i = 0; i < r; i++) {
            scanf("%s", buff);
            for (int j = 0; j < s; j++) {
                if (buff[j] != '*') cnt[buff[j] - 'A']++;
            }
        }
        best = -1, bw = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > best) {
                bw = i;
                best = cnt[i];
            }
            cnt[i] = 0;
        }
        printf("Nejzravejsi cervotoc je %s.\n", worm[bw]);
    }
    return 0;
}