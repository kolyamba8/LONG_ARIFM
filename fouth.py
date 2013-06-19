import sys
import third
if len(sys.argv) < 5:
	print "INCORRECT INPUT"
	exit()
name_a = sys.argv[1]
z = sys.argv[2]
name_b = sys.argv[3]
name_res = sys.argv[4]
name_mod = 0
fl = 0;
if len(sys.argv) > 5:
	if sys.argv[5] == "-b":
		fl = 1;
		if len(sys.argv) > 6:
			name_mod = sys.argv[6]
	else:
		name_mod = sys.argv[5]

a = third.CSECOND(name_a,fl)
b = third.CSECOND(name_b,fl)

if z == "+":
	res = a + b
if z == "-":
	res = a - b
if z == "mul":
	res = a * b
if z == "/":
	res = a / b
if z == "^":
	res = a ^ b
if z == "%":
	res = a % b

if name_mod != 0:
	mod = third.CSECOND(name_mod,fl)
	res %= mod

if fl == 1:
	res.b_output(name_res)
else:
	res.output(name_res)

