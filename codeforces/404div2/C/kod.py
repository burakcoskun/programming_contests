import math
r = input();
n = r.split(" ")[0]
m = r.split(" ")[1]

a = - 1
b = -1
c = 2*int(n) - 2*int(m)

if int(m) < int(n) :
	r1  = math.ceil((-1*b-math.sqrt(b*b-4*a*c))/2*a) + int(m);
	print(r1)
else: 
	print(n)

#print(r1)
#print(r2)
#if r1 < 0 :
#	print(r2)
#elif r2 < 0 :
#	print(r1) 
#else: 
#	print(min(r1,r2))

#print (math.ceil((-1*b-math.sqrt(b*b-4*a*c))/2*a))