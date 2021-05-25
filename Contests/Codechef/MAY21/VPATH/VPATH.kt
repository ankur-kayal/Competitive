import java.lang.AssertionError

private val input = System.`in`.bufferedReader()
private val output = StringBuilder()

private fun readLn() = input.readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

private fun runCase() {
    var n = readInt()
    val adj = Array(n){ mutableListOf<Int>()}
    for(i in 2..n) {
        var(u, v) = readInts()
        --u; --v
        adj[v].add(u)
        adj[u].add(v)
    }

    val values = LongArray(n){1}
    var ans = 0L
    val mod : Long = 1_000_000_007L

    fun dfs(node: Int, par: Int) {
        var (sum, sq) = listOf(0L, 0L)
        for(child in adj[node]) {
            if(child != par) {
                dfs(child, node)
                values[node] = (values[node] + (values[child] * 2) % mod)%mod
                sum += values[child]
                sum %= mod
                sq += (values[child]*values[child])%mod
                sq %= mod
            }
        }
        var special = ((((sum * sum) % mod) - sq) % mod + mod) % mod
        ans += special
        ans %= mod
    }

    dfs(0, -1)
    ans += values[0]
    ans %= mod

    output.append("$ans\n")
}


fun main(args: Array<String>) {

    var t: Int = 1
    t = readInt()
    repeat(t) {
        runCase()
    }

    print(output)
}

