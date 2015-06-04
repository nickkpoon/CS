def weather():
    file = 'weather.txt'
    f = open(file, 'r')
    L1 = ['January','Febuary','March','April','May','June','July','August','September','October','November','December']
    L2 = [0,0,0,0,0,0,0,0,0,0,0,0]
    for line in f:
        L = line.split()
        for x in range(0,12):
            if (L[0] == L1[x]):
                L2[x] += float(L[2])
    f.close()
    f = open('weather1.txt', 'w+')
    for i in range(0,12):
        f.write('%-12s%s\n' % (L1[i], L2[i]))

    f.close()
