import pymer.timestamp as ts  
import time

start = ts.timestamp()
time.sleep(1)
end = ts.timestamp()
print(end - start)

start = ts.timestamp()
a = 2
b = 3
c = a + b
end = ts.timestamp()
print(end - start)
