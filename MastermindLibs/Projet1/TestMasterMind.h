#pragma once
class TestMasterMind
    {
    public:
        TestMasterMind(void);
    private:
        void runAllTest();
        void TestConstructeur();
        void TestGetNbElement();
        void TestGetElement();
        void TestCleanList1();  //si bonne couleur bonne place
        void TestCleanList2();  //Bonne couleur, mauvaise place
        void TestCleanList3();  //Mauvaise couleur
    };
