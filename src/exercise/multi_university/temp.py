with open('data.txt', 'w') as f:
    f.write('10\n')
    for i in range(1, 11):
        f.write('100000\n')
        for j in range(100000):
            f.write(f'{i} {i}\n')


with open('data2.txt', 'w') as f:
    f.write('10\n')
    for i in range(1, 11):
        f.write('100000\n')
        for j in range(100000):
            f.write(f'{j} {j+1}\n')