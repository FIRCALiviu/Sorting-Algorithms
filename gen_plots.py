import matplotlib.pyplot as plt
data=open("results.txt","r")
algorithms=data.read().split("./")
del algorithms[0]

size=10**8
colors=[
'b' ,
'g' ,
'r' ,
'c' ,
'm' ,
'y' ,
'k' ,

'tab:orange',
'tab:pink'
]

for j,algorithm in enumerate(algorithms):
    
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
    plt.plot(dataX,dataY,color=colors[j],label=name,linewidth=2)
plt.title("max size={}".format(size))    
plt.legend()
plt.yscale('log') 
plt.xscale('log')       
plt.show()
