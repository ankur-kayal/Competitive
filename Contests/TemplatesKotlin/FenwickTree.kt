class FenwickTree(n: Int) {
    private val treeN = n
    private val tree = LongArray(treeN + 1) { 0 }
    private var treeSum = 0L

    fun build(initial: MutableList<Long>) {
        assert(treeN == initial.size)
        for(i in 1 .. treeN) {
            tree[i] = initial[i - 1]
            treeSum += initial[i - 1]

            var k = (i and -i) shr 1
            while(k > 0) {
                tree[i] += tree[i - k]
                k = k shr 1
            }
        }
    }

    // index is in [0, treeN)
    fun update(index: Int, change: Long) {
        assert(index in 0 until treeN)
        treeSum += change
        var i = index + 1
        while(i <= treeN) {
            tree[i] += change
            i += i and -i
        }
    }

    // Returns the sum of the range [0, count).
    fun query(count: Int): Long {
        var c = minOf(count, treeN)
        var sum = 0L

        var i = count
        while(i > 0) {
            sum += tree[i]
            i -= i and -i
        }
        return sum
    }

    // Returns the sum of the range [start, tree_n).
    fun querySuffix(start: Int): Long {
        return treeSum - query(start)
    }

    // Returns the sum of the range [a, b).
    fun query(a: Int, b: Int): Long {
        return query(b) - query(a)
    }

    fun get(aa: Int): Long {
        var a = aa
        assert(a in 0 until treeN)
        var above = a + 1
        var sum = tree[above]

        above -= above and -above

        while(a != above) {
            sum -= tree[a]
            a -= a and -a
        }
        return sum
    }

    fun set(index: Int, value: Long): Boolean {
        assert(index in 0 until treeN)
        var current = get(index)

        if(current == value) {
            return false
        }
        update(index, value - current)
        return true
    }

}

/*
* Usage: val tree = FenwickTree(n)
*        tree.build(a) where a is a MutableList<Long>
* */

fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()

    val(n, m) = input.readLine()!!.split(' ').map { it.toInt() }
    val a = input.readLine()!!.split(' ').map { it.toLong() }.toMutableList()

    val tree = FenwickTree(n)
    tree.build(a)
    repeat(m) {
        val(ch, i, v) = input.readLine()!!.split(' ').map { it.toInt() }
        if(ch == 1) {
            tree.set(i, v.toLong())
        } else {
            output.append("${tree.query(i, v)}\n")
        }
    }

    print(output)
}