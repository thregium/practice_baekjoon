#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 10000)���� ������ �Ϸķ� �ְ�, �� ������ �ո�� �޸鿡�� ����(<= 10000)�� ���� ��ȣ�� �ٸ� ���� �����ִ�.
�̶�, ������ ���� 3���� ������ �� �ִٸ�, ù ��° ������ �迭���� ���� �� �ִ� �ִ񰪰�
�� ��° ������ �迭���� ���� �� �ִ� �ּڰ��� ���� ���Ѵ�.
��, �迭�� ����� ������ 2���� �����ų� 1���� ������ �͵� �����ϴ�.

�ذ� ��� : �迭�� �� ���ʿ��� �����ؼ� ���� ���¿� �ٸ��ٸ� ������ �������. �̸� ��� �������� ������ �����ϱ� ������
��� ������ ���ϴ� ���·� ���� �� �ִٴ� ���� �� �� �ִ�. ����, ù ��°������ ��� ������ ����� �� �� �ְ�,
�� ��°������ ��� ������ ������ �� �� �ִµ�, �̰��� ���� ��� ������ ����� ���� ���� �հ� ����.
����, 2 * N�� ������ ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰����� : �׸��� �˰�����

��ó : ���� 1ȸ F��
*/

int main(void) {
    int n, x, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &x);
        r += abs(x);
    }
    printf("%d", r);
    return 0;
}