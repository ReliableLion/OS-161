# OS-161
### What's that
This repo contains the original os-161, enhanced with some implementations. In particular I implemented:
1. System Calls:
    - SYS_WRITE() (syscall 55)
    - SYS_READ() (syscall 50) extended for file management
    - SYS_EXIT() (syscall 3) extended for file management
    - SYS_OPEN() (syscall 45)
    - SYS_CLOSE() (syscall 49)
    - SYS_REMOVE() (syscall 68) (It actually doesn't remove the file for real)
    
2. DUMBVM with deallocation

3. Lock implemented using wchan and spinlock

4. Condition Variables implemented (with wchan and spinlock)

5. WAIT_PROC implemented with condition variables
