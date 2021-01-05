
test = int(input())
while(test>0):
    inp = input()
    n = inp.split(' ')[0]
    m = inp.split(' ')[1]
    n = n[::-1]; m = m[::-1]
    ans = int(n)+int(m)
    ans = ans+0
    ans = str(ans)[::-1]
    while(ans[0]=='0'):
        ans = ans[1::]
    print(ans)
    test-=1

