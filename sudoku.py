a=[
   [3, 0, 6, 5, 0, 8, 4, 0, 0],
   [5, 2, 0, 0, 0, 0, 0, 0, 0],
   [0, 8, 7, 0, 0, 0, 0, 3, 1],
   [0, 0, 3, 0, 1, 0, 0, 8, 0], 
   [9, 0, 0, 8, 6, 3, 0, 0, 5],
   [0, 5, 0, 0, 9, 0, 6, 0, 0],
   [1, 3, 0, 0, 0, 0, 2, 5, 0],
   [0, 0, 0, 0, 0, 0, 0, 7, 4],
   [0, 0, 5, 2, 0, 6, 3, 0, 0]
]
def place(i,j,number):
	for q in range(0,9):
		if(q!=i):
			if(a[q][j]==number):
				return False
	for q in range(0,9):
		if(q!=j):
			if(a[i][q]==number):
				return False
	if(i<3 and j<3):
		for q in range(3):
			for w in range(3):
				if(a[q][w]==number):
					return False
	if(i<3 and j<6 and j>=3):
		for q in range(3):
			for w in range(3,6):
				if(a[q][w]==number):
					return False
	if(i<3 and j<9 and j>=6):
		for q in range(3):
			for w in range(6,9):
				if(a[q][w]==number):
					return False

	if(i<6 and i>=3 and j<3):
		for q in range(3,6):
			for w in range(3):
				if(a[q][w]==number):
					return False
	if(i<6 and i>=3 and j<6 and j>=3):
		for q in range(3,6):
			for w in range(3,6):
				if(a[q][w]==number):
					return False
	if(i<6 and i>=3 and j<9 and j>=6):
		for q in range(3,6):
			for w in range(6,9):
				if(a[q][w]==number):
					return False

	if(i<9 and i>=6 and j<3):
		for q in range(6,9):
			for w in range(3):
				if(a[q][w]==number):
					return False
	if(i<9 and i>=6 and j<6 and j>=3):
		for q in range(6,9):
			for w in range(3,6):
				if(a[q][w]==number):
					return False
	if(i<9 and i>=6 and j<9 and j>=6):
		for q in range(6,9):
			for w in range(6,9):
				if(a[q][w]==number):
					return False
	return True
def display():
	for i in range(0,9):
		for j in range(0,9):
			print(a[i][j],end=" ")
		print()
def solve():
	sf=0
	number=1
	placed=False
	for i in range(0,9):
		for j in range(0,9):
			if(a[i][j]==0):
				while(placed==False and number<10 and number>0):
					flag=place(i,j,number)
					if(flag==True):
						a[i][j]=number
						placed=True
						ans=solve()
						if(ans==1):
							placed=False
							number+=1
						else:
							placed=True
							return 0
					else:
						number+=1
				a[i][j]=0
				return 1
	return 0
solve()
display()
# def test():
# 	a[8][8]=100000000
# test()