import os 
source=['bubblesort',
'countsort',
'mergesort',
'quicksort_median',
'quicksort_partition',
'radix_sort',
'shellsort',
'verify']
for code in source:
    
    os.system("g++ {}.cpp -o {}.out".format(code,code))