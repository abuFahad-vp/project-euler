
# Generate the series of numerator

x = big(2)
y = big(3)
z = big(0)
m = 2
prev = 2
for i in 4:101
    z = m*y + x
    if i%3==0
        prev += 2
        m = prev
    else
        m = 1
    end
    x = y
    y = z
end
sum(digits(z))