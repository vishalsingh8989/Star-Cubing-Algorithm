import matplotlib.pyplot as plt
import numpy as np
import os, time

print(os.listdir(os.getcwd()))

fin = open('result.txt' , 'r')
x = []
y = []
cardinality = 10
lines = fin.readlines()
for line in lines:
    l = line.split()
    x.append(int(l[2]))
    y.append(int(l[3]))
    cardinality = l[1]


### one plot


fig = plt.figure(num=None, figsize=(10, 10), dpi=360, facecolor='w', edgecolor='k')

# fig.subplots_adjust(bottom=0.2)

linecos1 = plt.plot(x, y, 'bo--', label='Star Cubing algorithm')

plt.xlabel("Min support")
plt.ylabel("Time (seconds) ")

x_limit = max(x) + 5
plt.xlim(0,x_limit)
interval = x_limit/20.0
plt.xticks(np.arange(0, x_limit, 2), rotation=20)
plt.yticks(np.arange(0, max(y), 50))
plt.minorticks_on()
plt.legend()
plt.grid()

### stop second plot

#print(x_vals)
#print(y_vals)

plt.figtext(0.10, 0.040, "Figure 1 : Iceberg Cube Computation.Min_sup vs Time taken graph. Tuples  = 1M , Cardinality = {0}, Dimensions : 4".format(cardinality), horizontalalignment='left')


stamp = "_".join(time.asctime().split())
file_name = "starcube_"+os.path.basename(__file__).replace(".py" , "_")+"_"+stamp+".png"
#plt.show()
plt.savefig(file_name)



