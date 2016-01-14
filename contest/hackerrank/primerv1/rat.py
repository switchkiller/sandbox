flag = 0
def permutations(string, text, step = 0):
    if step == len(string):
        str = "".join(string)
        if str in text:
            global flag
            flag = 1
    for i in range(step, len(string)):
        string_copy = [character for character in string]
        string_copy[step], string_copy[i] = string_copy[i], string_copy[step]
        permutations(string_copy,text, step + 1)

if __name__ == '__main__':
    t = int(raw_input())
    for i in range(t) :
        string = raw_input()
        text = raw_input()
        permutations(string, text)
        if (flag == 0):
            print "NO"
        else:
            print "YES"
        flag = 0
