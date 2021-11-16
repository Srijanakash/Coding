# cook your dish here
if __name__ == '__main__':
    t = int(input())
    while t>0:
        t = t - 1
        input_list = input().split()
        x = int(input_list[0])
        y = int(input_list[1])
        if x % 2 != 0:
            print("NO")
        else:
            if x == 0:
                if y % 2 == 0:
                    print("YES")
                else:
                    print("NO")
            else:
                print("YES")
