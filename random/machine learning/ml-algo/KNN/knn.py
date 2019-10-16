from __future__ import division
import numpy as np
import pandas as pd
import random
from math import sqrt
import matplotlib.pyplot as plt
import warnings
from matplotlib import style
from collections import Counter
style.use('fivethirtyeight')

def k_nearest_neighbours(data, predict, k=3):
    if len(data) >= k :
        warnings.warn("K is less!")
    distances = []
    for group in data:
        for features in data[group]:
            euclidean_distance = np.linalg.norm(np.array(features)-np.array(predict))
            distances.append([euclidean_distance, group])

    votes = [i[1] for i in sorted(distances)[:k]]
    votes_result = Counter(votes).most_common(1)[0][0]
    # print votes_result
    confidence = Counter(votes).most_common(1)[0][1] / k
    # print (confidence)
    return votes_result, confidence

# Random testing dataset
# dataset = {'k': [ [1,2], [2,3], [3,1] ], 'r': [ [6,5], [7,7], [8,6] ]}
# new_feature = [5,7]
accuracies = []
for i in range(5):
    df = pd.read_csv('breast-cancer-wisconsin.data')
    # data munging
    df.replace('?', -99999, inplace=True)
    df.drop(['id'], 1, inplace=True)
    full_data = df.astype(float).values.tolist()

    random.shuffle(full_data)
    test_size = 0.4
    train_set = {2:[], 4:[]}
    test_set =  {2:[], 4:[]}
    train_data = full_data[:-int(test_size*len(full_data))]
    test_data = full_data[-int(test_size*len(full_data)):]

    for i in train_data:
        train_set[i[-1]].append(i[:-1])

    for i in test_data:
        test_set[i[-1]].append(i[:-1])

    correct = 0
    total = 0

    # testing accuracy

    for group in test_set:
        for data in test_set[group]:
            vote, confidence = k_nearest_neighbours(train_set, data, k=5)
            if group == vote:
                correct += 1
            # else:
                # print (confidence)
            total += 1

    # print (correct, total)

    f = float(correct/total)

    # print('Accuracy:', f)
    accuracies.append(correct/total)

print(sum(accuracies)/len(accuracies))
# result = k_nearest_neighbours(dataset, new_feature)
# print (result)

# [[plt.scatter(ii[0],ii[1], s = 100, color = i) for ii in dataset[i]] for i in dataset]
# plt.scatter(new_feature[0],new_feature[1], color = result)
# plt.show()
