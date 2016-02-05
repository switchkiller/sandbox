def sol(n,k):
    if (n%k == 0):
        return n,k
    else
        return min(sol(n-1,k),sol(n+1,k),sol(n,k-1),sol(n,k+1))

if __name__="__main__":
    x=[int(input()) for _ in range(2)]
    print (sol(x[0],x[1])
