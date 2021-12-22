#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 2300)���� �������� �ɾ��ִ�. �̶�, ���� L(L <= 10)�� ������ �־�����, �ش� ������ ������� �����ϸ�
�����ִ� ��� ��� �ش� ������ ����ŭ �̵��� ����� �����Ѵ�. ������ ������ �ٽ� ù ���Ҹ� �����Ѵ�.
�������� ���� ����� ��ȣ�� ���Ѵ�.

�ذ� ��� : 1���� N���� ť�� ������� ������ ����, L_i - 1���� ť�� �� �� ���� �� �ڷ� ������, �� ���� ���� ����
ť���� �����Ѵ�. �̸� ť�� ũ�Ⱑ 1�� �� �� ���� �ݺ��� ���� ť�� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰����� : ����, �ùķ��̼�, ť

��ó : USACO 2006O B2��
*/

int seq[16];
queue<int> q;

int main(void) {
    int n, l, x;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < l; i++) {
        scanf("%d", &seq[i]);
    }
    for (int i = 0; i < n; i++) q.push(i + 1);
    for (int i = 0; q.size() > 1; i++) {
        for (int j = seq[i % l]; j > 0; j--) {
            x = q.front();
            q.pop();
            if (j > 1) q.push(x);
        }
    }
    printf("%d", q.front());
    return 0;
}