#include <stdio.h>
#include <string.h>

/*
���� : ���� 26 ������ ���� �ٸ� �ҹ��ڷ� �̷���� ���ڿ� v�� 10^6 ������ v�� �ִ� ���ڵ�� �̷����
���ڿ� s�� �־�����. �׸��� N(N <= 10^6)���� v�� �ִ� ���ڵ�� �̷���� ���ڿ� q_i�� �־��� ��,
�� q_i�� ���� �� ���ڿ��� s�� �ִ� ��κм����� �� ���Ѵ�. ��� q_i ������ ���� 10^6 ���ϴ�.

�ذ� ��� : 1885���� ��Ĵ�� �ִ� ��κм����� ���̸� ���Ѵ�.
�׿� �Բ� s�� �� ���ڿ� ���� ���� �յ� �����ش�. �� ���� N���� ���ڿ��� �Է¹����鼭
���ڿ��� ���̸� Ȯ���Ѵ�. ���̰� �ִ� ��κм����� �ٸ��ٸ� �� ���ڿ��� �ִ� ��κм����� �ƴϴ�.
���̰� ���ٸ� ��κм������� Ȯ���Ѵ�. �տ��� ���� ���� ���� �̿��� ���� ������ �ڸ���
�̺� Ž������ ã�Ƴ����� ��� ���ڸ� ���ʷ� ã�� �� �ִ� �� Ȯ���ϸ� �ȴ�.
��κм����̶�� �� ���ڿ��� �ִ� ��κм����̰�, �ƴ϶�� �ִ� ��κм����� �ƴϴ�.

�ֿ� �˰��� : ���ڿ�, �׸��� �˰���, �̺� Ž��, ���� ��

��ó : PacNW 2021 B/O�� // SCUSA 2021D1 G�� // NENA 2021 L��
*/

char v[32], chk[32], s[1048576], q[1048576];
int psum[26][1048576];

int main(void) {
    int n, ans = 1, rem, slen, qlen, pos, lo, hi, mid;
    scanf("%s%s", v, s + 1);
    rem = strlen(v);
    slen = strlen(s + 1);
    for (int i = 1; s[i]; i++) {
        if (chk[s[i] - 'a'] == 0) {
            chk[s[i] - 'a'] = 1;
            rem--;
            if (rem == 0) {
                for (int i = 0; v[i]; i++) chk[v[i] - 'a'] = 0;
                rem = strlen(v);
                ans++;
            }
        }
        for (int j = 0; j < 26; j++) psum[j][i] = psum[j][i - 1];
        psum[s[i] - 'a'][i]++;
    }
    for (int i = 0; i < 26; i++) psum[i][slen + 1] = 1012345678;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", q);
        qlen = strlen(q);
        if (qlen != ans) {
            printf("0\n");
            continue;
        }
        pos = 0;
        for (int j = 0; q[j] && pos <= slen; j++) {
            lo = pos + 1, hi = slen + 1;
            while (lo < hi) {
                mid = (lo + hi) >> 1;
                if (psum[q[j] - 'a'][mid] > psum[q[j] - 'a'][pos]) hi = mid;
                else lo = mid + 1;
            }
            pos = lo;
        }
        printf("%d\n", pos > slen);
    }
    return 0;
}