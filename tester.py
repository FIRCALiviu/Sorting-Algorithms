import os
algorithms=['bubblesort.out',
'countsort.out',
'mergesort.out',
'quicksort_median.out',
'quicksort_partition.out',
'radix_sort.out',
'result.out',
'shellsort.out']
test_size=[10**3,10**6,10**8]
sizes=[10**3,10**6,10**8]
for algorithm in algorithms: 
    for i in range(1,4):
        for j in range(1,4):
            os.system("time timeout 120s {}".format(algorithm))