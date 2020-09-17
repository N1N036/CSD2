import time as t

s = t.time()

for i in range(0,1000000):
    print(t.time()-s)
    print(t.time())

