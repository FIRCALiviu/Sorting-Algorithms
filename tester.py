import subprocess,time
algorithms=['./bubblesort.out',
'./countsort.out',
'./mergesort.out',
'./quicksort_median.out',
'./quicksort_partition.out',
'./radix_sort_16.out',
'./shellsort.out',
'./radix_sort_65536.out',
'./STLsort.out']
test_size=[10**3,10**6,10**8]
sizes=[10**3,10**6,10**8]
file=open("results.txt",'w')
for algorithm in algorithms: 
    file.write(algorithm+'\n')
    for i in range(9):
        try:
            
            if (i//3)==0:
                subprocess.run([algorithm,"test_set{}.in".format(i+1)] ,shell=False,timeout=200) # we run the program twice on small training set in order to counter lru cache bias
            t1=time.perf_counter()
            subprocess.run([algorithm,"test_set{}.in".format(i+1)] ,shell=False,timeout=200)
            t2=time.perf_counter()
            verify=subprocess.run('./verify.out').returncode
            if verify!=0:
                file.write("maxsize={} test_size={} failure\n".format(sizes[i%3],test_size[i//3]))
            else:
                file.write("maxsize={} test_size={} {} seconds\n".format(sizes[i%3],test_size[i//3],t2-t1))
        except subprocess.TimeoutExpired:
            file.write("maxsize={} test_size={} timeout\n".format(sizes[i%3],test_size[i//3]))

