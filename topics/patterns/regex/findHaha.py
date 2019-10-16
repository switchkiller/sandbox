import re
haRegex = re.compile(r'(Ha){,3}')
res = haRegex.search('HaHaHa')
res.group()
print res
