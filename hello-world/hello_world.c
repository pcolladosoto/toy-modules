#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>

// Module metadata.
MODULE_AUTHOR("Ruan de Bruyn & Pablo Collado Soto");
MODULE_DESCRIPTION("Hello World Driver");
MODULE_LICENSE("GPL");

// Struct representing our module's entry under `/proc`. Bear in mind
// it's not really 'polite' to create entries under `/proc`: `sysfs`
// is preferred...
static struct proc_dir_entry* proc_entry;

// This function will be called when a program tries to read from our
// driver's entry on `/proc/hwdriver`.
static ssize_t custom_read(struct file* file, char __user* user_buffer, size_t count, loff_t* offset) {
	printk(KERN_INFO "calling our very own custom read method.");
	char greeting[] = "Hello world!\n";
	int greeting_length = strlen(greeting);

	if (*offset > 0)
		return 0;

	copy_to_user(user_buffer, greeting, greeting_length);
	*offset = greeting_length;

	return greeting_length;
}

// Note the original version sported a `file_operations` struct. Beginning
// on kernel version 5.6 (we're targeting 5.14) that type was deprecated in
// favour of the `proc_ops` type we see below. Please refer to the following
// https://github.com/torvalds/linux/blob/master/include/linux/proc_fs.h for
// a peek at the `proc_fs.h` header file. In the end we just need to initialise
// the `proc_read` struct member with a pointer to the function we've defined
// just above.
static struct proc_ops pops = {
	.proc_read = custom_read
};

// This method will be triggered when the module loads (possibly through
// `insmod`). The `printk` call will print messages on the kernel's ring
// buffer which can be displayed with `dmesg`. This function is also in
// charge of initializing the driver's entry under `/proc`.
static int __init custom_init(void) {
	// Create `/proc/hwdriver` to expose the driver over ProcFS.
	// Refer to https://github.com/torvalds/linux/blob/master/include/linux/proc_fs.h
	// for information on what each argument accomplishes.
	proc_entry = proc_create("hwdriver", 0666, NULL, &pops);

	printk(KERN_INFO "Hello world driver loaded.");

	return 0;
}

// In the same fashion as before, we will just print a message after cleaning
// up our `/proc/hwdriver` entry.
static void __exit custom_exit(void) {
	proc_remove(proc_entry);
	printk(KERN_INFO "Goodbye my friend, I shall miss you dearly...");
}

// We just need to inform the kernel on what our init and exit functions are
// and... done!
module_init(custom_init);
module_exit(custom_exit);
