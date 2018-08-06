s=list(map(str,raw_input().split()))
i=0
ans=""
while s[0][i]<s[1][0]:
	i+=1
ans=s[0][:i]+s[1][0]
print ans
