#include "mystring.h"
#include "myutils.h"
#include "bitmask.h"

#include "unity.h"

/* Required by the unity test framework */
void setUp() {}
/* Required by the unity test framework */
void tearDown() {}

#pragma region mystring

void test_mystrlen()
{
    const char* tst_str1 = "Hello World";
    TEST_ASSERT_EQUAL(11, mystrlen(tst_str1));
}

void test_mystrcpy()
{
    const char tst_str1[16] = "Hello World";
    char buff[16];
    mystrcpy(buff, 16, tst_str1);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(tst_str1, buff, 12);
}

void test_mystrcat()
{
    const char tst_str1[16] = "Hello World";
    char buff[64] = "I am first. Next is ";
    char result[64] = "I am first. Next is Hello World";
    mystrcat(buff, 64, tst_str1);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(result, buff, 64);
}

void test_mystrcmp()
{
    const char tst_str1[16] = "Hello5World";
    const char tst_str2[16] = "Hello0World";
    const char tst_str3[16] = "Hello9World";
    const char tst_str4[16] = "Hello5Worl";
    const char tst_str5[16] = "Hello5World!";
    TEST_ASSERT_EQUAL( 0, mystrcmp(tst_str1, tst_str1, 16));
    TEST_ASSERT_EQUAL( 1, mystrcmp(tst_str1, tst_str2, 16));
    TEST_ASSERT_EQUAL(-1, mystrcmp(tst_str1, tst_str3, 16));
    TEST_ASSERT_EQUAL( 1, mystrcmp(tst_str1, tst_str4, 16));
    TEST_ASSERT_EQUAL(-1, mystrcmp(tst_str1, tst_str5, 16));
}

void test_mystring()
{
    RUN_TEST(test_mystrlen);
    RUN_TEST(test_mystrcpy);
    RUN_TEST(test_mystrcat);
    RUN_TEST(test_mystrcmp);
}

#pragma endregion

#pragma region myutils

#pragma region factorial

void test_factorial_all_ok(void)
{
    TEST_ASSERT_EQUAL(                  1ul, factorial( 0u));
    TEST_ASSERT_EQUAL(                  1ul, factorial( 1u));
    TEST_ASSERT_EQUAL(                  2ul, factorial( 2u));
    TEST_ASSERT_EQUAL(                120ul, factorial( 5u));
    TEST_ASSERT_EQUAL(            3628800ul, factorial(10u));
    TEST_ASSERT_EQUAL(      1307674368000ul, factorial(15u));
    TEST_ASSERT_EQUAL(2432902008176640000ul, factorial(20u));
    TEST_ASSERT_EQUAL(                  0ul, factorial(30u));
}

#pragma endregion

#pragma region isPrime

void test_isPrime_all_ok(void)
{
    TEST_ASSERT_EQUAL( true, isPrime(  2u));
    TEST_ASSERT_EQUAL( true, isPrime(  5u));
    TEST_ASSERT_EQUAL( true, isPrime( 89u));
    TEST_ASSERT_EQUAL(false, isPrime(221u));
    TEST_ASSERT_EQUAL( true, isPrime(257u));
    TEST_ASSERT_EQUAL( true, isPrime(433u));
    TEST_ASSERT_EQUAL( true, isPrime(613u));
    TEST_ASSERT_EQUAL(false, isPrime(667u));
    TEST_ASSERT_EQUAL( true, isPrime(809u));
}

void test_isPrime_zero_one(void)
{
    TEST_ASSERT_EQUAL(false, isPrime(0u));
    TEST_ASSERT_EQUAL(false, isPrime(1u));
}

void test_isPrime_large(void)
{
    TEST_ASSERT_EQUAL(false, isPrime(8343u));
    TEST_ASSERT_EQUAL( true, isPrime(8443u));
    TEST_ASSERT_EQUAL(false, isPrime(6443u));
    TEST_ASSERT_EQUAL( true, isPrime(9161u));
    TEST_ASSERT_EQUAL(false, isPrime(9171u));
    TEST_ASSERT_EQUAL( true, isPrime(9181u));
}

void test_isPrime_very_large(void)
{
    TEST_ASSERT_EQUAL( true, isPrime(2147483647u));
    TEST_ASSERT_EQUAL(false, isPrime(1914582657u));
}

void test_isPrime_super_large(void)
{
    // Takes very long. Pass -DHEAVY to gcc if you have a capable machine
#ifndef HEAVY
    TEST_IGNORE();
#endif // HEAVY
    TEST_ASSERT_EQUAL( true, isPrime(10911097110311091151u));
    TEST_ASSERT_EQUAL( true, isPrime(11111111111111111011u));
    TEST_ASSERT_EQUAL(false, isPrime(11111111111110011011u));
}

#pragma endregion

#pragma region isPalindrome

void test_isPalindrome_all_ok(void)
{
    TEST_ASSERT_EQUAL( true, isPalindrome(  0u));
    TEST_ASSERT_EQUAL(false, isPalindrome( 10u));
    TEST_ASSERT_EQUAL( true, isPalindrome(101u));
}

#pragma endregion

#pragma region vsum

void test_vsum_all_ok(void)
{
    TEST_ASSERT_EQUAL( 0, vsum(0u));
    TEST_ASSERT_EQUAL( 1, vsum(1u, 1));
    TEST_ASSERT_EQUAL( 1, vsum(3u, 1, 2, -2));
}


#pragma endregion

void test_myutils()
{
    /* Run Test functions for factorial */
    RUN_TEST(test_factorial_all_ok);

    /* Run Test functions for isPrime */
    RUN_TEST(test_isPrime_all_ok);
    RUN_TEST(test_isPrime_zero_one);
    RUN_TEST(test_isPrime_large);
    RUN_TEST(test_isPrime_very_large);
    RUN_TEST(test_isPrime_super_large);

    /* Run Test functions for isPalindrome */
    RUN_TEST(test_isPalindrome_all_ok);

    /* Run Test functions for vsum */
    RUN_TEST(test_vsum_all_ok);
}

#pragma endregion

#pragma region bitmask

void test_bitmask_all()
{
    TEST_ASSERT_EQUAL(0x8ul, bit_set(0x0ul, 3));
    TEST_ASSERT_EQUAL(0x7ful, bit_reset(0xfful, 7));
    TEST_ASSERT_EQUAL(0xf0ul, bit_flip(0xf4ul, 2));
    TEST_ASSERT_EQUAL(  true, bit_query(0xf4ul, 2));
}

void test_bitmask()
{
    RUN_TEST(test_bitmask_all);
}

#pragma endregion

int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    test_myutils();
    test_mystring();
    test_bitmask();

    /* Close the Unity Test Framework */
    return UNITY_END();
}
