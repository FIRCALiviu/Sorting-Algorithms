import numpy.random as np
test=open("test_set.in","w")
array=np.randint(0,10**7,2*10**7)
for integer in array:
    test.write("{} ".format(integer))
test.close()