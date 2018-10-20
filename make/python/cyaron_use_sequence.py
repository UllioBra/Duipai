from cyaron import *
Sequence(lambda i, f: 2*i+1) # f(i)=2*i+1
Sequence(lambda i, f: f(i-1) + 1, [0, 1]) # f(i)=f(i-1)+1, f(0)=0, f(1)=1
Sequence(lambda i, f: f(i-1) + 1, {100: 101, 102: 103}) # f(i)=f(i-1)+1, f(100)=101, f(102)=103