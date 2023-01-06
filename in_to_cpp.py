import argparse

parser = argparse.ArgumentParser()
parser.add_argument('input')
parser.add_argument('output')
args = parser.parse_args()
with open(args.input) as file:
	data = file.readlines()

out = ''

for line in data:
	s = line.split()
	out += "wc."
	out += s[0]
	out += "("
	if s[0] == "add_player":
		# print(len(s), s[3])
		out += s[1] + "," + s[2] + ","
		out += 'permutation_t::read("' + s[3] + '"),'
		out += s[4] + ',' + s[5] + ',' + s[6] + ',' + s[7]
	else:
		for argument in s[1:-1]:
			out += argument + ","
		out += s[-1]
	out += ");\n"

with open(args.output, 'w') as file:
	file.write(out)