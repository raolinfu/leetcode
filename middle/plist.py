#!/usr/bin/python3
import gdb

def pp(p ):
    print("hello")
    print("hello: " + p['ch'])
    while p is not None:
        print("world")
        ch = p['ch']
        print('ch: ' + ch)
        next = p['next']
        print("world")
        for n in next:
            if n:
                pp(n)
class Move(gdb.Command):
    def __init__(self):
        super(self.__class__, self).__init__("mv", gdb.COMMAND_USER)

    def invoke(self, args, from_tty):
        argv = gdb.string_to_argv(args)
        p = gdb.parse_and_eval(argv[0])
        ptr = p.dereference()
        ptr['ch']
        pp(p)


Move()
