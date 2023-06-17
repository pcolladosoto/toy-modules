# The Hello World Driver
This directory contains a bare-bones module that's been basically
lifted as-is from [this article](https://medium.com/dvt-engineering/how-to-write-your-first-linux-kernel-module-cf284408beeb).

The idea is having a bare-bones and no-frills driver letting us check whether
we've a correct setup and we can get things off the ground.

Bear in mind this module has been show to work for kernel `5.14.0` running on AlmaLinux 9:

    $ uname -r
    5.14.0-284.11.1.el9_2.x86_64

If you try to use any other version you might need to tweak some things here and there...

## Compiling
Provided you've got all the needed dependencies, compiling the module is as easy as running:

    $ make

Should that not work, refer to the root `README.md` for info on how to set things up.

If you want to remove the generated artifacts you can leverage the `clean` target:

    $ make clean

If you dig inside the `Makefile` you'll find some comments on how and why such a simple
Makefile actually works. Again, this Makefile has been basically lifted from the
aforementioned article verbatim.

## Using it
After compiling the module you can just insert (i.e. load) it into the kernel by
running the following from **this directory**:

    # insmod hello_world.ko

Once that's done, `/proc/hwdrive` will be created and you can `cat` it:

    $ cat /proc/hwdrive
    Hello world!

You can also check the module's been loaded correctly:

    $ lsmod | grep hello_world

When done, you can just remove it with:

    # rmmod hello_world

Now, that's cool isn't it?
