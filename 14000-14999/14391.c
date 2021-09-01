#include <stdio.h>

/*
���� : N * M(N, M <= 4) ũ���� ���ڿ� ������ ���� �ִ�. �� ������ ���� �Ǵ� ���η� ������ �߶�
������ ������ ���� ���� ũ���� �� ��, ���� ���� ���Ѵ�.

�ذ� ��� : ��� ��츦 ���� Ž���ϴ� ���� ���� �ذ� �����ϴ�. �� ���� �� ĭ���� �����ؼ� ���� �� �ִ� ��� ��츦 ���ƺ���,
���������� ����ִ� ���� ó�� ĭ���� �����ؼ� ��� ��츦 ���ƺ���. �̸� �ݺ��ϴ� ������ ĭ���� ���� ���� �Ǹ�
���� �ִ񰪰� ���� �ִ��� �����Ѵ�. �� ���� �� ���� ū ���� ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ
*/

char nums[8][8], chk[32];
int best = 0, n, m;

void track(int pos, int sum) {
    if (pos >= (n - 1) * 4 + m) {
        if (sum > best) best = sum;
    }
    int x = (pos >> 2), y = (pos & 3), t = 0, npos = pos, l = n;
    for (int i = x; i < n; i++) {
        t *= 10;
        t += nums[i][y] - '0';
        if (chk[i * 4 + y]) {
            l = i;
            break;
        }
        else chk[i * 4 + y] = 1;
        while (chk[npos] || (npos & 3) >= m) npos++;
        track(npos, sum + t);
    }
    for (int i = x + 1; i < l; i++) chk[i * 4 + y] = 0;
    t = nums[x][y] - '0', npos = pos, l = m;
    for (int i = y + 1; i < m; i++) {
        t *= 10;
        t += nums[x][i] - '0';
        if (chk[x * 4 + i]) {
            l = i;
            break;
        }
        else chk[x * 4 + i] = 1;
        while (chk[npos] || (npos & 3) >= m) npos++;
        track(npos, sum + t);
    }
    for (int i = y; i < l; i++) chk[x * 4 + i] = 0;
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", nums[i]);
    }
    track(0, 0);
    printf("%d", best);
    return 0;
}