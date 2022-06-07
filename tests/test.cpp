#include <gtest/gtest.h>
#include "Transaction.h"
#include "Account.h"

//тест на работу аккаунта и баланса
TEST(Trans, account) {
Account Acc(101, 100);
EXPECT_EQ(Acc.GetBalance(), 100);
}

//тест на условие закрытия аккаунта
TEST(Transaction, change_balance) {
    Account Acc(100, 100);
    try {
        Acc.ChangeBalance(100);
    } catch (std::runtime_error& error){
        EXPECT_EQ(error.what(), std::string("at first lock the account"));
    }
    Acc.Lock();
    Acc.ChangeBalance(100);
    EXPECT_EQ(Acc.GetBalance(), 200);
}
