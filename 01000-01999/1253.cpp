#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

/*
���� : N(N <= 2000)���� ����(|| <= 10^9)�� �־��� ��, �� ������ ��� �ش� ������ �ٸ� �� ������ ���� ������
������ ���Ѵ�. ���� ���̴��� �ٸ� ��ġ�� �ִٸ� �ٸ� �����̴�.

�ذ� ��� : ��� ������ ���� Ű������ �Ͽ� �ؽøʿ� �����Ѵ�. �׸���, ���� �ٸ� ������ ���� �ش� ���� ��� ���տ� ����
�������� ��ȣ�� �����Ѵ�. �̹� �ִ� ���� Ȯ���Ѵٸ� ���� �ִ� ������ ������ ���ο� ���տ� ���� �ʴ�
�������� ��ȣ���� �� ������.
�̸� �ݺ��� ��, �� ������ ���� �ؽøʿ��� ���� ã�´�. �ؽøʿ� �ִٸ� ���Ϳ� �ִ� ��ȣ���� Ȯ���ϰ�
�װ͵� �ƴ� ��� ������ �����ϹǷ� �ᱣ���� 1 �ø���. �̸� �ݺ��� ��� ���� ã���� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �ؽø�
*/

int a[2048];
unordered_map<int, vector<int>> mp;

int main(void) {
    int n, r = 0, t;
    std::unordered_map<int, vector<int>>::iterator it;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mp.find(a[i] + a[j]) == mp.end()) {
                mp.insert(pair<int, vector<int>>(a[i] + a[j], { i, j }));
            }
            else {
                it = mp.find(a[i] + a[j]);
                vector<int> v;
                for (int x : it->second) {
                    if (x == i || x == j) v.push_back(x);
                }
                it->second = v;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (mp.find(a[i]) != mp.end()) {
            it = mp.find(a[i]);
            t = 1;
            for (auto j : it->second) {
                if (j == i) t = 0;
            }
            r += t;
        }
    }
    printf("%d", r);
    return 0;
}