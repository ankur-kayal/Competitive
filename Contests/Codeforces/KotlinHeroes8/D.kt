fun main() {
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }

    val chosenFirst = IntArray(n + 1) { 0 }
    val chosenLast = IntArray(n + 1) { 0 }

    val choices = Array<IntArray>(n + 1) { IntArray(n + 1) }

    var (myChoiceFirst, myChoiceLast) = listOf(-1, -1)

    repeat(m) {
        val(fi, li) = readLine()!!.split(' ').map { it.toInt() }
        if(myChoiceLast == -1 && myChoiceFirst == -1) {
            myChoiceFirst = fi
            myChoiceLast = li
        }
        choices[fi][li]++
        chosenFirst[fi]++
        chosenLast[li]++
    }
    
    var ans = 0
    
    for(i in 1..n) {
        for(j in 1..n) {
            if(i == j) continue;
            val first = i; val last = j

            val allCorrect = choices[first][last]

            val oneCorrect = chosenFirst[first] + chosenLast[last] - 2 * allCorrect;

            // println("$allCorrect $oneCorrect")

            var score = 0
            if(myChoiceFirst == first) {
                score++
            }
            if(myChoiceLast == last) {
                score++
            }

            if(score == 2) {
                ans = maxOf(ans, 1)
            }
            else if(score == 1) {
                ans = maxOf(ans, allCorrect + 1)
            }
            else  {
                ans = maxOf(ans, allCorrect + oneCorrect + 1)
            }

            // println("$ans $score")
        }
    }
    
    println(ans)
}
