
fun main() {
    val t = readLine()!!.toInt()
    
    fun calculateCost(c: CharArray, target: String): Int {
        var cost = 0
        for(i in c.indices) {
            if(c[i] != target[i]) {
                cost++
            }
        }
        
        return cost
    }
    repeat(t) {
        val n = readLine()!!.toInt()
        
        val s = readLine()!!.toCharArray()
        val a = readLine()!!
        
        var possible = true
        var ans = 0
        
        for(i in a.indices) {
            val segment =  charArrayOf(s[i], s[i + 1], s[i + 2], s[i + 3])
            if(a[i] == '1') {
                if(i + 1 in a.indices && a[i + 1] == '1') {
                    possible = false
                    break
                }
                else if(i + 2 in a.indices && a[i + 2] == '1') {
                    
                    ans += calculateCost(segment, "()()")
                    s[i] = '('
                    s[i + 1] = ')'
                    s[i + 2] = '('
                    s[i + 3] = ')'
                }
                else if(i - 2 in a.indices && a[i - 2] == '1') {
                    ans += calculateCost(segment, "()()")
                    s[i] = '('
                    s[i + 1] = ')'
                    s[i + 2] = '('
                    s[i + 3] = ')'
                } else {
                    val cost1 = calculateCost(segment, "(())")
                    val cost2 = calculateCost(segment, "()()")
                    if(cost1 < cost2) {
                        ans += cost1
                        s[i] = '('
                        s[i + 1] = '('
                        s[i + 2] = ')'
                        s[i + 3] = ')'
                    } else {
                        ans += cost2
                        s[i] = '('
                        s[i + 1] = ')'
                        s[i + 2] = '('
                        s[i + 3] = ')'
                    }
                    
                }
            }
        }
        
        if(!possible) {
            ans = -1
        }
        println(ans)
    }
    
}

