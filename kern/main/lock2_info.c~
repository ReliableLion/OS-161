#include <types.h>
#include <kern/errno.h>
#include <kern/reboot.h>
#include <kern/unistd.h>
#include <limits.h>
#include <lib.h>
#include <opt-sfs.h>
#include <opt-net.h>
#include <opt-lock2.h>

#if OPT_LOCK2
void lock2_info(void);
#endif

void lock2_info(void) {

	kprintf("Hello Guys!\n\n");
	kprintf("-I'm implementing this syscalls:\n\n");
	kprintf("\t-- SYS_WRITE() (syscall 55)\n\n");
	kprintf("\t-- SYS_READ() (syscall 50)\n\n");
	kprintf("\t-- SYS_EXIT() (syscall 3)\n\n");
	kprintf("-DUMBVM with deallocation implemented\n\n");
	kprintf("-Lock implemented with wchan and spinlock\n\n");
}
