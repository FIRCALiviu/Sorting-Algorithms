import matplotlib.pyplot as plt
data=open("results.txt","r")
algorithms=data.read().split("./")
del algorithms[0]
fig, plots=plt.subplots(nrows=3,ncols=1)
sizes=[10**3,10**6,10**8]

for i,size in enumerate(sizes):
   
    for algorithm in algorithms:
        
        lines=algorithm.splitlines()
        name=lines[0]
        del lines[0]
        dataX=[]
        dataY=[]
        for line in lines:
            words=line.split()
            maxsize=int(words[0].split('=')[1])
            array_size=int(words[1].split("=")[1])
            if words[2]=='timeout':
                time=float(500) # we cap the data at 500
            else:
                time=float(words[2])
            if maxsize==size:
                dataX.append(array_size)
                dataY.append(time)
            else:
                continue
        

