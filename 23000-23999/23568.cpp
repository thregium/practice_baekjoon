#include <stdio.h>
#include <unordered_map>
using namespace std;

/*
���� : ���������� N(N <= 10000)���� ���� �ٸ� ��ġ������ �̵� ����� �Ÿ�(<= 2 * 10^6)�� �־��� ��,
������(|| <= 10^6)���� �̵� ������ ��� ��� �̵��Ͽ� �����ϴ� ������ ���Ѵ�.
�־��� ��� �̵��� 1���� ���δ�.

�ذ� ��� : �� ��ġ������ �̵� ������ �ؽøʿ� ���� ���� Nȸ �̵��ϰ� �� ��ġ�� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �ؽø�, �ùķ��̼�

��ó : Seoul 2021 C��
*/

unordered_map<int, int> mv;

int main(void) {
    int n, pos, diff;
    char dir;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c %d", &pos, &dir, &diff);
        if (dir == 'L') mv.insert({ pos, -diff });
        else if (dir == 'R') mv.insert({ pos, diff });
        else return 1;
    }
    scanf("%d", &pos);
    for (int i = 0; i < n; i++) {
        pos += mv[pos];
    }
    printf("%d", pos);
    return 0;
}