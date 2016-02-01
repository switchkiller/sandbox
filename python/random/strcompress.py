#!/usr/bin/python3
def strcompress(st):
    count, c = 1, ''
    result = []
    for i, s in enumerate(st):
        if (c == s):
            count += 1
        else:
            result.append(c)
            if i != 0:
                result.append(str(count))
            count = 1
            c = s
    result.append(c)
    result.append(str(count))
    return ''.join(result)

if __name__ == "__main__":
    st = input()
    print (strcompress(st))
