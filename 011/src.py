import os

d = '.'
array2D = []

for filename in os.listdir(d):
    if not filename.endswith('.txt'):
        continue

    with open(filename, 'r') as f:
        for line in f.readlines():
            l = line.strip().split(' ')
            array2D.append([eval(i) for i in [s.lstrip("0") for s in l]])

print(array2D)