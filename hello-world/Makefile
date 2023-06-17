# As explained in the `all` target, this variable is read by a Makefile
# so that it 'knows' what module needs to be compiled.
obj-m += hello_world.o

all:
	@# Move into /lib/modules/$(shell uname -r)/build before doing
	@# anything else. That way we compile the module 'in-tree'. Within
	@# there we'll make the `modules` target already defined in the
	@# Makefile on that repository. We also leverage the `M` option
	@# passed to that Makefile so that the module is dropped into
	@# the current directory as pointed by the `PWD` variable.
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	@# The idea is the same as above: we're just cleaning stuff now!
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
