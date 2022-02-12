#include <stdio.h>
#include <map>
using namespace std;

/*
���� : H * W(H, W <= 10^9) ũ���� ĭ�� �ְ�, ���� N���� �� ������ ĭ�� ��� ���� �ִ�.
�� ���Ⱑ �ִ� ĭ�� �־�����, �� ĭ�� ��� 3 * 3 �������� ���Ⱑ ���� ���� ���� ���� ������ ���Ѵ�.
����� ���� ĭ�� ���� �� ���� �� �ִ�.

�ذ� ��� : ���� �ʿ� ���Ⱑ �ִ� ĭ�� ���� ������ ������ �����Ѵ�. 
�׸��� �� ���Ⱑ �ִ� ĭ���� �� �ֺ� 3 * 3 ������ ���� �ش� ĭ�� �߽����� �Ͽ� ���� ������ �� ����,
�� �� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ��

��ó : JOIG 2022 4��
*/

int pos[65536][2];
map<pair<int, int>, int> m;

int main(void) {
    int h, w, n, x, y, c, r = 0;
    scanf("%d %d%d", &h, &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
        if (m.find(make_pair(pos[i][0], pos[i][1])) == m.end()) {
            m.insert(make_pair(make_pair(pos[i][0], pos[i][1]), 1));
        }
        else m[make_pair(pos[i][0], pos[i][1])]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                x = pos[i][0] + j, y = pos[i][1] + k;
                if (x + j < 1 || y + k < 1 || x + j > h || y + k > w) continue;
                c = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (m.find(make_pair(x + dx, y + dy)) != m.end()) {
                            c += m[make_pair(x + dx, y + dy)];
                        }
                    }
                }
                if (c > r) r = c;
            }
        }
    }
    printf("%d", r);
    return 0;
}