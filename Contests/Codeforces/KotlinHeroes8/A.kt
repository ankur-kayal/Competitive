
fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val s = readLine()!!
        var greater = 0; var lesser = 0

        for(i in s) {
            if(i == '<') {
                lesser++;
            } else if(i == '>') {
                greater++
            }
        }

        if(greater == 0 && lesser != 0) {
            println('<')
        }
        if(lesser == 0 && greater != 0) {
            println('>')
        }
        if(greater == 0 && lesser == 0) {
            println('=')
        }
        if(greater != 0 && lesser != 0) {
            println('?')
        }
    }
}

