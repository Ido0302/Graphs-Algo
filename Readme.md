# Exe2 - Graphs - Overload Operators

In that exercise we implements new functionality of operators but on graphs.

1. Arithmetic operator:

g1+g2: return new graph who the add of g1 and g2.
g1-g2: return new graph the sub of g2 from g1.
g1*g2: return new graph who contains new matrix which the multiplication of g1's matrix and g2's matrix.

g1+=g2: add g2 to g1.
g1-=g2: sub g2 from g1.
g1*=(int): multiply the weights of g1's edges. 

+g1: unary plus on weights of g1's edges.
-g1: unary minus on weights of g1's edges.

++g1/g1++: add 1 to weights of g1's edges (prefix/postfix).
--g1/g1--: sub 1 to weights of g1's edges (prefix/postfix).

2. Compare operator:
g1==g2: g1 equal g2 if there are with the same count of vertices, the same edges and the same edges's weights.
g1!=g2: g1 different g2 if there are not.

g1 < g2: return true if g1 completly contains in g2 g1 has least edges or g1 has least vertices.
g1<=g2: return true if g1 small or equal g2.

g1 > g2: return true if g2 smaller than g1.
g1>=g2: return true if g2 small or equal g1.

3. Output operator:
g1<<: print graph's adjacency matrix in format: "[0,...]\n...\n[...,0]"


