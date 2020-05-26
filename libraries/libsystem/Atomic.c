
#include <libsystem/Atomic.h>
#include <libsystem/Common.h>

static bool atomic_enabled = false;
static uint atomic_depth = 0;

bool is_atomic()
{
    return !(atomic_enabled && atomic_depth == 0);
}

void atomic_enable()
{
    atomic_enabled = true;
}

void atomic_disable()
{
    atomic_enabled = false;
}

void atomic_begin()
{
    if (atomic_enabled)
    {
        asm volatile("cli");
        atomic_depth++;
    }
}

void atomic_end()
{
    if (atomic_enabled)
    {
        atomic_depth--;

        if (atomic_depth == 0)
        {
            asm volatile("sti");
        }
    }
}