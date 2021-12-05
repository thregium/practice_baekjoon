#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 5000)���� �������� �̷���� Ʈ���� �־�����. K(K <= 10^18)��°�� ���� Ʈ���� ũ�⸦ ���Ѵ�.

�ذ� ��� : ���� 1�� ������ ��Ʈ�� Ʈ���� ���ġ�Ѵ�. �� ����, Ʈ���� �� �����鸶�� �ش� ������ ��Ʈ�� �ϴ�
����Ʈ���� ���� ũ�⺰�� �����ָ� ���̳��� ���α׷����� �ϸ� �ȴ�.
Ʈ���� ����Ʈ���� ���� �� ���� ũ�⺰ ����Ʈ���� ���� ���ϱ�� ����� ���·� ��������.
����, �� �������� �ð� ���⵵�� ���������� O(N^2)�� �Ǳ� ������ ���� ���� ���� �� �ִ�.

�ֿ� �˰��� : DP, Ʈ��DP, ����

��ó : SEUSA 2020 H�� // PacNW 2020 L�� // MidAtl 2020 K�� // SCUSA 2020 H��
*/

vector<long long> mem[5120];
vector<int> ed[5120], child[5120];

void dfs(int x, int p) {
    for (int i : ed[x]) {
        if (i == p) continue;
        child[x].push_back(i);
        dfs(i, x);
    }
}

void dp(int x) {
    vector<long long> temp;
    temp.push_back(0);
    temp.push_back(1);
    mem[x].push_back(0);
    mem[x].push_back(1);
    for (int i : child[x]) {
        dp(i);
    }
    for (int i : child[x]) {
        //�� �ڽ��� ����Ʈ�� ���� Ȯ���ذ��� �ش� ������ ����Ʈ�� ���� ����Ѵ�.
        for (int j = 1; j < mem[i].size(); j++) {
            for (int k = j + 1; k < temp.size(); k++) {
                //�� ũ�⺰�� ���� ���ؼ� ���Ѵ�. �ߺ� ����� ���� ���� ���ο� �迭�� �����Ѵ�.
                if (temp[k] >= 0) temp[k] += mem[i][j] * mem[x][k - j];
                if (temp[k] > 1000000000000000000) temp[k] = -1; //�����÷θ� ���� ���� 10^18 �̻��� -1�� ����Ѵ�.
            }
            temp.push_back(mem[i][j] * mem[x][mem[x].size() - 1]);
        }
        for (int i = 0; i < temp.size(); i++) {
            if (i >= mem[x].size()) mem[x].push_back(temp[i]);
            else mem[x][i] = temp[i];
        }
    }    
}

int main(void) {
    int n, a, b;
    long long k, r = 0;
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2020\\kthsubtree\\data\\secret\\6002.in", "r", stdin);
    scanf("%d %lld", &n, &k);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    dfs(1, -1); //Ʈ���� ��Ʈ�� 1�� �����.
    dp(1); //���̳��� ���α׷����� ���� �� ������ ��Ʈ�� ����Ʈ���� ũ�⺰�� ���Ѵ�.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mem[j].size() > i && r >= 0) {
                r += mem[j][i];
                if (r > 1000000000000000000 || mem[j][i] < 0) r = -1;
            }
        }
        if (r >= k || r < 0) {
            printf("%d", i); //���� K �̻��� �Ǵ� ũ�⿡�� ���� ����Ѵ�.
            return 0;
        }
    }
    printf("-1");
    return 0;
}