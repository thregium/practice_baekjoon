#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : ũ�� N(N <= 100000)�� ���۸� ���� ����Ϳ��� ������ ������ ó���Ǵ� ������ �־��� ��,
����Ϳ� ���� ������ ���Ѵ�.

�ذ� ��� : ť�� �̿��Ѵ�. ������ ���� ������ ���� ũ�Ⱑ ���� ��� ť�� �߰��ϰ�, ������ ó���� ������
ť���� ���� ����. �������� ���� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ť

��ó : ���ִ� 2018D2 B��
*/

queue<int> q;

int main(void) {
    int n, x;
    scanf("%d", &n);
    while (1) {
        scanf("%d", &x);
        if (x > 0) {
            if (q.size() < n) q.push(x);
        }
        else if (x == 0) {
            if (q.size() == 0) return 1;
            else q.pop();
        }
        else break;
    }
    if (q.size() == 0) printf("empty");
    else {
        while (q.size()) {
            printf("%d ", q.front());
            q.pop();
        }
    }
    return 0;
}