/*
update(i, a, b)
    set A[i] = a and B[i] = b
    O(log N)
query(l, r)
    return min{l <= i < r} A[i] * T + B[i]
    O(log N)
heaten(new_T)
    set T = new_temp (! current_T < new_T)
    O((log N) ^ 2) Amortized

Ref : 
https://codeforces.com/blog/entry/82094
https://koosaga.com/307
*/
template<typename T>
struct KineticSegmentTree{
private:
    const T TINF = numeric_limits<T>::max() / 2;
    using Line = pair<T, T>;

    int sz;
    T temp;             // temperature
    vector<Line> lines; // min line
    vector<T> melt;     // melting temperature of each subtree

    inline T f(const Line &L, T x) const {
        return L.first * x + L.second;
    }

    // f(lhs, temp) < f(rhs, temp) ?
    inline bool le(const Line &lhs, const Line &rhs) const {
        T flhs = f(lhs, temp), frhs = f(rhs, temp);
        if(flhs != frhs) return flhs < frhs;
        return lhs.first < rhs.first; // (!) temp < x : lhs < rhs
    }

    // return x, temp < x && f(A, x) == f(B, x)
    T intersect(Line A, Line B) const {
        if(A.first == B.first) return TINF;
        if(A.first < B.first) swap(A, B);
        T delta = f(B, temp) - f(A, temp);
        T delta_slope = A.first - B.first;
        T ret = temp + (delta - 1) / delta_slope + 1;
        return ret > temp ? ret : TINF;
    }

    void recalc(int k){
        if(k >= sz)        return ; 
        if(melt[k] > temp) return ; // (!) nothing to update
        // update後のrecalcでは，関係ないノードはここで止まる

        recalc(2 * k);
        recalc(2 * k + 1);

        auto L = lines[2 * k], R = lines[2 * k + 1];
        if(le(L, R)) lines[k] = L;
        else         lines[k] = R;

        melt[k] = min(melt[2 * k], melt[2 * k + 1]);
        if(L != R){
            T t = intersect(L, R);
            melt[k] = min(melt[k], t);
        }
        return ;
    }

    T query(int l, int r, int k, int a, int b){
        if(b <= l or r <= a) return TINF;
        if(l <= a and b <= r) return f(lines[k], temp);
        int m = (a + b) / 2;
        return min(query(l, r, 2 * k, a, m), query(l, r, 2 * k + 1, m, b));
    }

public:
    KineticSegmentTree(int N, T temp_ = T(0)) : temp(temp_){
        sz = 1;
        while(sz < N) sz <<= 1;
        lines.assign(sz * 2, {0, TINF});
        melt.assign(sz * 2, TINF);
    }

    // O(log N)
    void update(int idx, T a, T b){
        int k = idx + sz;
        lines[k] = {a, b};
        k >>= 1;
        for(; k; k >>= 1){
            melt[k] = -TINF; // re-set in recalc↓
            recalc(k);
        }
    }

    // O(log N)
    T query(int l, int r){
        return query(l, r, 1, 0, sz);
    }

    // Amortized O((log N) ^ 2)
    void heaten(T new_temp){
        assert(new_temp >= temp);
        temp = new_temp;
        recalc(1);
    }
};