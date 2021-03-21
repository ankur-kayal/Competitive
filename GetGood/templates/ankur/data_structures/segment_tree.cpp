#include <bits/stdc++.h>
using namespace std;

#define Stringize( L )     #L 
#define MakeString( M, L ) M(L)
#define $Line MakeString( Stringize, __LINE__ )
#define Reminder __FILE__ "(" $Line ") : Warning: "

struct custom_node {
    int64_t val;
    int64_t lazy;
    // add more data types if you need  

    custom_node() {
        ... init here with default neutral values;

        /*
        val = 1e18;
        lazy = 1e18;
        */
    }

    custom_node(int64_t _val) {
        ... init here with the actual value
        /*
        val = _val;
        lazy = 1e18;
        */
    }

    custom_node op(custom_node& other) {
        ... update the operation you want to use
        /*
        custom_node ans = custom_node(min(val, other.val));
        return ans;
        */
    }

    custom_node lazy_op(int64_t val, int64_t size) {
        ... define the lazy operation you want to use
        /*
        custom_node ans;
        ans.lazy = val;
        ans.val = (val);
        */
    }
};

struct segment_tree {
    int size; // size of the segment tree, 

    custom_node NEUTRAL_ELEMENT; //  neutral element

    int NO_LAZY; // define the parameter which defines if you have any lazy left

    vector<custom_node> values; // segment tree cumulative values

    void init(int n) {
        #pragma message(Reminder "Don't forget to define the lazy parameter")
        NO_LAZY = -1; // define the no lazy parameter
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.assign(2 * size, NEUTRAL_ELEMENT);
    }

    custom_node merge(custom_node& a, custom_node& b) {
        custom_node res;
        res = a.op(b);
        return res;
    }

    void build(vector<int64_t>& a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < int(a.size())) {
                values[x] = custom_node(a[lx]);
            }
            return;
        }

        int m = (rx + lx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void build(vector<int64_t>& a) {
        build(a, 0, 0, size);
    }

    custom_node query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(lx >= r or l >= rx) {
            return NEUTRAL_ELEMENT;
        }

        else if(lx >= l and rx <= r) {
            return values[x];
        }

        int m = (lx + rx) / 2;

        custom_node s1 = query(l, r, 2 * x + 1, lx, m);
        custom_node s2 = query(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
    }

    custom_node query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

    void propagate(int x, int lx, int rx) {
        if(values[x].lazy == NO_LAZY) {
            return;
        }
        int m = (rx - lx) / 2;

        values[x] = values[x].lazy_op(values[x].lazy, rx - lx);

        if(rx - lx != 1) { // if you have children propagate the lazy parameter to the children
            // custom define how you want to update !! Most errors occur Here !!
            #pragma message(Reminder "Define how you want to pass lazy parameters, once done comment this")
            values[2 * x + 1].lazy = values[x].lazy;
            values[2 * x + 2].lazy = values[x].lazy;

        }

        values[x].lazy = NO_LAZY;
    }

    void range_update(int l, int r, int val, int x, int lx, int rx) {
        propagate(x, lx, rx); // try propagating once you touch every node
        if(lx >= r or l >= rx) {
            return;
        }
        if(lx >= l and rx <= r) {
            // custom define how you want to update !! Most errors occur Here !!
            #pragma message(Reminder "Define how you want to pass lazy parameters and update, once done comment this")
            // values[x].val = val;
            values[x].lazy = val;
            propagate(x, lx, rx);
            return;
        }

        int m = (lx + rx) / 2;
        range_update(l, r, val, 2 * x + 1, lx, m);
        range_update(l, r, val, 2 * x + 2, m, rx);

        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void range_update(int l, int r, int val) {
        range_update(l, r, val, 0, 0, size);
    }
};