#include <stdio.h>
#include <assert.h>

/*
���� : ���� L(L <= 15)�� �ҹ��ڷ� �̷���� �ܾ� D(D <= 5000)���� �־�����. N(N <= 500)���� ���Ͽ� ����
�� ���Ͽ� �����ϴ� �ܾ��� ������ ���Ѵ�. �� ������ L���� ������ �̷���� �ְ�,
�� ������ ���ĺ� �� �� �Ǵ� ��ȣ ���� ���ĺ���� �̷���� �ִ�.

�ذ� ��� : �� ������ �Է¹��� �� ���� �� ������ ���ԵǴ� ���ĺ����� ã�Ƴ�����.
�̴� ��ȣ ���̰� 0�� �� ���� ������ �̵��ϰ�, ���ĺ��� ������ ���� ������ �� ���ĺ��� �߰��ϴ� �������
���� �����ϴ�. �� ����, �� �ܾ�� ���� ������� Ȯ���ϸ� ��� ���ĺ��� ������ ���ԵǴ� �� Ȯ���Ͽ�
�׷��� ���ĺ��� ����, �� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ���Ʈ ����

��ó : GCJ 2009Q A2��
*/

char word[5120][32], s[512];
int chk[5120], finding[16][32];

int main(void) {
    int l, d, n, par, pt, res = 0;
    scanf("%d %d %d", &l, &d, &n);
    for (int i = 0; i < d; i++) {
        scanf("%s", word[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        par = 0, pt = 0;
        for (int j = 0; j < d; j++) chk[j] = 1;
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < 26; k++) finding[j][k] = 0;
        }
        for (int j = 0; s[j]; j++) {
            if (s[j] == '(') par++;
            else if (s[j] == ')') par--;
            else finding[pt][s[j] - 'a'] = 1;
            if (par == 0) pt++;
        }
        assert(pt == l);
        
        res = 0;
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < d; k++) {
                if (!finding[j][word[k][j] - 'a']) chk[k] = 0;
            }
        }
        for (int j = 0; j < d; j++) res += chk[j];
        printf("Case #%d: %d\n", i, res);
    }
    return 0;
}