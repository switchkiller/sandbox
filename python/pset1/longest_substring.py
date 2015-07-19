s="barun singhaniaabc"
start=0
end=0
temp_start=0
for i in range(1,len(s)):
    if s[i-1] > s[i]:
        temp_start=i
    if i - temp_start>start-end :
        start=temp_start
        end=i
print "Longest alphabetical sub-string: ",s[start:end+1]
