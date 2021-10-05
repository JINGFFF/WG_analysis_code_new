import os
import sys
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

path = sys.argv[1]

files = os.listdir(path)
print(files)
df1 = pd.read_csv(path + '/' + files[0], header=None)
print(df1)
for file in files[1:]:
  df2 = pd.read_csv(path +'/' +  file,header=None)
  df1 = pd.concat([df1,df2],axis=0,ignore_index=True)

plt.matshow(df1.corr())
#plt.imshow(df1.corr())
plt.colorbar()
plt.show()
