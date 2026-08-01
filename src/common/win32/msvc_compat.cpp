#ifdef __MINGW32__
#include <windows.h>
#include <stdint.h>

extern "C" {

uintptr_t __security_cookie = 0xBB40E64E;
void* _except_list = nullptr;

void __fastcall __security_check_cookie(uintptr_t cookie) {
    (void)cookie;
}

void _alloca_probe() {
    __asm__ __volatile__("ret");
}

void _chkstk() {
    __asm__ __volatile__("ret");
}

__attribute__((naked)) void _aullshr() {
    __asm__ __volatile__(
        "cmp $64, %%cl\n\t"
        "jge 1f\n\t"
        "cmp $32, %%cl\n\t"
        "jge 2f\n\t"
        "shrd %%cl, %%edx, %%eax\n\t"
        "shr %%cl, %%edx\n\t"
        "ret\n\t"
        "2:\n\t"
        "mov %%edx, %%eax\n\t"
        "xor %%edx, %%edx\n\t"
        "and $31, %%cl\n\t"
        "shr %%cl, %%eax\n\t"
        "ret\n\t"
        "1:\n\t"
        "xor %%eax, %%eax\n\t"
        "xor %%edx, %%edx\n\t"
        "ret\n\t"
        ::: "memory"
    );
}

}
#endif
