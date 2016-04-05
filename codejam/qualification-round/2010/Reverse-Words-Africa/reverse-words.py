import sys

from helper import read_int, read_list_of_str

def main(filename=None):
	if filename is None:
		if len(sys.argv) == 2:
			filename = sys.argv[1]
		else:
			print("Usage: reverse-words input_file")
			return 1

	# XXX using [ with open(_) as f ]will create a scope of f within its body
	fout = open("ans.out", 'w+')
	with open(filename, "r") as f:
		num_cases = read_int(f)
		#enumerate from position 1 because 0 has N
		for i, line in enumerate(f,1): 
			print (line	)
			words = read_list_of_str(f)
		
			words.reverse()
			#print ("Case #" + str(i) + ": " + " ".join(words))
			fout.write("Case #" + str(i) + ": " + " ".join(words) + "\n")
	fout.close()
	return 0

if __name__ == "__main__":
	status = main()
	sys.exit(status)
