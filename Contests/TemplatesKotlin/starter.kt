fun main(args: Array<String>) {
    Thread(null, Main(), "solution", 1 shl 28).start()
}

class Main : Runnable {

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

    override fun run() {
        var t: Int = 1
        t = readInt()
        repeat(t) {
            solve()
        }

        print(output)
    }

    private fun solve() {
        
    }
}