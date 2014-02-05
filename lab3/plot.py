import numpy as np;
import matplotlib.pyplot as plt

data1 = np.genfromtxt("out1.txt",delimiter=' ',names=['x','y']);
data2 = np.genfromtxt("out2.txt",delimiter=' ',names=['x','y']);
data3 = np.genfromtxt("out3.txt",delimiter=' ',names=['x','y']);
data4 = np.genfromtxt("out4.txt",delimiter=' ',names=['x','y']);

fig = plt.figure();
ax1 = fig.add_subplot(111)

p1= ax1.plot(data1['x'],data1['y'],label="0.1");
p2 = ax1.plot(data2['x'],data2['y'],label="0.2");
p3 = ax1.plot(data3['x'],data3['y'],label="0.3");
p4 =ax1.plot(data4['x'],data4['y'],label="0.4");
#ax1.legend([p1,p2,p3,p4],[ "0.1","0.2","0.3","0.4"])
ax1.legend(bbox_to_anchor=(1.05, 1), loc="top", borderaxespad=0.)

plt.show()
