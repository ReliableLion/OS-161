#include <types.h>
#include <kern/errno.h>
#include <kern/reboot.h>
#include <kern/unistd.h>
#include <limits.h>
#include <lib.h>
#include <opt-sfs.h>
#include <opt-net.h>
#include <opt-file_management.h>

#if OPT_FILE_MANAGEMENT
void file_management_info(void);
#endif

void file_management_info(void) {

	kprintf("Hello Guys!\n\n");
	kprintf("-I'm implementing this syscalls:\n\n");
	kprintf("\t-- SYS_WRITE() (syscall 55)\n\n");
	kprintf("\t-- SYS_READ() (syscall 50) extended for file management\n\n");
	kprintf("\t-- SYS_EXIT() (syscall 3) extended for file management\n\n");
	kprintf("\t-- SYS_OPEN() (syscall 45)\n\n");
	kprintf("\t-- SYS_CLOSE() (syscall 49)\n\n");
	kprintf("\t-- SYS_REMOVE() (syscall 68)\n\n");
	kprintf("-DUMBVM with deallocation implemented\n\n");
	kprintf("-Lock implemented with wchan and spinlock\n\n");
	kprintf("-Condition Variables implemented (with wchan and spinlock)\n\n");
	kprintf("-WAIT_PROC implemented with condition variables\n\n");
}
