#ifndef SMART_POINTER_H_
#define SMART_POINTER_H_

#include <iostream>

template <typename T>
class SmartPointer {
 public:
  SmartPointer(T* pointer) {
    pointer_ = pointer;
    counter_ = new size_t();
    *counter_ = 1;
  }
  SmartPointer(SmartPointer<T>& smart_pointer) {
    pointer_ = smart_pointer.pointer_;
    counter_ = smart_pointer.counter_;
    ++*counter_;
  }

  SmartPointer<T>& operator=(SmartPointer<T>& smart_pointer) {
    if (this != &smart_pointer) {
      if (--*counter_ == 0) {
        Clear();
        std::cout << "operator= clear" << std::endl;
      }
      pointer_ = smart_pointer.pointer_;
      counter_ = smart_pointer.counter_;
      ++*counter_;
    }
    return *this;
  }

  ~SmartPointer() {
    if (--*counter_ == 0) {
      Clear();
      std::cout << "Deconstructor clear" << std::endl;
    }
  }

  T* GetPointer() { return pointer_; }
  size_t GetCount() { return *counter_; }

 private:
  void Clear() {
    delete pointer_;
    delete counter_;
    pointer_ = nullptr;
    counter_ = nullptr;
  }

  T* pointer_;
  size_t* counter_;
};
#endif  // SMART_POINTER_H_