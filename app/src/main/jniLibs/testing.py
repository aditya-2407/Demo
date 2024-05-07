import random

with open('matrix.txt', 'w') as f:
    for _ in range(100):
        row = [str(random.randint(0, 100)) for _ in range(100)]
        f.write(' '.join(row) + '\n')