/*
 * 2017	Davide Maraschio
 *
 */

#include <types.h>
#include <syscall.h>
#include <lib.h>
#include <vnode.h>
#include <uio.h>
#include <current.h>
#include <proc.h>
#include <vfs.h>
#include <opt-file_management.h>

#define MAXFILE 100

struct vnode *fdTable[MAXFILE]; // Take notes of all the opened file
int currFid=3; // Point to the next available FD

int sys_write(int fd, const void *buffer, size_t len, int *retval) {

	int i=0;

	if( fd == 1 || fd == 2) {
		for(i=0; i<(int)len; i++)
			kprintf("%c", ((char *)buffer)[i]);

		*retval = i;
	
		return 0;
	} 
#ifdef OPT_FILE_MANAGEMENT	
	else if(fd >= 3) {
		
		struct iovec iov;
		struct uio u;
		struct vnode *v = fdTable[fd];
		int result;	

		KASSERT(v!=NULL);

		iov.iov_kbase = (userptr_t)buffer;
		iov.iov_len = len;
		u.uio_iov = &iov;
		u.uio_iovcnt = 1;
		u.uio_offset = 0;
		u.uio_resid = len;
		u.uio_segflg = UIO_USERSPACE;
		u.uio_rw = UIO_WRITE;
		u.uio_space = curproc->p_addrspace;
		
		result = VOP_WRITE(v, &u);

		*retval = len - u.uio_resid; // written bytes

		return result;
	} 
#endif
	else {
		kprintf("Error: Cannot print on stdin");
		*retval = -1;
		return 0;
	}
}

int sys_read(int fd, void *buffer, size_t count, int *retval) {

	char c;

	if( fd == 0) {
		for(int i=0; i< (int)count; i++) {

			c = getch();

			*((char *)(buffer+i)) = c;
		}

		*retval = (int)count;
	
		return 0;
	} 
#ifdef OPT_FILE_MANAGEMENT	
	else if(fd >= 3) {
		
		struct iovec iov;
		struct uio u;
		struct vnode *v = fdTable[fd];
		int result;	

		KASSERT(v!=NULL);

		iov.iov_kbase = (userptr_t)buffer;
		iov.iov_len = count;
		u.uio_iov = &iov;
		u.uio_iovcnt = 1;
		u.uio_offset = 0;
		u.uio_resid = count;
		u.uio_segflg = UIO_USERSPACE;
		u.uio_rw = UIO_READ;
		u.uio_space = curproc->p_addrspace;
		
		result = VOP_READ(v, &u);

		*retval = count - u.uio_resid; // written bytes

		return result;
	} 
#endif
	else {
		kprintf("Error: Cannot read from stdout");
		*retval = -1;
		return -1;
	}
}

#ifdef OPT_FILE_MANAGEMENT

int sys_open(const char *filename, int flags, int *retval) {
	
	struct vnode *v;
	int fd, result;

	result = vfs_open((char *)filename, flags, 0, &v);

	if(result) return -1;
	if (currFid >= MAXFILE) return -1;

	fd = currFid++;
	fdTable[fd] = v;
	
	*retval = fd;
	return 0;
}

int sys_close(int fd) {
	
	if(fd<3) return -1;
	if(fdTable[fd] == NULL) return -1;

	vfs_close(fdTable[fd]);

	fdTable[fd] = NULL;

	return 0;
}

int sys_remove(const char *filename) {
	
	//int result;

	(void)filename;
	
	// NOT IMPLEMENTED
	//result = vfs_remove((char *)filename);
	
	//if(result) return -1;

	kprintf("FILE REMOVED AHAHAHAHAHAHAHAH\n");
	
	return 0;
}
#endif













