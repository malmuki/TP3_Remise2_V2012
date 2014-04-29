#pragma once
#include "List.h"
class TestList
{
public:
    TestList(void);
    ~TestList(void);

private:
    void RunAllTests();
    void TextConstructeur();
    void TestPushBack1();
    void TestPushBack2();
    void TestInsert1();
    void TestInsert2();
    void TestErase1();
    void TestErase2();
    void TestErase3();
    void TestErase4();
    void TestGetElement();
    void TestGetNbElement();
    void TestIsEmpty();
    void TestClear();
};

