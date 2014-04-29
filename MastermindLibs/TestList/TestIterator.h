#pragma once
class TestIterator
    {
    public:
        TestIterator(void);
        ~TestIterator(void);

    private:
        void RunAllTests();
        void TestNext();
        void TestPrevious();
        void TestGetCurrentElement();
        void TestGetCurrent();
        void TestSetCurrent();
    };
