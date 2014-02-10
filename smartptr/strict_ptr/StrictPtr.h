/*
    StrictPtr is yet another smart pointer implementation.
    (c) Volodymyr Lashko 2014
*/

#pragma once

#include <cstddef>


template< typename T >
class StrictPtr
{
public:
  explicit StrictPtr(const T * const src = NULL)
      : ptr_(src)
  { }

  ~StrictPtr()
  {
    delete ptr_;
  }
  
  T & operator*() const { return *ptr_; }
  T * const operator->() const { return ptr_; }
  T * const ptr() const { return ptr_; }
  const bool isNull() const { return ptr_ == NULL; }

private:
  StrictPtr(const FlexiblePtr & other);
  StrictPtr & operator=(const FlexiblePtr & other);

  T * const ptr_;
};

