
#ifndef UNIQUE_PTR_TPP
#define UNIQUE_PTR_TPP

#include <utility>

template<typename T>
UniquePtr<T>::UniquePtr()
    : ptr(nullptr) {}

template<typename T>
UniquePtr<T>::UniquePtr(T* p)
    : ptr(p) {}

template<typename T>
T* UniquePtr<T>::get() const noexcept{
    return ptr;
}

template<typename T>
T& UniquePtr<T>::operator*() const {
    return *ptr;
}

template<typename T>
T* UniquePtr<T>::operator->() const noexcept{
    return ptr;
}

template<typename T>
UniquePtr<T>::operator bool() const noexcept{
    return ptr != nullptr;
}

template<typename T>
T* UniquePtr<T>::release() noexcept{
    T* p = ptr;
    ptr = nullptr;
    return p;
}

template<typename T>
void UniquePtr<T>::reset(T* newPtr) noexcept{
    if (ptr != newPtr) {
        delete ptr;
        ptr = newPtr;
    }
}

template<typename T>
void UniquePtr<T>::swap(UniquePtr<T>& other) noexcept {
    std::swap(ptr, other.ptr);
}

template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr<T>&& other) noexcept
    : ptr(other.ptr) {
    other.ptr = nullptr;
}

template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& other) noexcept {
    if (this != &other) {
        reset(other.release());
    }
    return *this;
}

template<typename T>
UniquePtr<T>::~UniquePtr() {
    delete ptr;
}

#endif

