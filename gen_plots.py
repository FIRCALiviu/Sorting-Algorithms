import matplotlib.pyplot as plt
data=open("results.txt","r")
algorithms=data.read().split("./")
del algorithms[0]
fig=plt.figure()
image=fig.add_subplot(1,1,1)
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
    image.plot(dataX,dataY,color=colors[j],label=name,linewidth=1.3)
image.set_title("Max integer size={}".format(size))    
image.legend()
image.set_yscale('log') 
image.set_xscale('log')
image.set_xlabel("array size")
image.set_ylabel("time to sort (seconds)")       
fig.set_size_inches(20, 11, forward=True)
plt.show()
