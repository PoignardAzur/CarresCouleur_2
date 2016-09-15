// TO DELETE

#ifndef UP_HPP_
#define UP_HPP_

#include <memory>

template <typename T>
using uptrt = std::unique_ptr<T>;

template <typename T>
inline uptrt<T> uptr(T* ptr)
{
    return uptrt<T>(ptr);
}

using std::move;

#endif // !UP_HPP_
