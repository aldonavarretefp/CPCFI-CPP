noBalloons = int(input())
heights = input().split()
heights = list(map(int, heights))
c = [0] * (noBalloons+1)
for i in heights:
    c[i-1] += 1 
    if c[i] != 0:
        c[i] -= 1
noArrows = sum(c)
print(noArrows)