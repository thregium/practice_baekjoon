#include <stdio.h>
#include <queue>
#include <unordered_set>
using namespace std;

/*
���� : 6�ڸ� ������ �ڿ��� N�� 10 ������ �ڿ��� K�� �־��� ��, N�� �ڸ��� Kȸ �ٲپ� ���� �� �ִ� �ڿ��� ���
���� ū ���� ����. ��, �߰� �������� 0�� �� �տ� ���� ��찡 ������ �� �ȴ�.
�ٲ� �� ���ٸ� -1�� ����ϸ� �ȴ�.

�ذ� ��� : BFS�� �ϵ�, ���� ���� ������ ���� �����ϴٷ� �� �ڿ����� �ٲ� Ƚ���� ���� �湮 ���θ� �ٸ��� �����Ѵ�.
ó�� N���� �Ÿ��� K�� �� �� ���� �̸� �ݺ��ϰ�, �Ÿ��� K�� �� ��� ���� ū ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, �ؽü�

��ó : SRM 437 D1A/D2B
*/

int tmp[16];
queue<int> q; //ť�� �¿��� N * 100 + K�� ���� �����Ѵ�.
unordered_set<int> us;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int bfs(int n, int k) {
    int d = 0, dist, res = -1;
    q.push(n * 100);
    us.insert(n * 100);
    while (n) {
        d++; //�̸� �ڸ����� ���Ѵ�.
        n /= 10;
    }
    while (q.size()) {
        n = q.front();
        q.pop();
        dist = n % 100;
        n /= 100;
        if (dist > k) continue;
        else if (dist == k) {
            if (n > res) res = n; //Kȸ �ٲ� �� ��� ���� ū ���� ���Ѵ�.
        }
        for (int i = 0; i < d; i++) {
            tmp[d - i - 1] = n % 10; //�� �ڸ����� ������.
            n /= 10;
        }
        for (int i = 0; i < d; i++) {
            for (int j = i + 1; j < d; j++) {
                //�ش� �ڸ����� ��� ��ȯ�� �߰��Ѵ�.
                swap(&tmp[i], &tmp[j]);
                if (tmp[0] == 0) {
                    swap(&tmp[i], &tmp[j]);
                    continue;
                }
                n = 0;
                for (int i = 0; i < d; i++) {
                    n *= 10;
                    n += tmp[i];
                }
                if (us.find(n * 100 + dist + 1) == us.end()) {
                    //�̹� �湮���� ���� ��� �ٽ� �湮�Ѵ�.
                    us.insert(n * 100 + dist + 1);
                    q.push(n * 100 + dist + 1);
                }
                swap(&tmp[i], &tmp[j]);
            }
        }
    }
    return res;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", bfs(n, k));
    return 0;
}