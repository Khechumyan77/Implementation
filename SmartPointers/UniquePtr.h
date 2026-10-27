
#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <utility>

template<typename T>
class UniquePtr {
private:
    T* ptr;

public:
    UniquePtr();
    UniquePtr(T* p);

    T* get() const noexcept;
    T& operator*() const;
    T* operator->() const noexcept;

    explicit operator bool() const noexcept;

    T* release() noexcept;
    void reset(T* newPtr = nullptr) noexcept;
    void swap(UniquePtr& other) noexcept;

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&& other) noexcept;
    UniquePtr& operator=(UniquePtr&& other) noexcept;

    ~UniquePtr();
};

#include "UniquePtr.tpp"

#endif

