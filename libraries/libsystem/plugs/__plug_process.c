
#include <abi/Syscalls.h>

#include <libsystem/Assert.h>
#include <libsystem/__plugs__.h>

static int _cached_this = -1;

int __plug_process_this(void)
{
    if (_cached_this == -1)
    {
        assert(__syscall(SYS_PROCESS_THIS, (int)&_cached_this, 0, 0, 0, 0) == SUCCESS);
    }

    return _cached_this;
}

Result __plug_process_launch(Launchpad *launchpad, int *pid)
{
    return (Result)__syscall(SYS_PROCESS_LAUNCH, (int)launchpad, (int)pid, 0, 0, 0);
}

void __plug_process_exit(int code)
{
    __syscall(SYS_PROCESS_EXIT, code, 0, 0, 0, 0);

    ASSERT_NOT_REACHED();
}

Result __plug_process_cancel(int pid)
{
    return (Result)__syscall(SYS_PROCESS_CANCEL, pid, 0, 0, 0, 0);
}

Result __plug_process_map(uintptr_t address, size_t size)
{
    return (Result)__syscall(SYS_PROCESS_MAP, address, size, 0, 0, 0);
}

Result __plug_process_alloc(size_t count, uintptr_t *out_address)
{
    return (Result)__syscall(SYS_PROCESS_ALLOC, count, (int)out_address, 0, 0, 0);
}

Result __plug_process_free(uintptr_t address, size_t size)
{
    return (Result)__syscall(SYS_PROCESS_FREE, address, size, 0, 0, 0);
}

Result __plug_process_get_cwd(char *buffer, uint size)
{
    return (Result)__syscall(SYS_PROCESS_GET_CWD, (int)buffer, size, 0, 0, 0);
}

Result __plug_process_set_cwd(const char *cwd)
{
    return (Result)__syscall(SYS_PROCESS_SET_CWD, (int)cwd, 0, 0, 0, 0);
}

Result __plug_process_sleep(int time)
{
    return (Result)__syscall(SYS_PROCESS_SLEEP, time, 0, 0, 0, 0);
}

Result __plug_process_wait(int pid, int *exit_value)
{
    return (Result)__syscall(SYS_PROCESS_WAIT, pid, (int)exit_value, 0, 0, 0);
}
