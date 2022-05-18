#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>
#include <queue>

#define byte unsigned char

namespace def_cube {
    const std::vector<int> rw_order = {0, 1, 2, 3, 4, 5, 6, 7, 8, 36, 37, 38, 9, 10, 11, 18, 19, 20, 27, 28, 29, 39, 40, 41, 12, 13, 14, 21, 22, 23, 30, 31, 32, 42, 43, 44, 15, 16, 17, 24, 25, 26, 33, 34, 35, 45, 46, 47, 48, 49, 50, 51, 52, 53};
    class Cube {
    public:
        byte arr[54];
    private:
        void cw_turn(const std::vector<int> &position) {
            int len = (int)position.size();
            for (int i=0; i<len; i += 4) {
                byte t = arr[position[i]];
                arr[position[i]] = arr[position[i+3]];
                arr[position[i+3]] = arr[position[i+2]];
                arr[position[i+2]] = arr[position[i+1]];
                arr[position[i+1]] = t;
            }
        }
        void ccw_turn(const std::vector<int> &position) {
            int len = (int)position.size();
            for (int i=0; i<len; i += 4) {
                byte t = arr[position[i]];
                arr[position[i]] = arr[position[i+1]];
                arr[position[i+1]] = arr[position[i+2]];
                arr[position[i+2]] = arr[position[i+3]];
                arr[position[i+3]] = t;
            }
        }
        void half_turn(const std::vector<int> &position) {
            int len = (int)position.size();
            for (int i=0; i<len; i += 4) {
                std::swap(arr[position[i]], arr[position[i+2]]);
                std::swap(arr[position[i+1]], arr[position[i+3]]);
            }
        }
    public:
        Cube() {
            std::fill(arr, arr + 54, 0);
        }
        void turn_once(int x) {
            int q = x / 3, r = x % 3;
            std::vector<int> il;
            if (q == 0) il = {0, 2, 8, 6, 3, 1, 5, 7, 9, 36, 27, 18, 10, 37, 28, 19, 11, 38, 29, 20};
            else if (q == 1) il = {9, 11, 17, 15, 12, 10, 14, 16, 6, 18, 47, 44, 7, 21, 46, 41, 8, 24, 45, 38};
            else if (q == 2) il = {18, 20, 26, 24, 21, 19, 23, 25, 2, 33, 47, 11, 5, 30, 50, 14, 8, 27, 53, 17};
            else if (q == 3) il = {27, 29, 35, 33, 30, 28, 32, 34, 0, 42, 53, 20, 1, 39, 52, 23, 2, 36, 51, 26};
            else if (q == 4) il = {36, 38, 44, 42, 39, 37, 41, 43, 0, 9, 45, 35, 3, 12, 48, 32, 6, 15, 51, 29};
            else if (q == 5) il = {45, 47, 53, 51, 48, 46, 50, 52, 42, 15, 24, 33, 43, 16, 25, 34, 44, 17, 26, 35};
            if (r == 0) cw_turn(il);
            else if (r == 1) half_turn(il);
            else if (r == 2) ccw_turn(il);
        }
        void read() {
            for (const int &idx: rw_order) {
                int t;
                scanf("%d", &t);
                arr[idx] = (byte)t;
            }
        }
        void pretty_print() const {
            int i = 0;
            printf("      ");
            for (const int &idx: rw_order) {
                printf("%d ", (int)arr[idx]);
                ++i;
                if (i == 3 || i == 6 || i == 45 || i == 48 || i == 51) {
                    printf("\n      ");
                } else if (i == 9 || i == 21 || i == 33) {
                    puts("");
                }
            }
            puts("");
        }
    };
} // namespace def_cube
using Cube = def_cube::Cube;

namespace phase_1 {
    typedef std::pair<int, int> pii;
    unsigned short backprop[2048];
    const std::vector<pii> eleven_edge({
        pii(1, 28), pii(37, 3), pii(19, 5), pii(7, 10),
        pii(41, 12), pii(21, 14), pii(23, 30), pii(39, 32),
        pii(46, 16), pii(43, 48), pii(25, 50)
    });
    int cube_value(const Cube &cube) {
        int r = 0;
        for (const auto &[idx, _]: eleven_edge) {
            r = (r << 1) | !cube.arr[idx];
        }
        return r;
    }
    void precalc() {
        std::queue<int> q;
        q.push(0);
        backprop[0] = -1;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            Cube cube;
            int sum_edge = 0;
            for (int j=0; j<11; ++j) {
                const auto &[now, flipped] = eleven_edge[10 - j];
                int v = (f >> j) & 1;
                cube.arr[v ? flipped : now] = 1;
                sum_edge ^= v;
            }
            cube.arr[sum_edge ? 34 : 52] = 1;
            for (int i=0; i<6; ++i) {
                for (int j=0; j<3; ++j) {
                    cube.turn_once(i * 3);
                    int nv = cube_value(cube);
                    if (!backprop[nv]) {
                        backprop[nv] = ((i * 3 + 3 - j) << 11) | f;
                        q.push(nv);
                    }
                }
                cube.turn_once(i * 3);
            }
        }
    }
    void solve(const Cube &cube, std::vector<int> &result) {
        int r = 0;
        for (const auto &[now, flipped]: eleven_edge) {
            int edge_color = (1 << (cube.arr[flipped])) | (1 << (cube.arr[now]));
            if (cube.arr[flipped] == 3 || cube.arr[flipped] == 5) (r <<= 1) |= 1;
            else if (!(edge_color & 40) && (cube.arr[flipped] == 1 || cube.arr[flipped] == 6)) (r <<= 1) |= 1;
            else r <<= 1;
        }
        while (r > 0) {
            int value = backprop[r];
            result.push_back((value >> 11) - 1);
            r = value & 2047;
        }
    }
} // namespace phase_1

namespace phase_2 {
    typedef std::pair<int, int> pii;
    struct piii {
        int first, second, third;
        piii(): first(0), second(0), third(0) {}
        piii(int first, int second, int third): first(first), second(second), third(third) {}
    };
    const std::vector<int> full_op_list({1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16});

    // corners
    const std::vector<piii> seven_corners({
        piii(18, 8, 11), piii(20, 27, 2), piii(24, 17, 47), piii(26, 53, 33),
        piii(36, 0, 29), piii(38, 9, 6), piii(42, 35, 51)
    });
    unsigned short corner_short[16384], corner_long[2187];
    unsigned short corner_op_table[2187][14];
    int cube_corner_value(const Cube &cube) {
        int r = 0;
        for (const auto &[a, b, c]: seven_corners) {
            (r <<= 2) |= (cube.arr[a] ? 0 : cube.arr[b] ? 1 : 2);
        }
        return r;
    }
    void precalc_corner_op() {
        {
            int c = 0;
            for (int i=0; i<2187;) {
                int f = (c & (c >> 1)) & 0x55555555;
                if ((f &= -f)) {
                    c += f;
                } else {
                    corner_short[c] = i;
                    corner_long[i] = c;
                    ++c;
                    ++i;
                }
            }
        }
        for (int i=0; i<2187; ++i) {
            int f = corner_long[i];
            Cube now_cube;
            int sum_status = 0;
            for (int j=0; j<7; ++j) {
                int status = (f >> (j << 1)) & 3;
                const auto &[a, b, c] = seven_corners[6 - j];
                now_cube.arr[status == 0 ? a : status == 1 ? b : c] = 1;
                sum_status += status;
            }
            sum_status %= 3;
            now_cube.arr[sum_status == 0 ? 44 : sum_status == 1 ? 15 : 45] = 1;
            if (!corner_op_table[i][0]) { // U2
                now_cube.turn_once(1);
                int f = corner_short[cube_corner_value(now_cube)];
                corner_op_table[i][0] = f;
                corner_op_table[f][0] = i;
                now_cube.turn_once(1);
            }
            for (int j=1; j<5; ++j) {
                for (int k=0; k<3; ++k) {
                    now_cube.turn_once(j * 3);
                    int update_op = j * 3 + k - 2;
                    if (!corner_op_table[i][update_op]) {
                        int f = corner_short[cube_corner_value(now_cube)];
                        corner_op_table[i][update_op] = f;
                        corner_op_table[f][j * 3 - k] = i;
                    }
                }
                now_cube.turn_once(j * 3);
            }
            if (!corner_op_table[i][13]) { // D2
                now_cube.turn_once(16);
                int f = corner_short[cube_corner_value(now_cube)];
                corner_op_table[i][13] = f;
                corner_op_table[f][13] = i;
                now_cube.turn_once(16);
            }
        }
    }

    // edges
    const std::vector<pii> twelve_edges({
        pii(37, 3), pii(19, 5), pii(41, 12), pii(21, 14),
        pii(23, 30), pii(39, 32), pii(43, 48), pii(25, 50),
        pii(1, 28), pii(7, 10), pii(46, 16), pii(52, 34)
    });
    unsigned short edge_short[4096], edge_long[495];
    unsigned short edge_op_table[495][14];
    int cube_edge_value(const Cube &cube) {
        int r = 0;
        for (const auto &[idx, _]: twelve_edges) {
            (r <<= 1) |= !!cube.arr[idx];
        }
        return r;
    }
    void precalc_edge_op() {
        int arr[4] = {0, 1, 2, 3};
        for (int i=0; i<495; ++i) {
            int v = (1 << arr[0]) | (1 << arr[1]) | (1 << arr[2]) | (1 << arr[3]);
            edge_short[v] = i;
            edge_long[i] = v;
            if (arr[3] == 11) {
                if (arr[2] == 10) {
                    if (arr[1] == 9) {
                        ++arr[0];
                        arr[1] = arr[0] + 1;
                    } else {
                        ++arr[1];
                    }
                    arr[2] = arr[1] + 1;
                } else {
                    ++arr[2];
                }
                arr[3] = arr[2] + 1;
            } else {
                ++arr[3];
            }
        }
        for (int i=0; i<495; ++i) {
            int f = edge_long[i];
            Cube now_cube;
            for (int j=0; j<12; ++j) {
                const auto &[idx, _] = twelve_edges[11 - j];
                now_cube.arr[idx] = (f >> j) & 1;
            }
            if (!edge_op_table[i][0]) { // U2
                now_cube.turn_once(1);
                int f = edge_short[cube_edge_value(now_cube)];
                edge_op_table[i][0] = f;
                edge_op_table[f][0] = i;
                now_cube.turn_once(1);
            }
            for (int j=1; j<5; ++j) {
                for (int k=0; k<3; ++k) {
                    now_cube.turn_once(j * 3);
                    int update_op = j * 3 + k - 2;
                    if (!edge_op_table[i][update_op]) {
                        int f = edge_short[cube_edge_value(now_cube)];
                        edge_op_table[i][update_op] = f;
                        edge_op_table[f][j * 3 - k] = i;
                    }
                }
                now_cube.turn_once(j * 3);
            }
            if (!edge_op_table[i][13]) { // D2
                now_cube.turn_once(16);
                int f = edge_short[cube_edge_value(now_cube)];
                edge_op_table[i][13] = f;
                edge_op_table[f][13] = i;
                now_cube.turn_once(16);
            }
        }
    }

    // merge
    unsigned int backprop[1'119'744];
    void precalc() {
        precalc_corner_op();
        precalc_edge_op();
        std::queue<int> q;
        q.push(0);
        backprop[0] = -1;
        int op_size = (int)full_op_list.size();
        while (!q.empty()) {
            const int f = q.front();
            q.pop();
            int corner = (f >> 9) & 4095, edge = f & 511;
            for (int i=0; i<op_size; ++i) {
                const int &op = full_op_list[i];
                int nc = corner_op_table[corner][i], ne = edge_op_table[edge][i];
                int v = (nc << 9) | ne;
                if (!backprop[v]) {
                    int qq = op / 3, r = op % 3;
                    backprop[v] = ((qq * 3 + 2 - r) << 21) | f;
                    q.push(v);
                }
            }
        }
    }
    void solve(const Cube &cube, std::vector<int> &result) {
        // corners
        int corner = 0;
        for (const auto &[a, b, c]: seven_corners) {
            if ((1 << cube.arr[a]) & 40) corner <<= 2;
            else if ((1 << cube.arr[b]) & 40) (corner <<= 2) |= 1;
            else if ((1 << cube.arr[c]) & 40) (corner <<= 2) |= 2;
        }
        corner = corner_short[corner];
        // edges
        int edge = 0;
        for (const auto &[a, b]: twelve_edges) {
            int v = (1 << cube.arr[a]) | (1 << cube.arr[b]);
            if (v & 40) edge <<= 1;
            else (edge <<= 1) |= 1;
        }
        edge = edge_short[edge];
        int r = (corner << 9) | edge;
        while (r > 0) {
            int value = backprop[r];
            result.push_back(value >> 21);
            r = value & 2'097'151;
        }
    }
} // namespace phase_2

namespace phase_3 {
    typedef std::pair<int, int> pii;
    using piii = phase_2::piii;
    const std::vector<int> full_op_list({1, 4, 6, 7, 8, 10, 12, 13, 14, 16});

    unsigned short piece_short[256], piece_long[70];
    void precalc_piece() {
        if (piece_long[0] == 15) {
            return;
        }
        int arr[4] = {0, 1, 2, 3};
        for (int i=0; i<70; ++i) {
            int v = (1 << arr[0]) | (1 << arr[1]) | (1 << arr[2]) | (1 << arr[3]);
            piece_short[v] = i;
            piece_long[i] = v;
            if (arr[3] == 7) {
                if (arr[2] == 6) {
                    if (arr[1] == 5) {
                        ++arr[0];
                        arr[1] = arr[0] + 1;
                    } else {
                        ++arr[1];
                    }
                    arr[2] = arr[1] + 1;
                } else {
                    ++arr[2];
                }
                arr[3] = arr[2] + 1;
            } else {
                ++arr[3];
            }
        }
    }
    
    // corners
    const std::vector<piii> eight_corners({
        piii(18, 8, 11), piii(26, 53, 33), piii(36, 0, 29), piii(44, 45, 15),
        piii(20, 27, 2), piii(24, 17, 47), piii(38, 9, 6), piii(42, 35, 51)
    });
    unsigned int perm_long[40320];
    unsigned short perm_short[524288], corner_op_table[40320][10];
    unsigned int idx_from_perm(const std::vector<int> &permutation) {
        int perm_val = 0;
        for (int i=0; i<6; ++i) {
            (perm_val <<= 3) |= permutation[i];
        }
        return (perm_val << 1) | (permutation[6] > permutation[7]);
    }
    void precalc_perm() {
        precalc_piece();
        std::vector<int> permutation({ 0, 1, 2, 3, 4, 5, 6, 7 });
        int c = 0;
        do {
            int perm_val = 0;
            for (int i=0; i<6; ++i) {
                (perm_val <<= 3) |= permutation[i];
            }
            perm_short[(perm_val << 1) | (permutation[6] > permutation[7])] = c;
            perm_long[c] = (perm_val << 6) | (permutation[6] << 3) | permutation[7];
            ++c;
        } while (std::next_permutation(permutation.begin(), permutation.end()));
    }
    int cube_corner_value(const Cube &cube) {
        int r = 0;
        for (int i=0; i<6; ++i) {
            (r <<= 3) |= cube.arr[eight_corners[i].first];
        }
        return (r << 1) | (cube.arr[eight_corners[6].first] > cube.arr[eight_corners[7].first]);
    }
    void precalc_corner_op() {
        precalc_perm();
        for (int i=0; i<40320; ++i) {
            int f = perm_long[i];
            Cube now_cube;
            for (int j=0; j<8; ++j) {
                now_cube.arr[eight_corners[7 - j].first] = (f >> (j * 3)) & 7;
            }
            int op_idx = 0;
            for (int j=0; j<6; ++j) {
                if ((1 << j) & 20) {
                    for (int k=0; k<3; ++k) {
                        now_cube.turn_once(j * 3);
                        if (!corner_op_table[i][op_idx]) {
                            int f = perm_short[cube_corner_value(now_cube)];
                            corner_op_table[i][op_idx] = f;
                            corner_op_table[f][op_idx & 1 ? op_idx : ((op_idx - 2) ^ 2) + 2] = i;
                        }
                        ++op_idx;
                    }
                    now_cube.turn_once(j * 3);
                } else {
                    if (!corner_op_table[i][op_idx]) {
                        now_cube.turn_once(j * 3 + 1);
                        int f = perm_short[cube_corner_value(now_cube)];
                        corner_op_table[i][op_idx] = f;
                        corner_op_table[f][op_idx] = i;
                        now_cube.turn_once(j * 3 + 1);
                    }
                    ++op_idx;
                }
            }
        }
    }

    // edges
    const std::vector<pii> eight_edges({
        pii(41, 12), pii(21, 14), pii(23, 30), pii(39, 32),
        pii(37, 3), pii(19, 5), pii(43, 48), pii(25, 50)
    });
    unsigned short edge_op_table[70][10];
    int cube_edge_value(const Cube &cube) {
        int r = 0;
        for (const auto &[idx, _]: eight_edges) {
            (r <<= 1) |= !!cube.arr[idx];
        }
        return r;
    }
    void precalc_edge_op() {
        precalc_piece();
        for (int i=0; i<70; ++i) {
            int f = piece_long[i];
            Cube now_cube;
            for (int j=0; j<8; ++j) {
                const auto &[idx, _] = eight_edges[7 - j];
                now_cube.arr[idx] = (f >> j) & 1;
            }
            int op_idx = 0;
            for (int j=0; j<6; ++j) {
                if ((1 << j) & 20) {
                    for (int k=0; k<3; ++k) {
                        now_cube.turn_once(j * 3);
                        if (!edge_op_table[i][op_idx]) {
                            int f = piece_short[cube_edge_value(now_cube)];
                            edge_op_table[i][op_idx] = f;
                            edge_op_table[f][op_idx & 1 ? op_idx : ((op_idx - 2) ^ 2) + 2] = i;
                        }
                        ++op_idx;
                    }
                    now_cube.turn_once(j * 3);
                } else {
                    if (!edge_op_table[i][op_idx]) {
                        now_cube.turn_once(j * 3 + 1);
                        int f = piece_short[cube_edge_value(now_cube)];
                        edge_op_table[i][op_idx] = f;
                        edge_op_table[f][op_idx] = i;
                        now_cube.turn_once(j * 3 + 1);
                    }
                    ++op_idx;
                }
            }
        }
    }

    // merge
    unsigned int backprop[2'822'400];
    void precalc() {
        precalc_corner_op();
        precalc_edge_op();
        std::queue<int> q;
        {
            std::vector<bool> init_check(40320);
            std::queue<int> q0;
            q0.push(0);
            q.push(0);
            backprop[0] = -1;
            init_check[0] = true;
            while (!q0.empty()) {
                int f = q0.front();
                q0.pop();
                std::vector<int> perm;
                {
                    int x = perm_long[f];
                    for (int i=0; i<8; ++i) {
                        perm.push_back(x & 7);
                        x >>= 3;
                    }
                    std::reverse(perm.begin(), perm.end());
                }
                for (const auto &[f, s]: {
                    make_pair(pii(0, 1), pii(4, 5)),
                    make_pair(pii(1, 2), pii(5, 6)),
                    make_pair(pii(2, 3), pii(6, 7)),
                    make_pair(pii(2, 3), pii(4, 5)),
                }) {
                    std::swap(perm[f.first], perm[f.second]);
                    std::swap(perm[s.first], perm[s.second]);
                    int nf = perm_short[idx_from_perm(perm)];
                    if (!init_check[nf]) {
                        q0.push(nf);
                        q.push(nf * 70);
                        backprop[nf * 70] = -1;
                        init_check[nf] = true;
                    }
                    std::swap(perm[f.first], perm[f.second]);
                    std::swap(perm[s.first], perm[s.second]);
                }
            }
        }
        int op_size = (int)full_op_list.size();
        while (!q.empty()) {
            const int f = q.front();
            q.pop();
            int corner = f / 70, edge = f % 70;
            for (int i=0; i<op_size; ++i) {
                const int &op = full_op_list[i];
                int nc = corner_op_table[corner][i], ne = edge_op_table[edge][i];
                int v = nc * 70 + ne;
                if (!backprop[v]) {
                    int qq = op / 3, r = op % 3;
                    backprop[v] = ((qq * 3 + 2 - r) << 22) | f;
                    q.push(v);
                }
            }
        }
    }
    void solve(const Cube &cube, std::vector<int> &result) {
        // corners
        int corner = 0;
        std::vector<int> corner_order;
        for (const auto &[a, b, c]: eight_corners) {
            int corner_color = (1 << cube.arr[a]) | (1 << cube.arr[b]) | (1 << cube.arr[c]);
            int r = 0;
            if (corner_color & 64) {
                r |= 1;
            }
            if (corner_color & 32) {
                r |= 2;
            }
            if (((corner_color >> 4) & 1) != (__builtin_popcount(r) & 1)) {
                r |= 4;
            }
            corner_order.push_back(r);
        }
        corner = perm_short[idx_from_perm(corner_order)];
        // edges
        int edge = 0;
        for (const auto &[a, b]: eight_edges) {
            int v = (1 << cube.arr[a]) | (1 << cube.arr[b]);
            if (v & 20) edge <<= 1;
            else (edge <<= 1) |= 1;
        }
        edge = piece_short[edge];
        int r = corner * 70 + edge;
        while (~backprop[r]) {
            int value = backprop[r];
            result.push_back(value >> 22);
            r = value & 4'194'303;
        }
    }
} // namespace phase_3

namespace phase_4 {
    typedef std::pair<int, int> pii;
    using piii = phase_2::piii;

    const std::vector<piii> eight_corners({
        piii(18, 8, 11), piii(26, 53, 33), piii(36, 0, 29), piii(44, 45, 15),
        piii(20, 27, 2), piii(24, 17, 47), piii(38, 9, 6), piii(42, 35, 51)
    });
    byte perm_short[256], perm_long[24];
    void precalc_perm() {
        if (perm_long[0] == 27) {
            return;
        }
        std::vector<int> perm({ 0, 1, 2, 3 });
        int c = 0;
        do {
            int r = 0;
            for (const int &x: perm) {
                (r <<= 2) |= x;
            }
            perm_short[r] = c;
            perm_long[c] = r;
            ++c;
        } while (std::next_permutation(perm.begin(), perm.end()));
    }

    // corner
    byte corner_op_table[96][6];
    unsigned short corner_long[96];
    void precalc_corner_op() {
        precalc_perm();

        std::queue<int> q;
        q.push(0);
        corner_long[0] = 6939;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            Cube now_cube;
            for (int i=0; i<8; ++i) {
                now_cube.arr[eight_corners[7 - i].first] = (corner_long[f] >> (i << 1)) & 3;
            }
            for (int i=0; i<6; ++i) {
                if (!corner_op_table[f][i]) {
                    now_cube.turn_once(i * 3 + 1);
                    int long_p = 0;
                    for (const auto &[pos, _, __]: eight_corners) {
                        (long_p <<= 2) |= now_cube.arr[pos];
                    }
                    int short_p = (perm_short[long_p >> 8] << 2) | ((long_p >> 6) & 3);
                    if (!corner_long[short_p]) {
                        corner_long[short_p] = long_p;
                        q.push(short_p);
                    }
                    corner_op_table[f][i] = short_p;
                    corner_op_table[short_p][i] = f;
                    now_cube.turn_once(i * 3 + 1);
                }
            }
        }
    }

    // edge
    const std::vector<pii> twelve_edges({
        pii(1, 28), pii(7, 10), pii(46, 16), pii(52, 34),
        pii(21, 14), pii(23, 30), pii(39, 32), pii(41, 12),
        pii(19, 5), pii(25, 50), pii(43, 48), pii(37, 3)
    });
    unsigned short edge_op_table[6912][6];
    void precalc_edge_op() {
        precalc_perm();
        unsigned int *edge_long = new unsigned int[6912];
        std::fill(edge_long, edge_long + 6912, 0U);

        std::queue<int> q;
        q.push(0);
        edge_long[0] = 1776411;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            Cube now_cube;
            for (int i=0; i<12; ++i) {
                now_cube.arr[twelve_edges[11 - i].first] = (edge_long[f] >> (i << 1)) & 3;
            }
            for (int i=0; i<6; ++i) {
                if (!edge_op_table[f][i]) {
                    now_cube.turn_once(i * 3 + 1);
                    int long_p = 0, long_long_p = 0;
                    for (int j=0; j<3; ++j) {
                        int r = 0;
                        for (int k=0; k<4; ++k) {
                            int idx = (j << 2) | k;
                            (r <<= 2) |= now_cube.arr[twelve_edges[idx].first];
                        }
                        (long_long_p <<= 8) |= r;
                        (long_p *= 24) += perm_short[r];
                    }
                    const int nf = long_p >> 1;
                    if (!edge_long[nf]) {
                        edge_long[nf] = long_long_p;
                        q.push(nf);
                    }
                    edge_op_table[f][i] = nf;
                    edge_op_table[nf][i] = f;
                    now_cube.turn_once(i * 3 + 1);
                }
            }
        }
    }

    // merge
    byte color[64];
    int backprop[663552];
    void precalc() {
        precalc_corner_op();
        precalc_edge_op();
        {
            int i = 0;
            for (const auto &[a, b, c]: eight_corners) {
                int v = (1 << (a / 9)) | (1 << (b / 9)) | (1 << (c / 9));
                color[v] = i & 3;
                ++i;
            }
            for (const auto &[a, b]: twelve_edges) {
                int v = (1 << (a / 9)) | (1 << (b / 9));
                color[v] = i & 3;
                ++i;
            }
        }
        std::queue<int> q;
        backprop[0] = -1;
        q.push(0);
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            int edge = f / 96U, corner = f % 96U;
            for (int i=0; i<6; ++i) {
                int ne = edge_op_table[edge][i], nc = corner_op_table[corner][i];
                int nf = ne * 96 + nc;
                if (!backprop[nf]) {
                    backprop[nf] = ((i + 1) << 20) | f;
                    q.push(nf);
                }
            }
        }
    }

    void solve(const Cube &cube, std::vector<int> &result) {
        // corners
        int corner = 0;
        std::vector<int> corner_order;
        for (const auto &[a, b, c]: eight_corners) {
            (corner <<= 2) |= color[((1 << cube.arr[a]) | (1 << cube.arr[b]) | (1 << cube.arr[c])) >> 1];
        }
        corner = (perm_short[corner >> 8] << 2) | ((corner >> 6) & 3);
        // edges
        int edge = 0;
        for (int i=0; i<3; ++i) {
            int r = 0;
            for (int j=0; j<4; ++j) {
                const auto &[a, b] = twelve_edges[(i << 2) | j];
                (r <<= 2) |= color[((1 << cube.arr[a]) | (1 << cube.arr[b])) >> 1];
            }
            (edge *= 24) += perm_short[r];
        }
        edge >>= 1;
        int r = edge * 96 + corner;
        while (~backprop[r]) {
            int value = backprop[r];
            result.push_back((value >> 20) * 3 - 2);
            r = value & 1'048'575;
        }
    }
} // namespace phase_4

int main() {
    Cube cube;
    phase_1::precalc();
    phase_2::precalc();
    phase_3::precalc();
    phase_4::precalc();
    int T;
    scanf("%d", &T);
    while (T--) {
        cube.read();
        std::vector<int> result, result2;
        phase_1::solve(cube, result);
        for (const int &op: result) {
            cube.turn_once(op);
        }
        phase_2::solve(cube, result2);
        for (const int &op: result2) {
            cube.turn_once(op);
            result.push_back(op);
        }
        result2.clear();
        phase_3::solve(cube, result2);
        for (const int &op: result2) {
            cube.turn_once(op);
            result.push_back(op);
        }
        result2.clear();
        phase_4::solve(cube, result2);
        for (const int &op: result2) {
            cube.turn_once(op);
            result.push_back(op);
        }
        result2.clear();
        for (const int &op: result) {
            if (op == -1) printf("/ ");
            else {
                putchar("UFRBLD"[op / 3]);
                if (int r; (r = op % 3)) putchar(" 2'"[r]);
                putchar(' ');
            }
        }
        puts("");
        result.clear();
    }
    return 0;
}