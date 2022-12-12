
f = open("project83.txt","r")
fr = open("matrix_main.c","w")
len = 80

lines = readlines(f)
matrix = zeros(Int64,len,len)
i=1
for l in lines
    global i
    sub = split(l,",")
    j = 1
    for s in sub
        matrix[i,j] = parse(Int64,s)
        j += 1
    end
    i += 1
end

#println(matrix)

array = []

for i in 1:len
    for k in 1:len
        push!(array,(i,k))
    end
end
write(fr,"{")
for P in array
    if(P[1] == len && P[2] == len) break end
    write(fr,"{")
    for S in array
        if (P[1] == S[1] && (P[2] == S[2]+1 || P[2] == S[2]-1))
            #print("$(matrix[P[1],P[2]] + matrix[S[1],S[2]]) ");
            #write(fr,"$(matrix[P[1],P[2]] + matrix[S[1],S[2]]),");
            if(S[2]==len && S[1]==len)
                write(fr,"$(matrix[P[1],P[2]] + matrix[S[1],S[2]])");
            else
                write(fr,"$(matrix[P[1],P[2]] + matrix[S[1],S[2]]),");
            end
        elseif (P[2] == S[2] && (P[1] == S[1]+1 || P[1] == S[1]-1))
            #write(fr,"$(matrix[P[1],P[2]] + matrix[S[1],S[2]]),");
            if(S[2]==len && S[1]==len)
                write(fr,"$(matrix[P[1],P[2]] + matrix[S[1],S[2]])");
            else
                write(fr,"$(matrix[P[1],P[2]] + matrix[S[1],S[2]]),");
            end
        else
            #print("0 ")
            if(S[2]==len && S[1]==len)
                write(fr,"0")
            else
                write(fr,"0,")
            end
        end
    end
    #println()
    write(fr,"},\n")
end
write(fr,"{")
for i in 1:len*len-1
    #print("0 ")
    write(fr,"0,")
end
#println()
write(fr,"0}};\n")
close(fr)
close(f)

