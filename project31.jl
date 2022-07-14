
# @benchmark 1.590μs
function solutionB(tgt::Int = 200)
  coins = [1, 2, 5, 10, 20, 50, 100, 200]
  ways = zeros(Int, tgt + 1)
  ways[1] = 1

  for coin in coins
    for j in (coin+1):length(ways)
      ways[j] += ways[j - coin]
    end
  end 
  ways[tgt + 1]
end

solutionB()