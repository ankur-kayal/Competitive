
fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val n = readLine()!!.toInt()
        val rhymes = mutableListOf<Int>()
        val dontRhyme = mutableListOf<Int>()

        repeat(n) {
            var(si, ti, ri) = readLine()!!.split(' ')
            if(ri == "1") {
                // rhymes
                si = si.reversed()
                ti = ti.reversed()
                var match = 0
                for(i in 0 until minOf(si.length, ti.length)) {
                    if(si[i] == ti[i]) {
                        match++
                    } else {
                        break
                    }
                }

                rhymes.add(match)
            }

            else {
                // dont rhyme
                si = si.reversed()
                ti = ti.reversed()
                var match = 0
                for(i in 0 until minOf(si.length, ti.length)) {
                    if(si[i] == ti[i]) {
                        match++
                    } else {
                        break
                    }
                }
                dontRhyme.add(match)
            }
        }

        var rhymeMin = rhymes.min()!!
        var dontRhymeMax = dontRhyme.max()


        var k = 0

        val ans = mutableListOf<Int>()


        if(dontRhymeMax == null) {
            for(i in 0..rhymeMin) {
                ans.add(i)
            }
        } else {
            for(i in (dontRhymeMax + 1)..rhymeMin) {
                ans.add(i)
            }
        }

        println(ans.size)
        if(ans.size != 0) {
            println(ans.joinToString(" "))
        }

    }
}

