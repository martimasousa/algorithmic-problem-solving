import sys
from pulp import LpProblem, LpMaximize, LpVariable, value, GLPK

data = sys.stdin.readline()
first_line = list(map(int, data.split()))

prob = LpProblem("MaximizeProfit", LpMaximize)

main_expression = 0
n_toys = 0

is_constraint = {}

toys = {}
for i_toy in range(first_line[0]):
    line = sys.stdin.readline()

    toy = list(map(int, line.split()))
    toy.append(LpVariable("Toy" + str(i_toy), lowBound=0, upBound=toy[1], cat='Integer'))

    toys[i_toy] = toy

    main_expression += toy[0]*toy[2]
    n_toys += toy[2]

    is_constraint[i_toy] = 0

packages = {}
for i_package in range(first_line[1]):
    line = sys.stdin.readline()

    package = list(map(int, line.split()))

    min_upbound = toys[package[0] - 1][1]
    for toy_i in range(3):
        if toys[package[toy_i] - 1][1] < min_upbound:
            min_upbound = toys[package[toy_i] - 1][1]

    package.append(LpVariable("Package" + str(i_package), lowBound=0, upBound=min_upbound, cat='Integer'))

    packages[i_package] = package

    main_expression += package[3]*package[4]
    n_toys += 3*package[4]

    for toy_i in range(3):
        toys[package[toy_i] - 1][2] = toys[package[toy_i] - 1][2] + package[4]
        is_constraint[package[toy_i] - 1] = 1

prob += main_expression
prob += n_toys <= first_line[2] # Max toys in 1 day

for toy_i in range(first_line[0]):
    if is_constraint[toy_i] == 1:
        prob += toys[toy_i][2] <= toys[toy_i][1] # Max for each toy

prob.solve(GLPK(msg=False))

print(int(value(prob.objective)))