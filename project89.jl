using RomanNumerals


f = open("project89.txt", "r")
RomanNums = readlines(f)



function main() 
    count = 0
    for roman in RomanNums
        count += length(roman) - length(RomanNumeral(roman))
    end
    println(count)
end

main()









