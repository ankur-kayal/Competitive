#include <bits/stdc++.h>
#include <exception>
#include <stdint.h>
using namespace std;

#define nl '\n'


//----------------------------------- DEBUG -----------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

//----------------------------------- END DEBUG --------------------------------

// TODO: set this to false if it's unnecessary and the time limit might be tight.
// CHECK_OVERFLOW64 = true can run up to 2 times slower (particularly on CF).
const bool CHECK_OVERFLOW64 = false;

using dist_t = long double;

struct point {
    int64_t x, y;

    point() : x(0), y(0) {}

    point(int64_t _x, int64_t _y) : x(_x), y(_y) {}

    point& operator+=(const point &other) { x += other.x; y += other.y; return *this; }
    point& operator-=(const point &other) { x -= other.x; y -= other.y; return *this; }
    point& operator*=(int64_t mult) { x *= mult; y *= mult; return *this; }

    point operator+(const point &other) const { return point(*this) += other; }
    point operator-(const point &other) const { return point(*this) -= other; }
    point operator*(int64_t mult) const { return point(*this) *= mult; }

    bool operator==(const point &other) const { return x == other.x && y == other.y; }
    bool operator!=(const point &other) const { return !(*this == other); }

    point operator-() const { return point(-x, -y); }
    point rotate90() const { return point(-y, x); }

    int64_t norm() const {
        return (int64_t) x * x + (int64_t) y * y;
    }

    dist_t dist() const {
        return sqrt(dist_t(norm()));
    }

    bool top_half() const {
        return y > 0 || (y == 0 && x > 0);
    }

    friend ostream& operator<<(ostream &os, const point &p) {
        return os << '(' << p.x << ", " << p.y << ')';
    }
};



int64_t cross(const point &a, const point &b) {
    return (int64_t) a.x * b.y - (int64_t) b.x * a.y;
}

int64_t dot(const point &a, const point &b) {
    return (int64_t) a.x * b.x + (int64_t) a.y * b.y;
}

int cross_sign(const point &a, const point &b) {
    if (CHECK_OVERFLOW64) {
        long double double_value = (long double) a.x * b.y - (long double) b.x * a.y;

        if (abs(double_value) > 1e18)
            return double_value > 0 ? +1 : -1;
    }

    uint64_t uint64_value = (uint64_t) a.x * b.y - (uint64_t) b.x * a.y;
    int64_t actual = int64_t(uint64_value);
    return (actual > 0) - (actual < 0);
}

bool left_turn_strict(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) > 0;
}

bool left_turn_lenient(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) >= 0;
}

bool collinear(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) == 0;
}

// Returns twice the signed area formed by three points in a triangle. Positive when a -> b -> c is a left turn.
int64_t area_signed_2x(const point &a, const point &b, const point &c) {
    return cross(b - a, c - a);
}

dist_t distance_to_line(const point &p, const point &a, const point &b) {
    assert(a != b);
    return dist_t(abs(area_signed_2x(p, a, b))) / (a - b).dist();
}

int64_t manhattan_dist(const point &a, const point &b) {
    return (int64_t) abs(a.x - b.x) + abs(a.y - b.y);
}

int64_t infinity_norm_dist(const point &a, const point &b) {
    return max(abs(a.x - b.x), abs(a.y - b.y));
}

// Sort in increasing order of y, with ties broken in increasing order of x.
bool yx_compare(const point &a, const point &b) {
    return make_pair(a.y, a.x) < make_pair(b.y, b.x);
}

// Sort in increasing order of angle to the x-axis.
bool angle_compare(const point &a, const point &b) {
    if (a.top_half() ^ b.top_half())
        return a.top_half();

    return cross_sign(a, b) > 0;
}

// -ve means right turn, +ve means left turn, 0 means linear
int64_t cross_product(point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

vector<point> getConvexHull(vector<point> &points) {
    vector<point> upperHull, lowerHull;

    // compute upper hull;

    upperHull = {points[0]};
    lowerHull = {points[0]};

    for(int i=1;i<points.size();i++) {
        while(lowerHull.size() > 1 and cross_product(lowerHull[lowerHull.size() - 2], lowerHull[lowerHull.size() - 1], points[i]) <= 0) {
            lowerHull.pop_back();
        }
        lowerHull.push_back(points[i]);

        while(upperHull.size() > 1 and cross_product(upperHull[upperHull.size() - 2], upperHull[upperHull.size() - 1], points[i]) >= 0) {
            upperHull.pop_back();
        }
        upperHull.push_back(points[i]);
    }

    vector<point> convexHull;

    for(auto u: lowerHull) {
        convexHull.push_back(u);
    }
    if(convexHull.size() > 1) convexHull.pop_back();
    for(int i=upperHull.size()-1;i>=1;i--) {
        convexHull.push_back(upperHull[i]);
    }

    return convexHull;
}


void run_cases() {
    int64_t N, K, D;
    cin >> N >> K >> D;

    vector<point> points;

    for(int i = 0; i < N; i++) {
        int64_t x, y;
        cin >> x >> y;

        points.push_back(point(x, y));
    }

    sort(points.begin(), points.end(), [&](point &a, point &b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });


    // construct the convex hull

    vector<point> hull = getConvexHull(points);

    sort(hull.begin(), hull.end(), [&](point &a, point &b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });

    debug();

    for (auto p: hull) {
        debug() << imie(p);
    }

    const int64_t INF64 = 2e18 + 7;
    vector<int64_t> distance(hull.size(), INF64);
    distance[0] = 0;

    // do djikstra on all the points running the N^2 algo

    vector<bool> used(hull.size(), false);


    for(int i = 0; i < int(hull.size()); i++) {
        // find the minimum distance vertex now excluding the used ones
        pair<int64_t, int64_t> minPoint = {INF64, INF64};
        for(int j = 0; j < int(hull.size()); j++) {
            if (!used[j]) {
                minPoint = min(minPoint, {distance[j], j});
            }
        }

        if(minPoint.first == INF64) {
            break;
        }

        for (int j = 0; j < int(hull.size()); j++) {
            if (used[j] || j == minPoint.second) {
                continue;
            }

            point node = hull[minPoint.second];
            point currentPoint = hull[j];

            int64_t dist = (node.x - currentPoint.x) * (node.x - currentPoint.x) + (node.y - currentPoint.y) * (node.y - currentPoint.y);

            if (dist <= D * D)
                distance[j] = min(distance[j], distance[minPoint.second] + max(K, dist));
        }

        used[minPoint.second] = true;
    }

    cout << (distance.back() == INF64 ? -1 : distance.back()) << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    /*For validation*/
    // freopen("c_validation_input.txt", "r", stdin);
    // freopen("c_validation_output.txt", "w", stdout);

    /*For final submit*/
    // freopen("c_final_input.txt", "r", stdin);
    // freopen("c_final_output.txt", "w", stdout);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": "; 
        run_cases();
    }
}