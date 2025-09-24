
a = 1
b = 2
total = 2

while True: 
	c = a+b 
	if c > 4000000:
		break
	if c%2==0:
			total = total + c
	a = b
	b = c

print (total)
 
		 


