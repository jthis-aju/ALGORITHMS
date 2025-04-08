n = int(input())
l = list(map(int,input().split()))
m = 0
for i in range(n):
    g = -99999999999999999999999999999
    x = 0
    for j in range(i-1,-1,-1):
        if (l[i]-l[j])/(j-i)>g:
            g = (l[i]-l[j])/(j-i)
            x+=1
    g = -99999999999999999999999999999
    for j in range(i+1,n):
        if (l[i]-l[j])/(i-j)>g:
            g = (l[i]-l[j])/(i-j)
            x+=1
    m = max(m,x)
print(m)
