import csv as csv
import numpy as np

csv_fo = csv.reader(open('train.csv','rb'))
header = csv_fo.next()

data = []
for row in csv_fo:
    data.append(row)
data = np.array(data)
print(data[0,3])
