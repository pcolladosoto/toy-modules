# Toy Linux Modules
Getting into kernel programming is no easy task. When working **within** the kernel things
change and the solid ground you once thought you had is no longer there: you are **in** said
ground!

This repository contains some toy kernel modules we wrote to practice our C-fu and get acquainted
with how things work within the kernel.

Each module comes with its own `README.md` discussing stuff such as what it's for, how to compile
it and such.

## Documentation
This endeavour was motivated by the superb article written by [Ruan de Bruyn](https://medium.com/@bruynrd)
on Medium. You can find it [here](https://medium.com/dvt-engineering/how-to-write-your-first-linux-kernel-module-cf284408beeb).

We've taken his example and added some 'sugar' on top to get used to how things work when there's
no more `printf()` available for you...

You can also refer to [Kernel Newbies](https://kernelnewbies.org) for a ton of information on working
with the kernel and such. Bear in mind, however, that these modules can be compiled **outside** the kernel
and then inserted though commands such as [`insmod(8)`](https://www.man7.org/linux/man-pages/man8/insmod.8.html).
You can also rely on [`rmmod(8)`](https://www.man7.org/linux/man-pages/man8/rmmod.8.html) to get them out and
on goodies such as [`lsmod(8)`](https://www.man7.org/linux/man-pages/man8/lsmod.8.html) to get a view of what's
currently loaded.

## What do we need?
We'll be basically compiling C programs importing the kernel's headers. We need a collection of tools for
doing so. As we'll be developing on a machine running [Almalinux](https://almalinux.org) we'll install
everything with `yum`, but you can use the package manager of your choice. Bear in mind you might need to
alter the names a bit...

Before doing anything else we **must** update all our packages. That way we make sure we're on the
last possible kernel and that auxiliary packages (such as `kernel-devel`)

    # yum update

Once that's done it's time to get the rest of stuff. The following gives some (non comprehensive)
information on what each package accomplishes.

- `gcc`:             The GNU Compiler Collection (i.e. the compiler).

- `make`:            A tool allowing us to leverage Makefiles for automating compilations.

- `build-essential`: General goodies needed for building software.

- `kernel-devel`:    Let's pull all the dependencies for actually building stuff for the
                     kernel (i.e. modules). This dependency will also install any needed
                     dependencies such as the `kernel-headers` package!

        # yum install gcc make build-essential kernel-devel


## Conventions
Throughout the different `README.md`s we'll be working with a ton of commands and such. We'll
assume a dollar sign prompt (i.e. `$`) means the commands can be executed by a regular user
whilst commands whose prompt is an octothorpe (i.e. `#`) need to be executed by `root` either
directly or through `sudo`. For instance, both invocations of `yum` above need to be done as
`root`, hence the leading `#`.

## On Vagrant
Given we work on a machine running macOS we leverage VMs for developing these modules. Instead
of launching full-fledge graphical environments we prefer to use more bare-bones machines and
[Vagrant](https://www.vagrantup.com) fills that spot perfectly.

If you [install Vagrant](https://developer.hashicorp.com/vagrant/downloads?product_intent=vagrant)
and run the following from this directory you should get your own machine up and running:

    $ vagrant up

For any more information please refer to the wonderful [documentation](https://developer.hashicorp.com/vagrant/docs)
maintained by the Vagrant team.
