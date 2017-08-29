/*
 * 2017	Davide Maraschio
 *
 */

#include <types.h>
#include <syscall.h>
#include <current.h>
#include <thread.h>
#include <proc.h>
#include <addrspace.h>

#include <opt-wait_proc.h>

void sys_exit(int exit_code) {

	struct proc *p = curproc;

	/* Set exit code */

	curthread->exit_code = exit_code;

	p->exit_code = exit_code;

	/* Detach thread from its process */

	proc_remthread(curthread);

#if OPT_WAIT_PROC
	lock_acquire(p->parent_lock);

	cv_signal(p->p_cv, p->parent_lock);

	lock_release(p->parent_lock);
#else
	proc_destroy(p);
#endif

	/* Thread exit will never return */

	thread_exit();

	panic("WHAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAT");
}
