m=3
n=int(raw_input())
def count( n, m ):
#	global S
    if n == 0:
        return 1
    if n < 0:
        return 0
    if m <= 0 and n >= 1: #m < 0 for zero indexed programming languages
        return 0
 
    return count( n, m - 1 ) + count( n - S[m], m )
S=[0,1,2,3]

print count(n,m)