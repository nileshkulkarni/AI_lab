def truthTableNor(n):   
    x = 0;
    class1 = list()
    class0 = list()
    
    for i in range(pow(2,n)):
        vect = list()
        or1 = 0
        for j in range(n):
            temp = (i>>j)%2
            or1 = or1 or temp   
            vect.extend([temp])     
        if or1>0:
            class0.append(vect) 
        else:
            class1.append(vect)
    
    return (class1,class0)

def palindrome(n):
    if( ((n>>4) % 2) == ((n) % 2)):
        if( ((n>>3) % 2) == ((n>>1) % 2)):
            return True
    return False
             
    

def truthTableParity(n):    
    x = 0;
    class1 = list()
    class0 = list()
    
    for i in range(pow(2,n)):
        vect = list()
        maj =0;
        for j in range(n):
            temp = (i>>j)%2
            if(temp>0):
                maj = maj +1
            vect.extend([temp])     
        if maj%2 == 0:
            class1.append(vect) 
        else:
            class0.append(vect)
    
    return (class1,class0)
    

def truthTableMaj(n):   
    x = 0;
    class1 = list()
    class0 = list()
    
    for i in range(pow(2,n)):
        vect = list()
        maj =0;
        for j in range(n):
            temp = (i>>j)%2
            if(temp>0):
                maj = maj +1
            vect.extend([temp])     
        if maj>(n/2):
            class1.append(vect) 
        else:
            class0.append(vect)
    
    return (class1,class0)
    

def xor(a,b):
    return ( a and not b) or (not a and b)

def truthTablePal(n):   
    x = 0;
    class1 = list()
    class0 = list()
    
    for i in range(pow(2,n)):
        vect = list()
        or1 = palindrome(i)
        for j in range(n):
            temp = (i>>j)%2
            vect.extend([temp])     
        if or1>0:
            class1.append(vect) 
        else:
            class0.append(vect)
    
    return (class1,class0)

def truthTableXor(n):   
    x = 0;
    class1 = list()
    class0 = list()
    
    for i in range(pow(2,n)):
        vect = list()
        or1 = 0
        for j in range(n):
            temp = (i>>j)%2
            or1 = xor(or1,temp) 
            vect.extend([temp])     
        if or1>0:
            class1.append(vect) 
        else:
            class0.append(vect)
    
    return (class1,class0)

def truthTableNand(n):  
    x = 0;
    class1 = list()
    class0 = list()
    
    for i in range(pow(2,n)):
        vect = list()
        or1 = 1
        for j in range(n):
            temp = (i>>j)%2
            or1 = or1 and temp  
            vect.extend([temp])     
        if or1>0:
            class0.append(vect) 
        else:
            class1.append(vect)
    
    return (class1,class0)

def truthTable(n,op):
    if op == "nor":
        truthTableNor(n);
    elif op == "nand":
        truthTableNand(n);
    elif op == "xor":
        truthTableXor(n);
    


def check(ind,w):
    leng = len(ind)
    sum =0; 
    for i in range(leng):
        sum = sum + ind[i]*w[i] 
    if sum > 0:
        return True;
    else:   
        return False;



def solve(input1,w):
    startCheck =0;
    maxSize = len(input1)
    cycleMap = list()
    
    while True:
        if(check(input1[startCheck],w)):
            startCheck=startCheck+1 
        else:
            for i in range(len(w)):
                w[i] = w[i]+ input1[startCheck][i]
            
            print w;
            if(w  in cycleMap):
                print "Cycle Detected"
                print "Repetition Rate " + str(len(cycleMap))
                return
            startCheck = 0;  
    
            cycleMap.append([x for x in w]);
        if(startCheck >= maxSize):
            break;
    print w;    
    return; 
    
def negate(input1):
    outp = list()
    for i in input1:
        outp.extend([-i])
    
    return outp


def PTA_weights(class1,class0):
    numrows1 = len(class1)
    numcols1 = 0
    if(numrows1>0): 
        numcols1 = len(class1[0])       
    
    numrows0 = len(class0)
    numcols0 = 0
    if (numrows0>0): 
        numcols0 = len(class0[0])       
    
    for i in range(numrows1):
        class1[i].extend([ -1])
            
        
    for j in range(numrows0):
        class0[j].extend([ -1])
        

    
    if (numcols1 != numcols0):
        print(" Error inputs for class1 and class0 not compatible\n")       
    else:
        w = list()
        input1 = list()
        for i in range(numrows1):
            input1.append(class1[i]);
        
        for j in range(numrows0):
            input1.append(negate(class0[j]));
        
        for i in range(numcols1+1):
            w.extend([0])
        solve(input1,w)

l = truthTableXor(2)
PTA_weights(l[0],l[1])



