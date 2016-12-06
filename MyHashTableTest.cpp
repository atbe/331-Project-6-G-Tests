#include <iostream>
using std::cout; using std::endl;
#include "gtest/gtest.h"
#include "src/HashTable.cpp"
#include "fstream"
using std::ifstream;

// Use the accounts class for testing
struct Account
{
    int acctNum;              // (Key) Account number
    float balance;            // Account balance

    int getKey () const { return acctNum; }
    static unsigned int hash(const int& key) { return abs( key ); }
};

class MyHashTableTest : public ::testing::Test {
    protected:
        HashTable<Account,int> accounts{11};    // List of accounts


        virtual void SetUp() {
            Account acct;                         // A single account

            std::ifstream inClientFile("src/test_accounts", std::ios::in);

            if (!inClientFile.is_open()) {
                cout << "Could not open file\n";
                throw;
            }

            // Fill in the accounts
            for ( int i = 0; i < 5; i++ )
            {
                inClientFile >> acct.acctNum >> acct.balance;
                accounts.insert(acct);
            }
        }

      // virtual void TearDown() {}
};

/** Tests for {} class.
 *
 */

TEST_F(MyHashTableTest, ConstructHashTable)
{
    ASSERT_FALSE(accounts.isEmpty());
}

TEST_F(MyHashTableTest, InsertItemIntoHashTable)
{

}

