#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 5000)개의 정점으로 이루어진 트리가 주어진다. K(K <= 10^18)번째로 작은 트리의 크기를 구한다.

해결 방법 : 먼저 1번 정점을 루트로 트리를 재배치한다. 그 다음, 트리의 각 정점들마다 해당 정점을 루트로 하는
서브트리의 수를 크기별로 구해주며 다이나믹 프로그래밍을 하면 된다.
트리에 서브트리를 붙일 때 마다 크기별 서브트리의 수는 곱하기와 비슷한 형태로 구해진다.
또한, 이 과정에서 시간 복잡도는 수학적으로 O(N^2)이 되기 때문에 문제 없이 구할 수 있다.

주요 알고리즘 : DP, 트리DP, 수학

출처 : SEUSA 2020 H번 // PacNW 2020 L번 // MidAtl 2020 K번 // SCUSA 2020 H번
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
        //각 자식의 서브트리 수를 확인해가며 해당 정점의 서브트리 수를 계산한다.
        for (int j = 1; j < mem[i].size(); j++) {
            for (int k = j + 1; k < temp.size(); k++) {
                //각 크기별로 값을 구해서 더한다. 중복 계산을 막기 위해 새로운 배열에 저장한다.
                if (temp[k] >= 0) temp[k] += mem[i][j] * mem[x][k - j];
                if (temp[k] > 1000000000000000000) temp[k] = -1; //오버플로를 막기 위해 10^18 이상은 -1로 계산한다.
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
    dfs(1, -1); //트리의 루트를 1로 만든다.
    dp(1); //다이나믹 프로그래밍을 통해 각 지점이 루트인 서브트리를 크기별로 구한다.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mem[j].size() > i && r >= 0) {
                r += mem[j][i];
                if (r > 1000000000000000000 || mem[j][i] < 0) r = -1;
            }
        }
        if (r >= k || r < 0) {
            printf("%d", i); //답이 K 이상이 되는 크기에서 답을 출력한다.
            return 0;
        }
    }
    printf("-1");
    return 0;
}