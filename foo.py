import subprocess,time
try:
    t1=time.perf_counter()
    subprocess.run("timeout 10s ./mergesort.out {}".format("test_set1.in"),shell=True,timeout=1)
    t2=time.perf_counter()
    p=subprocess.run("./verify.out").returncode
    if p==0:
        print(p)
    
    print(t2-t1)
except subprocess.TimeoutExpired:
    print("code timed out!")