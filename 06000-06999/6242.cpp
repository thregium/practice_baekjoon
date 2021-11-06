#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

/*
���� : ��ǥ���� N(N <= 40000)���� ���簢���� �־�����. �� ���簢���� X���� �� ������ �ϰ� �ִ�.
�̶�, �� ���簢���� ����(<= 10^9)�� X��ǥ�� ����, ��(<= 10^9)�� �־����� ���簢���� �������� ���̸� ���Ѵ�.

�ذ� ��� : �� ���簢���� �������� �������� X���� ��ǥ�� �������� �����Ѵ�. �� �� �� ������ ���ʷ� ���캸�鼭
�������� ������ ������ ��Ͽ� �ش� ���� �߰��ϰ�, ������ ������ �ش� ���� �����Ѵ�.
�̶�, �Ź� �̸� �����ϱ� �� ���� ������ X�� ���̸� Ȯ���ϰ� ���� ���� ������ �� * ���� ������ ���̸�ŭ��
�ᱣ���� ���س�����. �̰��� �� �������� ���� ���� ���簢���� ������ ���̰�, ���� �� ��ŭ�� ���̰� �߰��ȴ�.
�̸� �ݺ��� ���� �ᱣ���� ���� �ȴ�.

�ֿ� �˰��� : �ڷᱸ��, ��, ������

��ó : USACO 2007O S1��
*/

int vert[103000][3];
map<int, int> mp;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &vert[i * 2][0], &vert[i * 2 + 1][0], &vert[i * 2][1]);
        vert[i * 2 + 1][1] = vert[i * 2][1];
        vert[i * 2 + 1][2] = 1;
    }
    qsort(vert, n * 2, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n * 2; i++) {
        if (i > 0 && mp.size()) {
            r += (long long)(vert[i][0] - vert[i - 1][0]) * (--mp.end())->first;
        }
        if (vert[i][2]) {
            if (mp.empty()) return 1;
            if (mp.find(vert[i][1]) != mp.end()) {
                (mp.find(vert[i][1])->second)--;
                if (mp.find(vert[i][1])->second == 0) mp.erase(vert[i][1]);
            }
            else return 1;
        }
        else {
            if (mp.find(vert[i][1]) != mp.end()) {
                (mp.find(vert[i][1])->second)++;
            }
            else mp.insert(pair<int, int>(vert[i][1], 1));
        }
    }
    printf("%lld", r);
    return 0;
}