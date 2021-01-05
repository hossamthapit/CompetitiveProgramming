
test = int(input())
while(test>0):
    inp = input().split(' ')
    n = inp[0][::-1]; m = inp[1][::-1]
    ans = int(n)+int(m)
    ans = str(ans)[::-1]
    while(ans[0]=='0'):
        ans = ans[1::]
    print(ans)
    test-=1

