#include <stdio.h>
#include <deque>
using namespace std;

/*
���� : �� �迭�� �ִ�. S(S <= 100000)���� ���� �� �迭�� ���¸� ����Ѵ�.
A L - ���ʿ� �� ���� �ִ´�.
A R - �����ʿ� �� ���� �ִ´�.
D L X - ���ʿ��� X���� ���� �����Ѵ�.
D R X - �����ʿ��� X���� ���� �����Ѵ�.
���� ���� ������ 1���� ���ʷ� �ö󰣴�.

�ذ� ��� : ���� �̿��ϸ� �ȴ�. A�� push����, D�� pop����(Kȸ �ݺ�)�̴�.

�ֿ� �˰��� : �ڷ� ����, ��

��ó : USACO 2009O S2��
*/

deque<int> dq;

int main(void) {
    int s, x = 1, k;
    char ad, lr;
    scanf("%d", &s);
    for (int i = 0; i < s; i++) {
        scanf(" %c %c", &ad, &lr);
        if (ad == 'A') {
            if (lr == 'L') dq.push_front(x++);
            else dq.push_back(x++);
        }
        else {
            scanf("%d", &k);
            for (int j = 0; j < k; j++) {
                if (lr == 'L') dq.pop_front();
                else dq.pop_back();
            }
        }
    }
    for (int i : dq) {
        printf("%d\n", i);
    }
    return 0;
}