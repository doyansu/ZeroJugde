def getC(l,frist):#法2參考024-1 較久...
    if l==1 or frist==9:
        return 1
    else:
        return getC(l,frist+1)+getC(l-1,frist)

def getList(n):
    list1=[[1,1,1,1,1,1,1,1,1]]
    list2=[1,]
    for i in range(0,n-1):
        list2=[1,]
        for j in range(0,8):
            list2.append(list1[i][j+1]+list2[j])
        list1.append(list2)
        list2=[1,]
    return list1

def turnToList(listn,a,b):
    return listn[a-1][9-b]

def getT(n,listT):
    Sum=0
    for i in range(1,10):
        Sum=Sum+turnToList(listT,n,i)
    return Sum

def add(N):
    for i in range(1,len(N)+1):
        if N[-i]!='9':
            N=N[0:-i]+str(int(N[-i])+1)+'0'*(i-1)
            return N
    n='1'+'0'*(len(N))
    return n
            
def main():
    try:
        while True:
            Sum=0
            listT=[]
            N=add(input())
            listT=getList(len(N))
            for i in range(1,len(N)):
                Sum=(Sum+getT(i,listT))%1000000007
            for i in range(1,int(N[0])):
                Sum=(Sum+turnToList(listT,len(N),i))%1000000007 
            for i in range(0,len(N)-1):
                if N[i]>N[i+1]:
                    break
                elif N[i+1]>N[i]:
                    for j in range(int(N[i]),int(N[i+1])):
                        Sum=(Sum+turnToList(listT,len(N)-i-1,j))%1000000007
            print(Sum)  
    except EOFError:
        pass
        
main()
