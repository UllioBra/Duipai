from cyaron import *
n = randint(100000,100000)
tre = Graph.tree(n)
print(n)
for i in tre.iterate_edges():
    print(i.start,i.end)