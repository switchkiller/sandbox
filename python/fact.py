__author__="bond007"

def fact(n):
    '''
    >>> fact(4)
    24
    >>> fact(3)
    6
    '''
    if (n==0):
        return 1
    return n*fact(n-1)


if __name__ == "__main__":
    import doctest
    doctest.testmod()
