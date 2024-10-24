#include <string>
#include <cstdio>
#include <cstdlib>

std::size_t allocated = 0;

void *operator new(size_t sz)
{
    void *p = std::malloc(sz);
    allocated += sz;
    return p;
}

void operator delete(void *p) noexcept
{
    return std::free(p);
}

int main()
{
    allocated = 0;
    std::string s("***"); // 短字串
    std::printf("stack space = %zu, heap space = %zu, capacity = %zu\n",
                sizeof(s), allocated, s.capacity());

    allocated = 0;
    std::string s2(s.capacity() + 1, '*'); // 長字串
    std::printf("stack space = %zu, heap space = %zu, capacity = %zu\n",
                sizeof(s2), allocated, s2.capacity());

    allocated = 0;
    s2.push_back('x');
    std::printf("stack space = %zu, heap space = %zu, capacity = %zu\n",
                sizeof(s2), allocated, s2.capacity());
}