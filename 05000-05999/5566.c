#include <stdio.h>

/*
���� : N(N <= 1000)���� ĭ���� �̷���� �ֻ��� ���̿��� M(M <= 1000)�� �ֻ����� ���� ��, �� ��° �ֻ�������
�������� �����ϴ��� ���Ѵ�. N��° ĭ �Ǵ� �� ���İ� �������̰�, �� ĭ���� Ư���� ������ �� �Ǵ� �� ĭ���� �̵��ϴ� ������ ���� �ִ�.
0��° ���� ĭ���� ���� ������ ���� M�� �ȿ��� �ݵ�� �����ϴ� ��츸 �־�����.

�ذ� ��� : �� ĭ���� �̵��ϴ� ��ġ�� �̸� �����س��� ���� 1���� �����̸� �ֻ����� �ùķ��̼� �غ��� �ȴ�.

�ֿ� �˰����� : ����, �ùķ��̼�

��ó : JOI 2010�� 2��
*/

int b[1024], d[1024];

int main(void) {
    int n, m, p = 1;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &d[i]);
        p += d[i];
        p += b[p];
        if (p >= n) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}