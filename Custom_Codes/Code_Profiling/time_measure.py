import time

def get_number(x):
	for i in range (0,x):
		return i*i*i

def range_valuate(x):
	for p in range (0,x):
		q = get_number(p)

start = time.time()
range_valuate(10000)
end = time.time()

print ("\nThe function takes %0.2f seconds" % (end-start))

