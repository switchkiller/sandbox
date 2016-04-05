__name__ = 'helper'
__all__  = ['read_int', 'read_float', 'read_list_of_str', 'read_list_of_int', 'read_list_of_float']

#'file' is an open file object.

def read_int(file):
	return int(file.readline())

def read_float(file):
	return float(file.readline())

def read_list_of_str(file):
	return file.readline().split()

def read_list_of_int(file):
	return list(map(int, read_list_of_str(file)))

def read_list_of_float(file):
	return list(map(float, read_list_of_str(file)))

def is_odd(num):
	return num & 1 == 1

def is_even(num):
	return not (num & 1 == 1)  