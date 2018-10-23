from cyaron import *
n = randint(1,30)
m = randint(1,1000)
print(n,m)
gra = Graph.graph(n,m,weight_limit=(1,100),directed=True)
print(gra)