import os 
source=['bubblesort',
'countsort',
'mergesort',
'quicksort_median',
'quicksort_partition',
'radix_sort_16',
'shellsort',
'verify',
"radix_sort_65536",
'STLsort']
for code in source:
    
    os.system("g++ {}.cpp -o {}.out".format(code,code))