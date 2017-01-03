import cProfile, pstats, StringIO
pr = cProfile.Profile()
pr.enable()
def get_number(x):
    for i in range (0,x):
        return i*i*i

def range_valuate(x):
    for p in range (0,x):
        q = get_number(p)

range_valuate(10000)
pr.disable()
s = StringIO.StringIO()
sortby = 'cumulative'
ps = pstats.Stats(pr, stream=s).sort_stats(sortby)
ps.print_stats()
print s.getvalue()