import fileinput
def main():
    for line in fileinput.input():
        try:
            counta=countb=diff=flag=c=0
            rema=remb=5
            for i in range(10):
                c+=1
                if (i%2==0):
                    counta+=int(line[i])
                    rema-=1
                else:
                    countb+=int(line[i])
                    remb-=1
                if (counta>countb):
                    diff=counta-countb
                    if (diff>remb):
                        flag=1
                        break
                elif (countb>counta):
                    diff=countb-counta
                    if (diff>rema):
                        flag=2
                        break
            if (flag==0):
                for i in range(10,len(line)):
                    c+=1
                    if (i%2!=0):
                        diff-=int(line[i])
                        if (diff!=0):
                            break
                    else:
                        diff+=int(line[i])

            if ((diff>0 and flag==0) or (flag==1)):
                print "TEAM-A " + str(c)
            elif ((diff<0 and flag==0) or (flag==2)):
                print "TEAM-B " + str(c)
            else:
                print "TIE"
        except ValueError:
        	print "TIE"

main()
