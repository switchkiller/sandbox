import re
obj = re.compile(r'(Ha){,3}')
obj.findall('HaHaHa')
