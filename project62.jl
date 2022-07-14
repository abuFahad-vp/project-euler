using StatsBase

function digitized_sort(n)
    return sort(digits(n))
end

cubes = [x^3 for x in 1000:10000]
cube_digits = map(digitized_sort,cubes)
occur = countmap(cube_digits)

for i in cubes
    if occur[digitized_sort(i)] == 5
        println(i)
        break
    end
end
