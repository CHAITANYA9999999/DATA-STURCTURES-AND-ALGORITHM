import numpy as np
import pandas as pd

a=[8.3,10,15,10,10]
print(np.argsort(a,kind='quick'))

value=[4,2,10,1,2]

weight=[12,1,4,1,2]
n=5
ratio=[]
for i in range(n):
    ratio.append(value[i]/weight[i])

ratio = np.divide(value,weight)
print(ratio)
ratio = np.round(ratio,2)
print(ratio)
ratio_sorted = np.flip(np.sort(ratio))
print(ratio_sorted)

index = np.flip(np.argsort(ratio))
print(index)

def greedyKnapsack(value,weight,n,ratio,W):
    x=[]
    index = np.flip(np.argsort(ratio))
    for i in range(n):
        x.append(0)
    condition = True
    w = 0
    i=0
    while condition:
        if(W > (w + weight[index[i]])):
            x[index[i]] = 1
            w = w+ weight[index[i]]
        else:
            x[index[i]] = (W-w)/weight[index[i]]
            w = W
            condition = False
    return x 


x = greedyKnapsack(value,weight,n, ratio,15)
print(x)

np.multiply(x,value)
np.round(np.sum(np.multiply(x,value)),2)

np.sum(np.multiply(x,weight))
value = [30,40,45,77,90]
weight = [5,10]

def greedyKP(v,w,W):
    n=len(v)
    ratio = np.divide(v,w)
    index = np.flip(np.argsort(ratio))
    x = []
    for i in range(n):
        x.append(0)
    weight = 0
    for i in range(n):
        if (W > (weight + w[index[i]])):
            x[index[i]] = 1
            weight += w[index[i]]
        else:
            x[index[i]] = (W - w)/w[index[i]]
            weight = W
            break
        maxProfit = np.round(np.sum(np.multiply(x,v)))
        maxWeight = np.round(np.sum(np.multiply(x,w)))
        return maxProfit, maxWeight
    
v=[25,20,15,40,50]
w=[3,2,1,4,5]
W=6
profit,weight = greedyKP(v,w,W)
print(profit,weight)