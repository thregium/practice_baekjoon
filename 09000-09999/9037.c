#include <stdio.h>

/*
���� : N(N <= 10)���� �������� �ɾ� ���� C_i(C_i <= 30)���� ������ ���� �ִ�. �ڽ��� �����ʿ� �ִ� �������
�ڽ��� ���� ������ ������ �ְ� ������ Ȧ������ �Ǹ� ���� �� ���� �޴� ���� �� ������ �ϸ�
��� ����� ���� ������ ���� �������� ������ �� ���尡 ���� ������ ���Ѵ�.
��, ù ���尡 �����ϱ� �� ������ Ȧ������ ��� ���� �� ���� �ް� �����Ѵ�.

�ذ� ��� : ���� ������ ������ �Է¹ް� ������ Ȧ������ ��� 1���� �޴´�. �� ���ķδ� ����� ���� ���� ������ Ȯ���ϰ�
�ٸ��ٸ� ���� ���忡 �� ����� ���� ���� �������� �ùķ��̼��� ���� ���Ѵ�. �̶�, ���� �� ����� ���� ���� ���ϸ�
������ �Ͼ �ٸ� ����� ���� �� �����Ƿ� �ӽ������� �ٸ� �迭�� ������ �ξ�� �Ѵ�.
���� Ȯ���� ���� �ӽ� �迭���� �ٽ� ���� �迭�� ������ �Űܵθ� �ȴ�.
����� ���� ���� �������� �׶����� �帥 ���� ���� ����Ѵ�.

�ֿ� �˰����� : ����, �ùķ��̼�

��ó : Seoul 2009I B��
*/

int candy[16], nt[16];

int main(void) {
    int t, n, r, tmp;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &candy[i]);
            if (candy[i] & 1) candy[i]++;
        }
        r = 0;
        while (1) {
            tmp = 1;
            for (int i = 1; i < n; i++) {
                if (candy[i] != candy[i - 1]) tmp = 0;
            }
            if (tmp) {
                printf("%d\n", r);
                break;
            }
            for (int i = 0; i < n; i++) {
                nt[i] += (candy[i] >> 1);
                nt[(i + 1) % n] += (candy[i] >> 1);
            }
            for (int i = 0; i < n; i++) {
                candy[i] = nt[i];
                nt[i] = 0;
                if (candy[i] & 1) candy[i]++;
            }
            r++;
        }
    }
    return 0;
}