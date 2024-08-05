import math

a, b, c, r = [int(x) for x in input().split()]


def calc(a, b, c, r):
    sita = math.acos((a * a + b * b - c * c) / (2 * a * b)) / 2
    x = r / math.tan(sita)
    area = x * r - (math.pi - 2 * sita) / 2 * r * r
    return area


sita = math.acos((a * a + b * b - c * c) / (2 * a * b))
tri_area = 1 / 2 * a * b * math.sin(sita)

print((tri_area - (calc(a, b, c, r) + calc(b, c, a, r) + calc(c, a, b, r))) / tri_area)
