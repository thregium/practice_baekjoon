#include <stdio.h>
#include <set>
#include <map>
using namespace std;

/*
���� : H * W(H, W <= 10^9) ũ���� �迭�� ���� �� �ȼ��� N(N <= 100000)�� �ִ�. �̶�, 3 * 3 ũ���� ������ ���� ��
�ȼ��� i(i <= 9)���� ������ ������ ���� ���Ѵ�.

�ذ� ��� : H�� W�� ���� N�� �۱� ������ H�� W�� ũ�ٸ� ��κ��� ���� �ȼ��� 0���� ���� �� �� �ִ�.
�̸� �̿��ؼ�, ���� �ȼ� �ֺ� �����鸸 ���� Ȯ���ϵ��� �Ѵ�. �� �ȼ��� �˴ٸ� �׿� ������ �޴� 3 * 3 ������
���� 3 * 3ĭ�� �߽����� �� ĭ���̴�. �� ĭ�� ��� ������ ����ų� �̹� Ȯ���� ������ �����ϰ�
�ٽ� �ش� ĭ�� �߽����� 3 * 3 ĭ�� ���� Ȯ���Ѵ�. �̴� ���� ���� ���� Ȯ���� �� �ִ�.
�̸� ���� Ȯ���� 3 * 3 ������ ���� �� �ȼ��� ���� Ȯ���ϰ� �ʿ� �� ���� ��ǥ�� �Բ� �����Ѵ�.
�̸� ���� �ߺ� �湮�� ������ �� �ְ� �ȼ��� ���� ���� Ȯ���� ����������.
��� �ȼ��� ���� �̸� ������ �ʿ� �ִ� ĭ���� ���� �ͼ� ���� ���� �� �ȼ��� ������ ���� �׷��� ������ ������ �� �ش�.
�� ���� ����((H - 2) * (W - 2))�� ���� 0���� �θ� �ȴ�.

�ֿ� �˰��� : �ڷᱸ��, ��, ��
*/

int pos[103000][2];
long long res[16];
int dxy[9][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {0, 0} };
set<pair<int, int>> black;
map<pair<int, int>, int> cnt;

int isvalid(int h, int w, int x, int y) {
    if (x <= 1 || y <= 1 || x >= h || y >= w) return 0;
    else return 1;
}

int main(void) {
    int h, w, n, c;
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
        black.insert(pair<int, int>(pos[i][0], pos[i][1]));
    }
    int fx, fy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            fx = pos[i][0] + dxy[j][0];
            fy = pos[i][1] + dxy[j][1];
            if (!isvalid(h, w, fx, fy)) continue;
            if (cnt.find(pair<int, int>(fx, fy)) != cnt.end()) continue;
            c = 0;
            for (int k = 0; k < 9; k++) {
                fx = pos[i][0] + dxy[j][0] + dxy[k][0];
                fy = pos[i][1] + dxy[j][1] + dxy[k][1];
                if (black.find(pair<int, int>(fx, fy)) != black.end()) c++;
            }
            cnt.insert(pair<pair<int, int>, int>(pair<int, int>(fx, fy), c));
        }
    }

    res[0] = ((long long)h - 2) * (w - 2);
    for (auto i : cnt) {
        res[i.second]++;
        res[0]--;
    }
    for (int i = 0; i <= 9; i++) {
        printf("%lld\n", res[i]);
    }
    return 0;
}