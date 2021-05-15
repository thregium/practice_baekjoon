#include <stdio.h>
#include <deque>
using namespace std;

/*
���� : N(N <= 1000)���� ǳ���� ���� ��, �� ǳ������ 1������ ���ʷ� ��Ģ�� �°� �Ͷ߸� ������ ���Ѵ�.
��Ģ�� ǳ���� ���� �� X�� ����� ��� �ð�������� X��°, ������ ��� �ݽð�������� -X��° ǳ���� �Ͷ߸��� ���̴�.
��, �̹� ���� ǳ���� ���� �ʴ´�.

�ذ� ��� : ���� �̿��� Ǫ�� ���� �����ϴ�. �ð�������� ������ ������ (X - 1)��ŭ ���� �ڷ� �տ� �ִ� ������ ������,
�ݽð�������� ������ ������ -X��ŭ ���� ������ �ڿ� �ִ� ������ �������� �ȴ�.

�ֿ� �˰��� : �ڷᱸ��, ��
*/

deque<pair<int, int>> dq;

int main(void) {
    int n, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        dq.push_back(pair<int, int>(a, i));
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", dq.front().second);
        a = dq.front().first;
        dq.pop_front();
        if (i == n - 1) break;
        while (a > 1) {
            dq.push_back(dq.front());
            dq.pop_front();
            a--;
        }
        while (a < 0) {
            dq.push_front(dq.back());
            dq.pop_back();
            a++;
        }
    }
    return 0;
}