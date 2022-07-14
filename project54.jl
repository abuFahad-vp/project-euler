using DelimitedFiles

file = open("project54.txt", "r")

games = readdlm(file,'\n')

value_letter = Dict()
char_value = ['J','Q','K','A','T']
value_letter['J'] = 11
value_letter['Q'] = 12
value_letter['K'] = 13
value_letter['A'] = 14
value_letter['T'] = 10

function init(game)
    beta = split(game,' ')
    g = [[],[]]
    c = 1
    while c < 3
        for i in 1:5
            a = popfirst!(beta)
            card = []
            if a[1] in char_value
                push!(card,value_letter[a[1]])
            else
                push!(card,parse(Int64,a[1]))
            end
            push!(card,a[2])
            push!(g[c],card)
        end
        c += 1
    end
    sort!(g[1],by=x->x[1])
    sort!(g[2],by=x->x[1])
    return g
end

#1 High Card: Highest value card.
#2 One Pair: Two cards of the same value.
#3 Two Pairs: Two different pairs.
#4 Three of a Kind: Three cards of the same value.
#5 Straight: All cards are consecutive values.
#6 Flush: All cards of the same suit.
#7 Full House: Three of a kind and a pair.
#8 Four of a Kind: Four cards of the same value.
#9 Straight Flush: All cards are consecutive values of same suit.
#10 Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.

function highest_value(cards)
   i = lastindex(cards)
   return cards[i][1] 
end

function one_pair(cards)
    for i in 1:4
        if cards[i][1] == cards[i+1][1]
            return [2,cards[i][1]]
        end
    end
    return [0,false]
end

function two_pairs(cards)
    f = 0
    for i in 1:4
        if cards[i][1] == cards[i+1][1]
            f = cards[i][1]
            break
        end
    end   
    if f==0
        return [0,false]

    end
    for i in 1:4
        if cards[i][1] == cards[i+1][1] && cards[i][1] != f
            if f > cards[i][1]
                return [3,f]
            else
                return [3,cards[i][1]]
            end
        end
    end
    return [0,false]

end

function three_kind(cards)
    for i in 1:3    
        if cards[i][1]==cards[i+1][1]==cards[i+2][1]
            return [4,cards[i][1]]
        end
    end
    return [0,false]
end

function straight(cards)
    n = cards[1][1]
    if cards[2][1]==n+1 && cards[3][1]==n+2 && cards[4][1]==n+3 && cards[5][1]==n+4
        return [5,0]
    end
    return [0,false]
end

function flush(cards)
    if cards[1][2] == cards[2][2] == cards[3][2] == cards[4][2] == cards[5][2]
        return [6,0]
    end
    return [0,false]
end

function full_house(cards)
    t = three_kind(cards) 
    if t[2] == false
        return [0,false]
    end
    for i in 1:4
        if cards[i][1] == cards[i+1][1] && t[2] != cards[i][1]
            return [7,t[2],cards[i][1]]
        end 
    end
    return [0,false]
end

function four_kind(cards)
    for i in 1:2    
        if cards[i][1]==cards[i+1][1]==cards[i+2][1]==cards[i+3][1]
            return [8,cards[i][1]]
        end
    end
    return [0,false]
end

function straight_flush(cards)

    if straight(cards)[2] != false && flush(cards)[2] != false
        return [9]
    end 
    return [0,false]
end

function royal_flush(cards)
    if cards[1][1] == 10 && straight(cards)[2] != false && flush(cards)[2] != false
        return [10]
    end  
    return [0,false]
end

# 5H 5C 6S 7S KD
# 2C 3S 8S 8D TD

function maxvalue(card)
    value = [royal_flush(card),straight_flush(card),four_kind(card),full_house(card),flush(card),straight(card),three_kind(card),two_pairs(card),one_pair(card),highest_value(card)] 
    return value
end

c = 1

p = 0
while c < 1001
    f = init(games[c])
    p1 = maxvalue(f[1])
    p2 = maxvalue(f[2])
    for i in 1:10
        if i==10
            pl1 = 0
            pl2 = 0
            while true
                pl1 = highest_value(f[1])
                pl2 = highest_value(f[2])
                if pl1 == pl2
                    pop!(f[1])
                    pop!(f[2])
                else
                    break
                end
            end
            if pl1 > pl2 
                p += 1
                break
            else
                break
            end
        elseif p1[i][1] > p2[i][1]
            p += 1
            break
        elseif p1[i][1]==p2[i][1]==7
            if p1[i][2] > p2[i][2]
                p += 1
                break
            elseif p1[i][2]==p2[i][2]
                if p1[i][3] > p2[i][3]
                    p += 1
                    break
                end
            end
        elseif p1[i][1]==p2[i][1]==2
            if p1[i][2] > p2[i][2]
                p += 1
                break
            end
        end
    end
    c += 1
end

p/2

# lazy to code answer is 376