#Linear regression on google stock
import pandas as pd
import quandl, math
import numpy as np
from sklearn import preprocessing, cross_validation, svm
from sklearn.linear_model import LinearRegression

df = quandl.get('WIKI/GOOGL')

#print(df.head())

df = df[['Adj. Open','Adj. High','Adj. Low','Adj. Close','Adj. Volume',]]
df['HL_PCT'] = (df['Adj. High'] - df['Adj. Low']) / df['Adj. Low'] * 100.0
df['PCT_change'] = (df['Adj. Close'] - df['Adj. Open']) / df['Adj. Open'] * 100.0


df = df[['Adj. Close','HL_PCT','PCT_change','Adj. Volume',]]

forecast_col = 'Adj. Close'

#replace NaN using pandas with a raw value
df.fillna(-99999, inplace=True)
forecast_out = int(math.ceil(0.01*len(df)))

df['label'] = df[forecast_col].shift(-forecast_out)
df.dropna(inplace=True)

# print(df.head())

#here we define X features and y labels
X = np.array(df.drop(['label'], 1))
y = np.array(df['label'])

#normalize the data. Basically it will reduce the computation time
X = preprocessing.scale(X)

print(len(X), len(y))
