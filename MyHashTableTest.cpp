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
        HashTable<Account,int> emptyAccounts{11};    // List of accounts


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

/** Tests for HashTable class.
 *
 * Insert
 * Remove
 * Retrieve
 * IsEmpty
 *
 */

TEST_F(MyHashTableTest, ConstructHashTable)
{
    // The hashtable should not be empty (even though this may pass if your
    // isEmpty function does not work correctly).
    ASSERT_FALSE(accounts.isEmpty()) << "Hash table should not be empty.";
    ASSERT_TRUE(emptyAccounts.isEmpty()) << "Blank hash table should be empty.";
}

TEST_F(MyHashTableTest, InsertItemIntoHashTable)
{
    Account acct{420, 42.42};
    emptyAccounts.insert(acct);
    ASSERT_FALSE(emptyAccounts.isEmpty()) << "Hash Table must not be empty if account has been inserted.";
}

TEST_F(MyHashTableTest, RetrieveItemFromHashTable)
{
    Account acct{420, 42.42};
    emptyAccounts.insert(acct);

    Account retrieveDest;
    if(emptyAccounts.retrieve(acct.getKey(), retrieveDest))
    {
        ASSERT_TRUE(acct == retrieveDest) << "The acccount inserted must match the account we retrieve.";
    }
}
