import diagram_calculator
import numpy as np

x = diagram_calculator.DiagramCalculator(1)

m = x.get_matrix()
v = x.view_matrix()
c = x.copy_matrix()
print(m.flags,  '\n', v.flags, '\n', c.flags)
c[0, 0] = 1
print(m)
print(v)
print(c)

a = np.zeros((10, ))
b = x.modify_matrix(a)
print(b)
print(b.flags)
