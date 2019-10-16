def perm(str1):
    if len(str1) < 2:
        return str1
    res = []
    for i, c in enumerate(str1):
        for cc in perm(str1[i+1:] + str1[:i]):
            res.append(c + cc)
    return res
if __name__=="__main__":
    for i in perm(input()):
        print (i);
