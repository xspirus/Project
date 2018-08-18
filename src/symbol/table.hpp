/*******************************************************************************
 *                                                                             *
 *  Filename    : table.hpp                                                    *
 *  Project     : Alan Compiler                                                *
 *  Version     : 1.0                                                          *
 *  Author      : Spiros Dontas                                                *
 *  Email       : spirosdontas@gmail.com                                       *
 *                                                                             *
 *  Description : Symbol Table header file                                     *
 *                                                                             *
 *******************************************************************************/

#ifndef __TABLE_HPP__
#define __TABLE_HPP__

#include <memory>
#include <deque>
#include <unordered_map>

#include <symbol/types.hpp>
#include <symbol/entry.hpp>
#include <symbol/scope.hpp>

namespace sem {

/*******************************************************************************
 ********************************** Typedefs ***********************************
 *******************************************************************************/

typedef std::deque<ScopePtr> ScopeStack;
typedef std::deque<EntryPtr> EntryStack;
typedef std::unordered_map<std::string, EntryStack> HashTable;

/*******************************************************************************
 ******************************** Enumerations *********************************
 *******************************************************************************/

enum class Lookup {
    CURRENT,
    ALL
};

/*******************************************************************************
 ***************************** Symbol Table Class ******************************
 *******************************************************************************/

class Table {
    public :
        // Variables
        HashTable  entries;
        ScopeStack scopes;

        // Methods
        void openScope(EntryPtr fun);
        void closeScope();
        TypePtr scopeType();
        void addReturn();
        void addHidden(EntryPtr entry);
        void insertEntry(EntryPtr entry);
        EntryPtr lookupEntry(std::string id, Lookup l);

        ScopePtr getScope();
};

}

#endif
