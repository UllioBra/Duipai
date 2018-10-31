from graphviz import Digraph
import sys

n = int(input("Start : \n"))

dot = Digraph("P2634")
arr = [0 for i in range(n+1)]

for i in range(n-1):
    a,b,c = map(str,input().split())
    if not arr[int(a)]:
        arr[int(a)] = 1  
        dot.node(a)
    if not arr[int(b)]:
        arr[int(b)] = 1
        dot.node(b)
    dot.edge(a,b,str(int(c)%3))

dot.render("P2634.dot",view = True)