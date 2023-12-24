#ifndef ADDRESS_BOOK_H_
#define ADDRESS_BOOK_H_

#include "address.h"

class AddressBook {

    private:
        static const int MAXN = 1000;

        int book_size;
        Address book[MAXN];

        void ShowSingleAddress( int address_num ) const;
        int FindAddress( std::string u_name ) const;

    public:

        AddressBook();
        void AddNewAddress();
        void ShowAddress() const;
        void DeleteAddress();
        void QueryAddress() const;
        void UpdateAddress();
        void ClearAddress();
};

#endif