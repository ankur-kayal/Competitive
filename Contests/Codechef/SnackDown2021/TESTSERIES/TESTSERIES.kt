

fun main(args: Array<String>) {
    Thread(null, Main(), "whatever", 1 shl 28).start()
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
        val results = readInts()
        var india = 0; var england = 0

        for(result in results) {
            if(result == 1) {
                india++
            } else if(result == 2) {
                england++
            }
        }

        when {
            india > england -> {
                output.append("INDIA\n")
            }
            england > india -> {
                output.append("ENGLAND\n")
            }
            else -> {
                output.append("DRAW\n")
            }
        }
    }
}
