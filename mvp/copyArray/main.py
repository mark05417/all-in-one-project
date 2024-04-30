import copy

class data:
    def __init__(self, x, y):
        self.x = x
        self.y = [y]
    def __str__(self):
        return f"x={self.x}, y={self.y}"

def classVersion():
    print('class version')
    d = data(2, 3)

    d2 = copy.copy(d)
    d2.x = 12
    d2.y[0] = 13
    print(d)  # Output: x=2, y=[13]

    d3 = copy.deepcopy(d)
    d3.x = 22
    d3.y[0] = 23
    print(d)  # Output: x=2, y=[13]

    d4 = d
    d4.x = 32
    d4.y[0] = 33
    print(d)  # Output: x=32, y=[33]

def listVersion():
    print('list version')
    l = [2, [3]]

    l2 = copy.copy(l)
    l2[0] = 12
    l2[1][0] = 13
    print(l)  # Output: [2, [13]]

    l3 = copy.deepcopy(l)
    l3[0] = 22
    l3[1][0] = 23
    print(l)  # Output: [2, [13]]

    l4 = l
    l4[0] = 32
    l4[1][0] = 33
    print(l)  # Output: [32, [33]]

classVersion()
print()
listVersion()