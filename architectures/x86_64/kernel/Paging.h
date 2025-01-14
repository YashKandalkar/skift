#pragma once

#include <libsystem/Common.h>

struct __packed PageMappingLevel4Entry
{
    bool present : 1;               // Must be 1 to reference a PML-1
    bool writable : 1;              // If 0, writes may not be allowed.
    bool supervisor : 1;            // If 0, user-mode accesses are not allowed
    bool write_thought : 1;         // Page-level write-through
    bool cache : 1;                 // Page-level cache disable
    bool accessed : 1;              // Indicates whether this entry has been used
    int zero0 : 6;                  // Ignored
    uint64_t physical_address : 36; // Physical address of a 4-KByte aligned PLM-1
    int zero1 : 15;                 // Ignored
    bool execute_disabled : 1;      // If IA32_EFER.NXE = 1, Execute-disable
};

struct __packed PageMappingLevel4
{
    PageMappingLevel4Entry entries[512];
};

static inline size_t pml4_index(uintptr_t address)
{
    return (address >> 39) & 0x1FF;
}

static_assert(sizeof(PageMappingLevel4Entry) == sizeof(uint64_t));
static_assert(sizeof(PageMappingLevel4) == 4096);

struct __packed PageMappingLevel3Entry
{
    bool present : 1;               // Must be 1 to reference a PML-1
    bool writable : 1;              // If 0, writes may not be allowed.
    bool supervisor : 1;            // If 0, user-mode accesses are not allowed
    bool write_thought : 1;         // Page-level write-through
    bool cache : 1;                 // Page-level cache disable
    bool accessed : 1;              // Indicates whether this entry has been used
    int zero0 : 1;                  // Ignored
    int size : 1;                   // Must be 0 otherwise, this entry maps a 1-GByte page.
    int zero1 : 4;                  // Ignored
    uint64_t physical_address : 36; // Physical address of a 4-KByte aligned PLM-1
    int zero2 : 15;                 // Ignored
    bool execute_disabled : 1;      // If IA32_EFER.NXE = 1, Execute-disable
};

struct __packed PageMappingLevel3
{
    PageMappingLevel3Entry entries[512];
};

static inline size_t pml3_index(uintptr_t address)
{
    return (address >> 30) & 0x1FF;
}

static_assert(sizeof(PageMappingLevel3Entry) == sizeof(uint64_t));
static_assert(sizeof(PageMappingLevel3) == 4096);

struct __packed PageMappingLevel2Entry
{
    bool present : 1;               // Must be 1 to reference a PML-1
    bool writable : 1;              // If 0, writes may not be allowed.
    bool supervisor : 1;            // If 0, user-mode accesses are not allowed
    bool write_thought : 1;         // Page-level write-through
    bool cache : 1;                 // Page-level cache disable
    bool accessed : 1;              // Indicates whether this entry has been used
    int zero0 : 1;                  // Ignored
    int size : 1;                   // Must be 0 otherwise, this entry maps a 2-MByte page.
    int zero1 : 4;                  // Ignored
    uint64_t physical_address : 36; // Physical address of a 4-KByte aligned PLM-1
    int zero2 : 15;                 // Ignored
    bool execute_disabled : 1;      // If IA32_EFER.NXE = 1, Execute-disable
};

struct __packed PageMappingLevel2
{
    PageMappingLevel3Entry entries[512];
};

static inline size_t pml2_index(uintptr_t address)
{
    return (address >> 21) & 0x1FF;
}

static_assert(sizeof(PageMappingLevel2Entry) == sizeof(uint64_t));
static_assert(sizeof(PageMappingLevel2) == 4096);

struct __packed PageMappingLevel1Entry
{
    bool present : 1;               // Must be 1 to reference a PML-1
    bool writable : 1;              // If 0, writes may not be allowed.
    bool supervisor : 1;            // If 0, user-mode accesses are not allowed
    bool write_thought : 1;         // Page-level write-through
    bool cache : 1;                 // Page-level cache disable
    bool accessed : 1;              // Indicates whether this entry has been used
    int dirty : 1;                  // Indicates whether software has accessed the 4-KByte page referenced by this entry
    int memory_type : 1;            // Indirectly determines the memory type used to access the 4-KByte page referenced by this entry.
    int global : 1;                 // If CR4.PGE = 1, determines whether the translation is global.
    int zero0 : 3;                  // Ignored
    uint64_t physical_address : 36; // Physical address of a 4-KByte aligned PLM-1
    int zero1 : 10;                 // Ignored
    bool protection_key : 5;        // If CR4.PKE = 1, determines the protection key of the page.
    bool execute_disabled : 1;      // If IA32_EFER.NXE = 1, Execute-disable
};

struct __packed PageMappingLevel1
{
    PageMappingLevel3Entry entries[512];
};

static inline size_t pml1_index(uintptr_t address)
{
    return (address >> 12) & 0x1FF;
}

static_assert(sizeof(PageMappingLevel1Entry) == sizeof(uint64_t));
static_assert(sizeof(PageMappingLevel1) == 4096);
