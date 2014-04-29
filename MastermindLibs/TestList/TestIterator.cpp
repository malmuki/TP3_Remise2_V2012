#include <iostream>
#include <assert.h>
#include "TestIterator.h"
#include "Cell.h"
#include "Iterator.h"

TestIterator::TestIterator(void)
    {
    RunAllTests();
    }

TestIterator::~TestIterator(void)
    {
    }

void TestIterator::RunAllTests()
    {
    TestNext();
    TestPrevious();
    TestGetCurrentElement();
    TestGetCurrent();
    TestSetCurrent();
    }

void TestIterator::TestNext()
    {
    Iterator<int> iter;
    int x = 2;
    int y = 3;
    Cell<int>* next = new Cell<int>(&x,NULL,NULL);
    Cell<int>* cellCurrent = new Cell<int>(&y,NULL,next);

    iter.SetCurrent(cellCurrent);

    iter.Next();

    assert(iter.GetCurrentElement() == next->Element);
    }

void TestIterator::TestPrevious()
    {
    Iterator<int> iter;
    int x = 2;
    int y = 3;
    Cell<int>* previous = new Cell<int>(&x,NULL,NULL);
    Cell<int>* cellCurrent = new Cell<int>(&y,previous,NULL);

    iter.SetCurrent(cellCurrent);

    iter.Previous();

    assert(iter.GetCurrentElement() == previous->Element);
    }

void TestIterator::TestGetCurrentElement()
    {
    Iterator<int> iter;
    int x = 2;

    Cell<int>* cellCurrent = new Cell<int>(&x,NULL,NULL);

    iter.SetCurrent(cellCurrent);

    assert(iter.GetCurrent()->Element == cellCurrent->Element);
    }

void TestIterator::TestGetCurrent()
    {
    Iterator<int> iter;
    int x = 2;

    Cell<int>* cellCurrent = new Cell<int>(&x,NULL,NULL);

    iter.SetCurrent(cellCurrent);

    assert(iter.GetCurrent()->Element == cellCurrent->Element);
    }

void TestIterator::TestSetCurrent()
    {
    Iterator<int> iter;
    int x = 2;

    Cell<int>* cellCurrent = new Cell<int>(&x,NULL,NULL);

    iter.SetCurrent(cellCurrent);

    assert(iter.GetCurrent()->Element == cellCurrent->Element);
    }