// Oracle and hell-test generator for "Provinces of Ardenia".
// Correct answer: partition V into exactly K nonempty subsets, each inducing a
// connected subgraph, minimizing the sum of weights of edges internal to subsets.
// Feasible iff (number of connected components) <= K <= n.
#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

static const long long INF = (1LL << 62);

struct Inst {
    int n = 0, k = 0;
    vector<tuple<int, int, int>> e;  // 1-indexed u, v, w
};

static int m_of(const Inst& g) { return (int)g.e.size(); }

struct Oracle {
    int n, k;
    vector<int> adj;          // bitset
    vector<long long> cost;   // -1 = disconnected, else induced weight
    vector<long long> dp;     // [used][mask]
    vector<long long> memo;   // [left][mask], -2 unknown
    int full;

    explicit Oracle(const Inst& g) {
        n = g.n;
        k = g.k;
        full = (1 << n) - 1;
        adj.assign(n, 0);
        vector<tuple<int, int, int>> el;
        for (auto [u, v, w] : g.e) {
            --u;
            --v;
            adj[u] |= 1 << v;
            adj[v] |= 1 << u;
            el.emplace_back(u, v, w);
        }
        cost.assign(1 << n, -1);
        for (int mask = 1; mask <= full; ++mask) {
            int start = __builtin_ctz(mask);
            int seen = 1 << start;
            int st[12], sp = 0;
            st[sp++] = start;
            while (sp) {
                int x = st[--sp];
                int nbr = adj[x] & mask;
                while (nbr) {
                    int b = __builtin_ctz(nbr);
                    nbr &= nbr - 1;
                    int bit = 1 << b;
                    if (seen & bit) continue;
                    seen |= bit;
                    st[sp++] = b;
                }
            }
            if (seen != mask) continue;
            long long s = 0;
            for (auto [u, v, w] : el) {
                if ((mask >> u & 1) && (mask >> v & 1)) s += w;
            }
            cost[mask] = s;
        }

        dp.assign((k + 1) * (1 << n), INF);
        auto at = [&](int used, int mask) -> long long& {
            return dp[used * (1 << n) + mask];
        };
        at(0, 0) = 0;
        for (int used = 0; used < k; ++used) {
            for (int mask = 0; mask <= full; ++mask) {
                long long cur = at(used, mask);
                if (cur >= INF) continue;
                int rest = full ^ mask;
                for (int sub = rest; sub; sub = (sub - 1) & rest) {
                    if (cost[sub] < 0) continue;
                    long long nxt = cur + cost[sub];
                    long long& cell = at(used + 1, mask | sub);
                    if (nxt < cell) cell = nxt;
                }
            }
        }
    }

    long long solve_dp() const {
        long long ans = dp[k * (1 << n) + full];
        return ans >= INF ? -1 : ans;
    }

    long long dfs(int mask, int left) {
        if (left == 0) return mask == 0 ? 0 : INF;
        if (mask == 0) return INF;
        long long& mem = memo[left * (1 << n) + mask];
        if (mem != -2) return mem;
        int low = __builtin_ctz(mask);
        int rest = mask ^ (1 << low);
        long long best = INF;
        for (int sub = rest;; sub = (sub - 1) & rest) {
            int prov = sub | (1 << low);
            if (cost[prov] >= 0) {
                long long t = dfs(mask ^ prov, left - 1);
                if (t < INF && cost[prov] + t < best) best = cost[prov] + t;
            }
            if (sub == 0) break;
        }
        return mem = best;
    }

    long long solve_dfs() {
        memo.assign((k + 1) * (1 << n), -2);
        long long ans = dfs(full, k);
        return ans >= INF ? -1 : ans;
    }
};

static long long solve(const Inst& g) {
    Oracle o(g);
    long long a = o.solve_dp();
    long long b = o.solve_dfs();
    if (a != b) {
        cerr << "DP/DFS mismatch " << a << " vs " << b << "\n";
        exit(1);
    }
    return a;
}

// User's algorithm: Kruskal, add light edges, sum ONLY accepted tree edges,
// stop when component count hits K. Never returns -1.
static long long kruskal_A(const Inst& g) {
    int n = g.n;
    vector<int> fa(n + 1), rk(n + 1, 1);
    iota(fa.begin(), fa.end(), 0);
    auto fd = [&](auto&& self, int x) -> int {
        if (fa[x] == x) return x;
        return fa[x] = self(self, fa[x]);
    };
    auto un = [&](int a, int b) {
        a = fd(fd, a);
        b = fd(fd, b);
        if (a == b) return false;
        if (rk[a] > rk[b]) {
            fa[b] = a;
            rk[a] += rk[b];
        } else {
            fa[a] = b;
            rk[b] += rk[a];
        }
        return true;
    };
    auto edges = g.e;
    sort(edges.begin(), edges.end(), [](auto& x, auto& y) {
        return get<2>(x) < get<2>(y);
    });
    int tree_cnt = n;
    long long res = 0;
    for (auto [u, v, w] : edges) {
        if (un(u, v)) {
            --tree_cnt;
            res += w;
            if (tree_cnt == g.k) break;
        }
    }
    return res;
}

// Smarter wrong answer: if K < CC, -1; else take the K-component MSF
// partition and pay EVERY induced edge inside those components.
static long long kruskal_B(const Inst& g) {
    int n = g.n;
    vector<int> fa(n + 1), rk(n + 1, 1);
    iota(fa.begin(), fa.end(), 0);
    auto fd = [&](auto&& self, int x) -> int {
        if (fa[x] == x) return x;
        return fa[x] = self(self, fa[x]);
    };
    auto un = [&](int a, int b) {
        a = fd(fd, a);
        b = fd(fd, b);
        if (a == b) return false;
        if (rk[a] > rk[b]) {
            fa[b] = a;
            rk[a] += rk[b];
        } else {
            fa[a] = b;
            rk[b] += rk[a];
        }
        return true;
    };
    auto edges = g.e;
    stable_sort(edges.begin(), edges.end(), [](auto& x, auto& y) {
        return get<2>(x) < get<2>(y);
    });
    int comps = n;
    for (auto [u, v, w] : edges) {
        if (un(u, v)) --comps;
    }
    if (g.k < comps || g.k > n) return -1;

    iota(fa.begin(), fa.end(), 0);
    fill(rk.begin(), rk.end(), 1);
    int tree_cnt = n;
    int need = n - g.k;
    for (auto [u, v, w] : edges) {
        if (need == 0) break;
        if (un(u, v)) {
            --tree_cnt;
            --need;
        }
    }
    long long res = 0;
    for (auto [u, v, w] : g.e) {
        if (fd(fd, u) == fd(fd, v)) res += w;
    }
    (void)tree_cnt;
    return res;
}

// Independent assignment brute force. Returns -2 if the search space is too big.
static long long brute(const Inst& g) {
    int n = g.n, K = g.k;
    double est = 1;
    for (int i = 0; i < n; ++i) {
        est *= K;
        if (est > 6e5) return -2;
    }
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<int> adj(n, 0);
    for (auto [u, v, w] : g.e) {
        --u;
        --v;
        mat[u][v] = mat[v][u] = w;
        adj[u] |= 1 << v;
        adj[v] |= 1 << u;
    }
    int total = 1;
    for (int i = 0; i < n; ++i) total *= K;
    long long best = INF;
    for (int s = 0; s < total; ++s) {
        int maskp[12] = {};
        int x = s;
        bool miss = false;
        int seen_lab = 0;
        for (int i = 0; i < n; ++i) {
            int p = x % K;
            x /= K;
            maskp[p] |= 1 << i;
            seen_lab |= 1 << p;
        }
        if (seen_lab != (1 << K) - 1) continue;
        long long tot = 0;
        bool ok = true;
        for (int p = 0; p < K && ok; ++p) {
            int mask = maskp[p];
            int start = __builtin_ctz(mask);
            int seen = 1 << start;
            int st[12], sp = 0;
            st[sp++] = start;
            while (sp) {
                int y = st[--sp];
                int nbr = adj[y] & mask;
                while (nbr) {
                    int b = __builtin_ctz(nbr);
                    nbr &= nbr - 1;
                    if (seen >> b & 1) continue;
                    seen |= 1 << b;
                    st[sp++] = b;
                }
            }
            if (seen != mask) {
                ok = false;
                break;
            }
            for (int a = 0; a < n; ++a)
                if (mask >> a & 1)
                    for (int b = a + 1; b < n; ++b)
                        if (mask >> b & 1) tot += mat[a][b];
        }
        if (ok) best = min(best, tot);
        (void)miss;
    }
    return best >= INF ? -1 : best;
}

static void expect_eq(const string& name, long long got, long long want) {
    if (got != want) {
        cerr << "ASSERT " << name << " got " << got << " want " << want << "\n";
        exit(1);
    }
}

static void add_edge(Inst& g, int u, int v, int w) {
    if (u > v) swap(u, v);
    for (auto [a, b, c] : g.e) {
        if (a == u && b == v) {
            cerr << "duplicate edge " << u << " " << v << "\n";
            exit(1);
        }
    }
    if (w < 1 || w > 1000 || u == v || u < 1 || v > g.n) {
        cerr << "bad edge " << u << " " << v << " " << w << " n=" << g.n << "\n";
        exit(1);
    }
    g.e.emplace_back(u, v, w);
}

static void normalize(Inst& g) {
    sort(g.e.begin(), g.e.end(), [](auto& x, auto& y) {
        if (get<2>(x) != get<2>(y)) return get<2>(x) < get<2>(y);
        if (get<0>(x) != get<0>(y)) return get<0>(x) < get<0>(y);
        return get<1>(x) < get<1>(y);
    });
    int mx = g.n * (g.n - 1) / 2;
    if (g.n < 1 || g.n > 12 || g.k < 1 || g.k > g.n || (int)g.e.size() > mx) {
        cerr << "bad inst n=" << g.n << " m=" << g.e.size() << " k=" << g.k << "\n";
        exit(1);
    }
}

struct Written {
    string file;
    long long ans, A, B;
    int n, m, k;
    string tag;
};

static Written emit(const string& file, Inst g, const string& tag,
                    long long want = LLONG_MIN) {
    normalize(g);
    long long ans = solve(g);
    long long A = kruskal_A(g);
    long long B = kruskal_B(g);
    long long br = brute(g);
    if (br != -2 && br != ans) {
        cerr << "BRUTE mismatch " << file << " dp " << ans << " brute " << br << "\n";
        exit(1);
    }
    if (want != LLONG_MIN && ans != want) {
        cerr << "WANT mismatch " << file << " got " << ans << " want " << want << "\n";
        exit(1);
    }
    if (!(A != ans || B != ans)) {
        cerr << "not adversarial " << file << " ans=A=B=" << ans << "\n";
        exit(1);
    }
    ofstream in(file + ".in", ios::binary);
    in << g.n << " " << (int)g.e.size() << " " << g.k << "\n";
    for (auto [u, v, w] : g.e) in << u << " " << v << " " << w << "\n";
    ofstream out(file + ".out", ios::binary);
    out << ans << "\n";
    cout << file << "\tn=" << g.n << " m=" << g.e.size() << " K=" << g.k
         << "\tans=" << ans << "\tA=" << A << "\tB=" << B << "\ttag=" << tag << "\n";
    return {file, ans, A, B, g.n, (int)g.e.size(), g.k, tag};
}

static Inst sample1() {
    Inst g;
    g.n = 5;
    g.k = 1;
    add_edge(g, 1, 2, 5);
    add_edge(g, 2, 3, 5);
    add_edge(g, 3, 4, 5);
    add_edge(g, 4, 5, 5);
    return g;
}
static Inst sample2() {
    Inst g;
    g.n = 4;
    g.k = 2;
    add_edge(g, 1, 2, 3);
    add_edge(g, 2, 3, 4);
    add_edge(g, 3, 4, 2);
    add_edge(g, 1, 4, 10);
    return g;
}

static Inst lex_complete(int K) {
    Inst g;
    g.n = 12;
    g.k = K;
    int id = 1;
    for (int u = 1; u <= 12; ++u)
        for (int v = u + 1; v <= 12; ++v) add_edge(g, u, v, id++);
    return g;
}

static Inst uniform_complete(int K) {
    Inst g;
    g.n = 12;
    g.k = K;
    for (int u = 1; u <= 12; ++u)
        for (int v = u + 1; v <= 12; ++v) add_edge(g, u, v, 1000);
    return g;
}

static Inst two_cliques(int K) {
    Inst g;
    g.n = 12;
    g.k = K;
    for (int u = 1; u <= 6; ++u)
        for (int v = u + 1; v <= 6; ++v) add_edge(g, u, v, 1000);
    for (int u = 7; u <= 12; ++u)
        for (int v = u + 1; v <= 12; ++v) add_edge(g, u, v, 1000);
    add_edge(g, 6, 7, 1);
    return g;
}

// Two triangles. Optimal K = CC+1 splits off the cheap edge of the heavy triangle.
static Inst jewel(int n, int K, bool connect) {
    Inst g;
    g.n = n;
    g.k = K;
    add_edge(g, 1, 2, 1);
    add_edge(g, 2, 3, 2);
    add_edge(g, 1, 3, 1000);
    add_edge(g, 4, 5, 100);
    add_edge(g, 5, 6, 101);
    add_edge(g, 4, 6, 102);
    if (connect) {
        add_edge(g, 3, 4, 1000);
        for (int v = 7; v <= n; ++v) add_edge(g, 1, v, 1000);
    }
    return g;
}

static Inst three_triangles(int K) {
    Inst g;
    g.n = 9;
    g.k = K;
    add_edge(g, 1, 2, 10);
    add_edge(g, 2, 3, 11);
    add_edge(g, 1, 3, 900);
    add_edge(g, 4, 5, 12);
    add_edge(g, 5, 6, 13);
    add_edge(g, 4, 6, 901);
    add_edge(g, 7, 8, 14);
    add_edge(g, 8, 9, 15);
    add_edge(g, 7, 9, 902);
    return g;
}

// Two lightest edges share vertex 1; their other ends have a heavy chord.
// A disjoint medium edge is the correct second province.
static Inst shared_vertex(int n, int K, bool connect) {
    Inst g;
    g.n = n;
    g.k = K;
    add_edge(g, 1, 2, 1);
    add_edge(g, 1, 3, 2);
    add_edge(g, 2, 3, 1000);
    add_edge(g, 4, 5, 3);
    if (connect) {
        for (int v = 4; v <= n; ++v)
            if (!(v == 4 || v == 5)) add_edge(g, 1, v, 999);
        add_edge(g, 1, 4, 999);
        add_edge(g, 1, 5, 999);
    }
    return g;
}

// Cheapest three edges span a K_{2,2} whose fourth edge is heavy.
static Inst bipartite_heavy(int n, int K, bool connect) {
    Inst g;
    g.n = n;
    g.k = K;
    add_edge(g, 1, 4, 1);
    add_edge(g, 1, 5, 2);
    add_edge(g, 2, 4, 3);
    add_edge(g, 3, 6, 4);
    add_edge(g, 2, 5, 800);
    if (connect) {
        add_edge(g, 1, 3, 1000);
        for (int v = 7; v <= n; ++v) add_edge(g, 1, v, 1000);
    }
    return g;
}

static Inst random_graph(mt19937& rng, int n, int K, int m, bool force_conn) {
    Inst g;
    g.n = n;
    g.k = K;
    vector<pair<int, int>> cand;
    for (int u = 1; u <= n; ++u)
        for (int v = u + 1; v <= n; ++v) cand.emplace_back(u, v);
    shuffle(cand.begin(), cand.end(), rng);
    vector<pair<int, int>> picked;
    if (force_conn) {
        // random spanning tree via random Prufer-like: union random edges
        vector<int> fa(n + 1);
        iota(fa.begin(), fa.end(), 0);
        auto fd = [&](auto&& self, int x) -> int {
            return fa[x] == x ? x : fa[x] = self(self, fa[x]);
        };
        for (auto [u, v] : cand) {
            int a = fd(fd, u), b = fd(fd, v);
            if (a == b) continue;
            fa[a] = b;
            picked.emplace_back(u, v);
            if ((int)picked.size() == n - 1) break;
        }
    }
    for (auto [u, v] : cand) {
        if ((int)picked.size() >= m) break;
        bool has = false;
        for (auto [a, b] : picked)
            if (a == u && b == v) has = true;
        if (!has) picked.emplace_back(u, v);
    }
    vector<int> ws((int)picked.size());
    iota(ws.begin(), ws.end(), 1);
    // spread weights up to 1000
    if (!ws.empty()) {
        for (int i = 0; i < (int)ws.size(); ++i)
            ws[i] = 1 + (int)((long long)i * 999 / max(1, (int)ws.size() - 1));
        // fix possible duplicates by a second pass
        for (int i = 1; i < (int)ws.size(); ++i)
            if (ws[i] <= ws[i - 1]) ws[i] = min(1000, ws[i - 1] + 1);
    }
    shuffle(ws.begin(), ws.end(), rng);
    for (int i = 0; i < (int)picked.size(); ++i)
        add_edge(g, picked[i].first, picked[i].second, ws[i]);
    return g;
}

int main() {
    expect_eq("sample1", solve(sample1()), 20);
    expect_eq("sample1brute", brute(sample1()), 20);
    expect_eq("sample2", solve(sample2()), 5);
    expect_eq("sample2brute", brute(sample2()), 5);
    expect_eq("sample2A", kruskal_A(sample2()), 5);  // samples do not separate A

    // Hand proofs that do not depend on the DP.
    // uniform K=1: C(12,2)*1000 = 66000
    // uniform K=5: parts 3,3,2,2,2 -> (3+3+1+1+1)*1000 = 9000
    // uniform K=12: 0
    // lex K=1: sum 1..66 = 2211, A = sum 1..11 = 66
    // two cliques K=2: 21001, K=3: 12001
    expect_eq("uni1", solve(uniform_complete(1)), 66000);
    expect_eq("uni5", solve(uniform_complete(5)), 9000);
    expect_eq("uni12", solve(uniform_complete(12)), 0);
    expect_eq("lex1", solve(lex_complete(1)), 2211);
    expect_eq("lex1A", kruskal_A(lex_complete(1)), 66);
    expect_eq("lex12", solve(lex_complete(12)), 0);

    expect_eq("clique2", solve(two_cliques(2)), 21001);
    expect_eq("clique2B", brute(two_cliques(2)), 21001);
    expect_eq("clique3", solve(two_cliques(3)), 12001);
    expect_eq("clique3B", brute(two_cliques(3)), 12001);

    expect_eq("jewel6", solve(jewel(6, 3, true)), 304);
    expect_eq("jewel6B", brute(jewel(6, 3, true)), 304);
    expect_eq("jewel6A", kruskal_A(jewel(6, 3, true)), 103);
    expect_eq("jewel12", solve(jewel(12, 9, true)), 304);

    expect_eq("tri3", solve(three_triangles(3)), 2778);
    expect_eq("tri3B", brute(three_triangles(3)), 2778);
    expect_eq("tri2", solve(three_triangles(2)), -1);
    // K=4 splits triangle 3 (keep edge 14): 921+926+14 = 1861
    expect_eq("tri4", solve(three_triangles(4)), 1861);
    expect_eq("tri4B", brute(three_triangles(4)), 1861);

    expect_eq("share6", solve(shared_vertex(6, 4, true)), 4);
    expect_eq("share6B", brute(shared_vertex(6, 4, true)), 4);
    expect_eq("share6A", kruskal_A(shared_vertex(6, 4, true)), 3);
    expect_eq("share12", solve(shared_vertex(12, 10, true)), 4);

    expect_eq("bip6", solve(bipartite_heavy(6, 3, true)), 7);
    expect_eq("bip6B", brute(bipartite_heavy(6, 3, true)), 7);
    expect_eq("bip6A", kruskal_A(bipartite_heavy(6, 3, true)), 6);
    expect_eq("bip12", solve(bipartite_heavy(12, 9, true)), 7);

    // self-check oracle against brute on random small graphs
    mt19937 rng(20261003);
    for (int t = 0; t < 80; ++t) {
        int n = 1 + (int)(rng() % 6);
        int K = 1 + (int)(rng() % n);
        int mx = n * (n - 1) / 2;
        int m = (int)(rng() % (mx + 1));
        Inst g = random_graph(rng, n, K, m, false);
        long long a = solve(g);
        long long b = brute(g);
        if (b != -2 && a != b) {
            cerr << "random brute mismatch t=" << t << " dp " << a << " br " << b << "\n";
            exit(1);
        }
    }
    cout << "oracle checks passed\n";

    vector<Written> all;
    all.push_back(emit("01_k_eq_n", lex_complete(12), "k=n => 0", 0));
    all.push_back(emit("02_impossible_edgeless", [] {
        Inst g;
        g.n = 12;
        g.k = 6;
        return g;
    }(), "K < CC, no edges", -1));
    all.push_back(emit("03_impossible_below_cc", [] {
        Inst g;
        g.n = 12;
        g.k = 7;
        add_edge(g, 1, 2, 10);
        add_edge(g, 3, 4, 20);
        add_edge(g, 5, 6, 30);
        add_edge(g, 7, 8, 40);
        return g;
    }(), "K < CC, matching", -1));
    all.push_back(emit("04_k1_pay_all_edges", lex_complete(1), "K=1 pay every edge", 2211));
    all.push_back(emit("05_msf_keeps_heavy_chord", jewel(6, 3, true), "split heavy triangle", 304));
    all.push_back(emit("06_msf_keeps_heavy_chord_n12", jewel(12, 9, true), "same, n=12 connected", 304));
    all.push_back(emit("07_k_eq_cc_pay_chords", three_triangles(3), "K=CC pay chords", 2778));
    all.push_back(emit("08_impossible_three_triangles", three_triangles(2), "K=CC-1", -1));
    all.push_back(emit("09_split_one_triangle", three_triangles(4), "K=CC+1 choose which", 1861));
    all.push_back(emit("10_two_cliques_k2", two_cliques(2), "bridge vs balanced cut", 21001));
    all.push_back(emit("11_two_cliques_k3", two_cliques(3), "bridge province + two pures", 12001));
    all.push_back(emit("12_two_cliques_k4", two_cliques(4), "two cliques K=4"));
    all.push_back(emit("13_light_edges_share_vertex", shared_vertex(6, 4, true), "shared endpoint", 4));
    all.push_back(emit("14_light_edges_share_vertex_n12", shared_vertex(12, 10, true), "shared endpoint n=12", 4));
    all.push_back(emit("15_bipartite_heavy_fourth", bipartite_heavy(6, 3, true), "K22 heavy edge", 7));
    all.push_back(emit("16_bipartite_heavy_fourth_n12", bipartite_heavy(12, 9, true), "K22 heavy edge n=12", 7));
    all.push_back(emit("17_uniform_complete_k1", uniform_complete(1), "66*1000", 66000));
    all.push_back(emit("18_uniform_complete_k5", uniform_complete(5), "balanced 3,3,2,2,2", 9000));
    all.push_back(emit("19_uniform_complete_k12", uniform_complete(12), "K=n uniform", 0));

    // lex complete: emit every K where both wrong answers differ, but keep the
    // single K with the largest gap so the suite stays readable. K=6 is forced
    // below if it is not that K.
    {
        long long best_gap = -1;
        int best_k = -1;
        long long best_ans = 0, best_A = 0, best_B = 0;
        for (int K = 1; K <= 12; ++K) {
            Inst g = lex_complete(K);
            long long ans = solve(g);
            long long A = kruskal_A(g);
            long long B = kruskal_B(g);
            cout << "lex K=" << K << " ans=" << ans << " A=" << A << " B=" << B << "\n";
            if (A == ans || B == ans) continue;
            long long gap = min(llabs(A - ans), llabs(B - ans));
            if (gap > best_gap) {
                best_gap = gap;
                best_k = K;
                best_ans = ans;
                best_A = A;
                best_B = B;
            }
        }
        cout << "lex best K=" << best_k << " ans=" << best_ans << " A=" << best_A
             << " B=" << best_B << "\n";
        if (best_k > 0)
            all.push_back(emit("20_lex_complete_best_gap", lex_complete(best_k), "lex complete max gap"));
        if (best_k != 6)
            all.push_back(emit("21_lex_complete_k6", lex_complete(6), "lex star skeleton K=6"));
    }

    // Random n=12 graphs. Keep the three with the largest gap where A and B
    // are both wrong and the answer is feasible.
    struct Cand {
        long long gap;
        int id;
        Inst g;
    };
    vector<Cand> cands;
    mt19937 rng2(20261003);
    for (int t = 0; t < 40; ++t) {
        int K = 2 + (int)(rng2() % 9);  // 2..10
        int m = 20 + (int)(rng2() % 40);  // 20..59
        Inst g = random_graph(rng2, 12, K, m, true);
        long long ans = solve(g);
        long long A = kruskal_A(g);
        long long B = kruskal_B(g);
        if (ans < 0 || A == ans || B == ans) continue;
        long long gap = min(llabs(A - ans), llabs(B - ans));
        cands.push_back({gap, t, g});
    }
    sort(cands.begin(), cands.end(), [](auto& x, auto& y) {
        if (x.gap != y.gap) return x.gap > y.gap;
        return x.id < y.id;
    });
    int emitted = 0;
    vector<int> used_k;
    for (auto& c : cands) {
        if (emitted >= 3) break;
        bool kdup = false;
        for (int kk : used_k)
            if (kk == c.g.k) kdup = true;
        if (kdup && emitted < 2) continue;
        string name = "2" + to_string(2 + emitted) + "_random_n12";
        all.push_back(emit(name, c.g, "random seed 20261003"));
        used_k.push_back(c.g.k);
        ++emitted;
    }

    ofstream rep("report.tsv", ios::binary);
    rep << "file\tn\tm\tK\tans\tkruskal_tree\tmsf_induced\ttag\n";
    for (auto& w : all) {
        rep << w.file << "\t" << w.n << "\t" << w.m << "\t" << w.k << "\t" << w.ans
            << "\t" << w.A << "\t" << w.B << "\t" << w.tag << "\n";
    }
    cout << "wrote " << all.size() << " cases\n";
    return 0;
}
