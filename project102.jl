

function Area2(A,B,C)

    x1 = A[1];y1 = A[2]
    x2 = B[1];y2 = B[2]
    x3 = C[1];y3 = C[2]

    area = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)

    return abs(area)
end

f = open("project102.txt", "r")
Points = readlines(f)

function Parsing(string)
    sub = split(string,",")
    return [[parse(Int64,sub[1]),parse(Int64,sub[2])], [parse(Int64,sub[3]),parse(Int64,sub[4])],[parse(Int64,sub[5]),parse(Int64,sub[6])]]

end


function main()
    counter = 0
    P = [0,0]
    for point in Points
        A = Parsing(point)[1]
        B = Parsing(point)[2]
        C = Parsing(point)[3]
        if Area2(A,B,C) == (Area2(A,B,P) + Area2(A,P,C) + Area2(P,B,C))
            counter += 1
        end
    end
    println(counter)
end

main()
