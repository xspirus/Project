/*******************************************************************************
 *                                                                             *
 *  Filename    : general.hpp                                                  *
 *  Project     : Alan Compiler                                                *
 *  Version     : 1.0                                                          *
 *  Author      : Spiros Dontas                                                *
 *  Email       : spirosdontas@gmail.com                                       *
 *                                                                             *
 *  Description : General Functions used across multiple files                 *
 *                                                                             *
 *******************************************************************************/

#ifndef __GENERAL_HPP__
#define __GENERAL_HPP__

#include <memory>
#include <message/message.hpp>

/*******************************************************************************
 * Variadic Template functions must be implemented in header file.
 *   - newShared :
 *     > It is just a rename for sts::make_shared.
 *     > Also checks null pointer and crashes if out of memory.
 *******************************************************************************/

template<typename T, typename ... Args>
inline std::shared_ptr<T> newShared(Args&& ... args) {
    auto temp = std::make_shared<T>(args...);
    if ( temp == nullptr )
        internal("Out of memory");
    return temp;
}

#endif
