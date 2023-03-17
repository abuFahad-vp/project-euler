
def p141():
    s, limita, limitm = 0, 10**4, 10**12
    for a in xrange(2,limita):
        for b in xrange(1,a):
            if (a**3)*b+(b**2)>=limitm:
                break
            if km.gcd(a,b)>1:
                continue
            c=1
            while True:
                m2=(c**2)*(a**3)*b+c*(b**2)
                if m2>limitm:
                    break
                else:
                    if km.is_square(m2):
                        s+=m2
                c+=1
    print 'Solution: {}'.format(s)

p141()

'''
Solution: 878454337159
p141 took 20.685640 s
'''