#include <stdio.h>

/*
���� : N * M(N, M <= 500) ũ���� ���簢���� �־��� ��, �� ���簢���� Ʈ���̿��̳�� ��ƴ���� ä�� �� �ִ��� ���Ѵ�.

�ذ� ��� : Ʈ���̿��̳�� ä��� ���ؼ��� N * M�� 3�� ������� �Ѵ�. �׷���, 1 * 3 �������� ���� ä���
N�� M �� ��� �� ���� 3�� ����� ��� �׻� ä�� �� �ִ�. �̷��� ���� N * M�� 3�� ����� ��� ����̹Ƿ�,
N * M�� 3�� ������ ä�� �� �ְ�, ����� �ƴ϶�� ä�� �� ����.

�ֿ� �˰����� : ����, ��Ģ����
*/

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%s", n * m % 3 ? "NO" : "YES");
    return 0;
}