const int N = 2e5 + 5;

typedef int t_data;

const t_data TERM = 0;

struct Segtree {
    vector<t_data> t;
    Segtree() {
        t.assign(4 * N, 0);
    }

    t_data combine(const t_data& x, const t_data& y) {
        return (x > y ? x : y);
    }

    void build(int v, int s, int e, t_data * a) {
        if (s == e) {
            t[v] = a[s];
        } else {
            int mid = (s + e) >> 1;
            build(v << 1, s, mid);
            build(v << 1 | 1, mid + 1, e);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        }
    }

    void update(int v, int s, int e, int pos, t_data val) {
        if (s == e && s == pos) {
            t[v] += val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
            update(v << 1, s, mid, pos, val);
        else
            update(v << 1 | 1, mid + 1, e, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    t_data get(int v, int s, int e, t_data l, t_data r) {
        if (e < l || s > r || l > r)
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        t_data p1 = get(v << 1, s, mid, l, r);
        t_data p2 = get(v << 1 | 1, mid + 1, e, l, r);
        return combine(p1, p2);
    }
};
