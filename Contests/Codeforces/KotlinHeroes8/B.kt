
fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val n = readLine()!!.toInt()
        val(a, va) = readLine()!!.split(' ').map { it.toInt() }
        val(c, vc) = readLine()!!.split(' ').map { it.toInt() }
        
        val b = readLine()!!.toInt()
        
        val ans = IntArray(200 + 1) { vc }
        
        ans[a] = va
        ans[c] = vc
        
        var index = c
        var volume = vc
        while(index > a) {
            ans[index] = volume
            volume--
            volume = maxOf(va, volume)
            index--
        }
        
        index = a
        volume = va
        while(index > 0) {
            ans[index] = volume
            volume--
            volume = maxOf(1, volume)
            index--
        }
                
        println(ans[b])
    }
}

