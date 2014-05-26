/*
    This file is part of AcceSSL.

    Copyright 2011-2014 Marcin Gozdalik <gozdal@gmail.com>

    AcceSSL is free software; you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    AcceSSL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with AcceSSL; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _ATOMIC_HPP_
#define _ATOMIC_HPP_

#include <boost/detail/atomic_count.hpp>

namespace atomic {

class scoped_counter {
public:
    scoped_counter(boost::detail::atomic_count& counter) :
        m_counter(counter)
    {
        ++m_counter;
    }

    virtual ~scoped_counter()
    {
        --m_counter;
    }

private:
    boost::detail::atomic_count& m_counter;
};

};

#endif // _ATOMIC_HPP_
