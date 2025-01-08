def main(arr):
    n = len(arr)
    m = max(arr)
    s = sum(arr)
    #print(n,m,s)
    #print(-(s//(-(n-1))))
    need = -(s//(-(n-1)))*(n-1) -s
    #print(need)
    need += max(m*(n-1)-(s+need),0)
    return need

if __name__ == '__main__':
    print(main([3,2,2]))
    print(main([6,4,4,4]))
    print(main([5,0,0]))
    print(main([1,0,0,100,0]))


