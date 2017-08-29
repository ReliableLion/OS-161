#include <types.h>
#include <kern/errno.h>
#include <kern/reboot.h>
#include <kern/unistd.h>
#include <limits.h>
#include <lib.h>
#include <opt-sfs.h>
#include <opt-net.h>
#include <opt-binarylock.h>

#if OPT_BINARYLOCK
void binaryLock_info(void);
#endif

void binaryLock_info(void) {

	kprintf("Hello Guys!\n\n");
	kprintf("-I'm implementing this syscalls:\n\n");
	kprintf("\t-- SYS_WRITE() (syscall 55)\n\n");
	kprintf("\t-- SYS_READ() (syscall 50)\n\n");
	kprintf("\t-- SYS_EXIT() (syscall 3)\n\n");
	kprintf("-DUMBVM with deallocation implemented\n\n");
	kprintf("-Lock implemented as binary sem\n\n");
}
