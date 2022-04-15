n = int(input())
p = list(map(int, input().split()))

p.sort()

t = 0
for c, i in enumerate(p):
    t += i * (len(p) - c)

print(t)