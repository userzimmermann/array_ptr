/* array_ptr
 *
 * a simple c style array ptr/size wrapper template for c++
 * with stl container functionality
 * and support for std::vector and boost::array
 *
 * Copyright (C) 2011 Stefan Zimmermann <zimmermann.code@googlemail.com>
 *
 * array_ptr is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * array_ptr is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with array_ptr.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __CONST_ARRAY_PTR_HPP
#define __CONST_ARRAY_PTR_HPP

#include "array_ptr.hpp"

namespace array_ptr
{
  template<typename T>
  class const_array_ptr : public array_ptr<const T>
  {
  public:
    inline const_array_ptr(const array_ptr<T> &values) :
      array_ptr<const T>(values.get(), values.size())
    {}

    inline const_array_ptr(const std::vector<T> &values) :
      array_ptr<const T>(&values[0], values.size())
    {}

    template<std::size_t SIZE>
    inline const_array_ptr(const boost::array<T, SIZE> &values) :
      array_ptr<const T>(values.data(), SIZE)
    {}

    inline void reset(const array_ptr<T> &values)
    {
      this->array_ptr<const T>::reset(values.get(), values.size());
    }

    inline void reset(const std::vector<T> &values)
    {
      this->array_ptr<const T>::reset(&values[0], values.size());
    }

    template<std::size_t SIZE>
    inline void reset(const boost::array<T, SIZE> &values)
    {
      this->array_ptr<const T>::reset(values.data(), SIZE);
    }
  };
}

#endif