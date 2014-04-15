
class Perceptron:

	W =list()
	
	def __init__(self):
	

	def train(self,n):
							
	
	def generateTable(self,n):
		
				
	def check(self,ind,w):
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
			cycleMap.append([x for x in w]);
			if(check(input1[startCheck],w)):
				startCheck=startCheck+1	
			else:
				for i in range(len(w)):
					w[i] = w[i]+ input1[startCheck][i]
				if(w  in cycleMap):
					print "Cycle Detected"
						print "Repetition Rate " + str(len(cycleMap))
				return
				startCheck = 0;	 
		
			if(startCheck >= maxSize):
					break;
		print w	
		return;	
		

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
	
def truthTableDigit(n):
	x =0;
	
	



	
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

l = truthTableDigit(0)
PTA_weights(l[0],l[1])



