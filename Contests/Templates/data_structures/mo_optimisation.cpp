inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? (
        (y < hpow) ? 0 : 3
    ) : (
        (y < hpow) ? 1 : 2
    );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}
 
struct Query {
    int64_t l, r, id;
    int64_t ord;
 
    Query() {}
 
    Query(int64_t _l, int64_t _r, int64_t _id) : l(_l), r(_r), id(_id) {calcOrder();}
 
    inline void calcOrder() {
        ord = gilbertOrder(l, r, 21, 0);
    }
};
 
inline bool operator<(const Query &a, const Query &b) {
    return a.ord < b.ord;
}

int main() {
    sort(queries.begin(), queries.end());
 
    int global_left = 0, global_right = 0;
 
    auto add_element = [&](int64_t element) {
        
    };
 
    auto delete_element = [&](int64_t element) {
        
    };
 
    for(Query q: queries) {
 
        while(global_left < q.l) {
            delete_element(A[global_left]);
            global_left++;
        }
 
        while(global_left > q.l) {
            global_left--;
            add_element(A[global_left]);
        }
 
        while(global_right < q.r) {
            add_element(A[global_right]);
            global_right++;
        }
 
        while(global_right > q.r) {
            global_right--;
            delete_element(A[global_right]);
        }
 
        answers[q.id] = ans;
    }
}