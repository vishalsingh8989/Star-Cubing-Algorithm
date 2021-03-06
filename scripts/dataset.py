import random
import time
import sys
import os


ROOT = "/Users/vishaljasrotia/eclipse-workspace/star_cubing_algorithm"
INPUT = "input"
csv_path = os.path.join(ROOT, INPUT)


attribute = ["a" , "b" , "c" , "d"]

print("argc : " , sys.argv)
nums_tuple = 10
cardinality = 10
if len(sys.argv) > 1:
    nums_tuple = int(sys.argv[1])
    cardinality = int(sys.argv[2])

table = []
for i in xrange(4):
    temp = []
    card = random.randint(cardinality-cardinality/3,cardinality)
    for j in xrange(1, card + 1):
           temp.append(attribute[i] + str(j))
    table.append(temp[:])
print(table)

file_name = os.path.join(csv_path, "sample_"+str(nums_tuple)+"_"+str(cardinality)+"_.csv")
print("file_name  :" , file_name)

with  open(file_name, 'w') as f:
    f.write("A,B,C,D\n");
    for i in xrange(nums_tuple):
        t = ",".join([random.choice(table[0]) , random.choice(table[1]), random.choice(table[2]), random.choice(table[3])])
        f.write(t+"\n")
