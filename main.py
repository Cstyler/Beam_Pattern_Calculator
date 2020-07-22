import diagram_calculator

diagram_calculator.matrix_fun()

# Use the add function
print("1 + 2 = {}".format(diagram_calculator.add(1, 2)))

# Use the adder class
adder = diagram_calculator.Adder(3)
print("3 + 2 = {}".format(adder.add(2)))
adder.addition = 4
print("4 + 3 = {}".format(adder.add(2)))

# Use the join function that uses the stl
print("join(['a', 'b', 'c']) = {}".format(diagram_calculator.join(['a', 'b', 'c'])))
