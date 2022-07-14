function frac()
    # 40+9/90+8 = 4 / 8
    num = 1
    den = 1
    for a in 1:9
        for b in 1:9
            for c in 1:9
                if ((a*10)+b)/((b*10)+c) == a/c && ((a*10)+b) != ((b*10)+c)
                    num *= ((a*10)+b)
                    den *= ((b*10)+c)
                end
            end
        end
    end
    # // for integer fraction notation
    num//den
end
@time frac()