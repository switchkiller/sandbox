s="maulana azad national institute of technology"
count=0
for i in range(0,len(s)-3):
    if s[i:i+4] == "azad":
        count +=1
print "Number of times azad occured: " + str(count)
