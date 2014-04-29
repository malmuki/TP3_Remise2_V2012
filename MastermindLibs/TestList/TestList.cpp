#include "TestList.h"

TestList::TestList(void)
    {
    RunAllTests();
    }

TestList::~TestList(void)
    {
    }

void TestList::RunAllTests()
    {
    TextConstructeur();
    TestPushBack1();
    TestPushBack2();
    TestInsert1();
    TestInsert2();
    TestErase1();
    TestErase2();
    TestErase3();
    TestErase4();
    TestGetElement();
    TestGetNbElement();
    TestIsEmpty();
    TestClear();
    }

void TestList::TextConstructeur()
    {
    List<int>* list = new List<int>();
    assert(list->Begin() == NULL && list->End() == NULL);
    }

void TestList::TestPushBack1()// si list vide
    {
    List<int>* list = new List<int>();

    int i = 0;

    list->PushBack(&i);

    assert(list->Begin()->Element == list->End()->Element);
    }

void TestList::TestPushBack2()// si list avec qqchose( a la fin )
    {
    List<int>* list = new List<int>();

    int i = 0;
    int o = 2;

    list->PushBack(&i);
    list->PushBack(&o);

    Cell<int>* cell = new Cell<int>(&o,NULL,NULL);

    assert(list->End()->Element == cell->Element);
    }

void TestList::TestInsert1()//au debut
    {
    List<int>* list = new List<int>();
    Iterator<int>* iterator = new Iterator<int>();

    int i = 0;
    int o = 2;
    list->PushBack(&i);

    iterator->SetCurrent(list->End());

    list->Insert(&o,*iterator);

    assert(list->Begin() != list->End());
    }

void TestList::TestInsert2()//au entre premier et dernier
    {
    List<int>* list = new List<int>();
    Iterator<int>* iterator = new Iterator<int>();

    int i = 0;
    int z = 1;
    int o = 2;
    list->PushBack(&i);
    list->PushBack(&z);

    iterator->SetCurrent(list->Begin()->Next);

    list->Insert(&o,*iterator);

    assert(list->Begin() != list->Begin()->Next && list->End() != list->Begin()->Next);
    }

void TestList::TestErase1()//entre premier et dernier
    {
    List<int>* list = new List<int>();
    Iterator<int>* iterator = new Iterator<int>();

    int i = 0;
    int z = 1;
    int o = 2;
    list->PushBack(&i);
    list->PushBack(&z);
    list->PushBack(&o);

    iterator->SetCurrent(list->Begin()->Next);

    list->Erase(*iterator);

    assert(list->End() == iterator->GetCurrent());
    }

void TestList::TestErase2()//au debut
    {
    List<int>* list = new List<int>();
    Iterator<int>* iterator = new Iterator<int>();

    int i = 0;
    int z = 1;

    list->PushBack(&i);
    list->PushBack(&z);

    iterator->SetCurrent(list->Begin());

    list->Erase(*iterator);

    assert(list->Begin() == list->End());
    }

void TestList::TestErase3()//a la fin
    {
    List<int>* list = new List<int>();
    Iterator<int>* iterator = new Iterator<int>();

    int i = 0;
    int z = 1;

    list->PushBack(&i);
    list->PushBack(&z);

    iterator->SetCurrent(list->End());

    list->Erase(*iterator);

    assert(list->End() == list->Begin());
    }

void TestList::TestErase4() //le dernier element
    {
    List<int>* list = new List<int>();
    Iterator<int>* iterator = new Iterator<int>();

    int i = 0;

    list->PushBack(&i);

    iterator->SetCurrent(list->End());

    list->Erase(*iterator);

    assert(list->End() == NULL);
    }

void TestList::TestGetElement()
    {
    List<int>* list = new List<int>();
    Iterator<int>* iterator = new Iterator<int>();

    int i = 0;

    list->PushBack(&i);

    iterator->SetCurrent(list->Begin());

    assert(*(list->GetElement(*iterator)) == i);
    }

void TestList::TestGetNbElement()
    {
    List<int>* list = new List<int>();

    int i = 0;
    int z = 1;

    list->PushBack(&i);
    list->PushBack(&z);

    assert(list->GetNbElements() == 2);
    }

void TestList::TestIsEmpty()
    {
    List<int>* list = new List<int>();

    assert(list->IsEmpty());
    }

void TestList::TestClear()
    {
    List<int>* list = new List<int>();

    int i = 0;
    int z = 1;
    int o = 2;
    list->PushBack(&i);
    list->PushBack(&z);
    list->PushBack(&o);

    list->Clear();

    assert(list->IsEmpty());
    }
