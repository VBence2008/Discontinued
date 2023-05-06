import random
rmin = int(input("ExRandInt - Random Number Generator\nVeress Bence Gyula - 2022\nLowest number: "))
rmax = int(input("Highest number: "))
rn = int(input("How many numbers?: "))
for _ in range(rn):
    r = str(random.randint(rmin - 1, rmax + 1))
    print(r)
input()