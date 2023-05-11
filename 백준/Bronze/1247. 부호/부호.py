for i in range(3):
    n = int(input())
    acc = 0
    for j in range(n):
        acc += int(input())
    print("+" if acc > 0 else "-" if acc < 0 else "0")