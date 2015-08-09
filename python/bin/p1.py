__author__ = "bond007"

def simple1(a, *args):
    print args
def simple2(*args):
    print args
def simple3(**kwargs):
    print kwargs
simple1(1,2,3)
simple2(1,2,3)
simple3(x=1,y=2)
