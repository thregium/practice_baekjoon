#include <stdio.h>
#include <time.h>
#include <map>
#include <set>
using namespace std;

/*
���� : N(N <= 200000)���� 1���� K(K <= N)������ �ڿ����� �̷���� ������ �־�����. �̶�, �� ������ �κм��� ���
1���� K���� ��� �ڿ����� ����ְ� ���������� ���� ���� �κ� ������ ���Ѵ�.
�־����� �������� 1���� K������ ��� �ڿ����� ��� �ִ�.

�ذ� ��� : �ڿ������� ������ Ȯ���ϸ� �� ���� ó�� ������ ������ ������ ������ �д�.
�� ���� �������� ������ ������ ��(�Ǵ� �׿� ���� ��)�� ������ ������������ ���� ���� ������ �̴� ���� �̵����� �� �� �ִ�.
���� ���� �� ���� ���� �̰�, �� ���� �� ��� ���� ���� ��, ... �� �ݺ��� ������.
������ ���� ������ ���� �������� ���ư���. �̶�, �ش� ������ ������ ���� �̹� �����ٸ� ���� �������� ���캸�ƾ� �Ѵ�.
�̸� �ݺ��ϸ� ���� ���� �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���, �ڷ� ����, ��, ��

��ó : PacNW 2019 B��
*/

char chk[204800];
int a[204800];
map<int, int> lower; //�ش� ���� ������ ����� �� ���� ����
map<int, set<int>> upper; //�ش� ���������� ���� ��� ���� ���� ���� ���� �� ���� �ִ� ��ġ��

int main(void) {
    int n, k, p = -1, last = -1;
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2019\\perfectflush\\data\\secret\\PerfectFlush-1005.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2019\\perfectflush\\data\\secret\\PerfectFlush-1005_t.out", "w", stdout);
    scanf("%d %d", &n, &k);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        //a[i] = rand() % k + 1;
        //printf("%d ", a[i]);
    }
    //printf("\n");
    for (int i = n - 1; i >= 0; i--) {
        //�ڿ������� ������ ���캻��. ��� ���� �� ���� ���� �� ���� ���� ������ ���� �¿� �߰��Ѵ�.
        if (lower.find(a[i]) == lower.end()) lower.insert(pair<int, int>(a[i], 1));
        else lower[a[i]]++;
        if (lower.size() == k) {
            lower.erase(a[i]);
            last = i;
            break;
        }
    }
    for (int i = 0; i <= last; i++) {
        //�ڿ������� ���� �� ��� ���� ������ �������� �տ������� ������ �߰��Ѵ�.
        if (upper.find(a[i]) == upper.end()) upper.insert(pair<int, set<int>>(a[i], set<int>{i}));
        else upper[a[i]].insert(i);
    }
    p = *(upper.begin()->second.begin());
    for (int i = k - 1; i >= 0; i--) {
        //��� ���� ã�� �� ���� ���� �������� ���� �� ������ �� ��� ���� ���� ���� ã�� ���� �ݺ��Ѵ�.
        printf("%d", a[p]);
        chk[a[p]] = 1;
        if (i == 0) break;
        else printf(" ");

        while (chk[a[last]] || a[p] == a[last]) {
            //������ ���� ã�� ��� ���� ������ ���캻��.
            for (int j = last + 1; j < n; j++) {
                if (!chk[a[j]]) {
                    if (upper.find(a[j]) == upper.end()) upper.insert(pair<int, set<int>>(a[j], set<int>{j}));
                    else upper[a[j]].insert(j);
                }
                if (lower[a[j]] == 1) {
                    lower.erase(a[j]);
                    last = j;
                    break;
                }
                else lower[a[j]]--;
            }
        }
        while (*(upper.begin()->second.begin()) <= p || chk[upper.begin()->first]) {
            //���� �� ������ �� ��� ���� ���� ���� ã�´�.
            upper.begin()->second.erase(upper.begin()->second.begin());
            if (upper.begin()->second.empty()) upper.erase(upper.begin());
            if (upper.empty()) break;
        }
        p = *(upper.begin()->second.begin());
    }
    printf("\n");
    return 0;
}