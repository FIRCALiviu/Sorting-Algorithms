import numpy as np
tests=[ open("test_set1.in","w") , open("test_set2.in","w")   ,open("test_set3.in","w")   ,open("test_set4.in","w"), open("test_set5.in","w"), open("test_set6.in","w"), open("test_set7.in","w"), open("test_set8.in","w"), open("test_set9.in","w")]
test_size=[10**3,10**6,10**8]
sizes=[10**3,10**6,10**8]
test_num=0
for array_size in test_size:
    for size in sizes:
        data=np.random.randint(0,size,array_size)
        for num in data:
            tests[test_num].write(hex(num)+' ') # outputing the values in hex so it uses less space
        tests[test_num].close()
        test_num+=1
        
