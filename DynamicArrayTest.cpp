#include "DynamicArrayTest.h"
#include <assert.h>
#include <iostream>
void DynamicArrayTest::runAllTests()
{
    test_def_constr();
    test_append();
    test_get();
    test_assign_op();
    test_copy_const();
    test_resize();
}

void DynamicArrayTest::test_def_constr()
{
    DynamicArray temp;
    assert(temp.getCapacity() == 100);
    assert(temp.getLength() == 0);
}

void DynamicArrayTest::test_append()
{
    DynamicArray temp{ 1 };
    Date s_d{ 1, 1, 2022 };
    Date e_d{ 8, 1, 2022 };
    Offer o1{ "1","lax","otp",s_d,e_d,1000,1 };
    temp.append(o1);
    assert(temp.get(0) == o1);
}

void DynamicArrayTest::test_get()
{
    DynamicArray temp{ 2 };
    Date s_d{ 1, 1, 2022 };
    Date e_d{ 8, 1, 2022 };
    Offer o1{ "1","lax","otp",s_d,e_d,1000,1 };
    Offer o2{ "2","otp","lax",e_d,s_d,1100,2 };
    temp.append(o1);
    temp.append(o2);
    assert(temp.get(0) == o1);
    assert(temp.get(1) == o2);
}

void DynamicArrayTest::test_assign_op()
{
    DynamicArray temp{ 2 };
    Date s_d{ 1, 1, 2022 };
    Date e_d{ 8, 1, 2022 };
    Offer o1{ "1","lax","otp",s_d,e_d,1000,1 };
    Offer o2{ "2","otp","lax",e_d,s_d,1100,2 };
    temp.append(o1);
    temp.append(o1);
    DynamicArray temp2{ 2 };
    temp2 = temp;
    assert(temp2.get(0) == temp.get(0));
}

void DynamicArrayTest::test_copy_const()
{
    DynamicArray temp{ 2 };
    Date s_d{ 1, 1, 2022 };
    Date e_d{ 8, 1, 2022 };
    Offer o1{ "1","lax","otp",s_d,e_d,1000,1 };
    Offer o2{ "2","otp","lax",e_d,s_d,1100,2 };
    temp.append(o1);
    temp.append(o1);
    DynamicArray temp2{ temp };
    assert(temp2.get(0) == temp.get(0));
}

void DynamicArrayTest::test_resize()
{
    DynamicArray temp{ 1 };
    Date s_d{ 1, 1, 2022 };
    Date e_d{ 8, 1, 2022 };
    Offer o1{ "1","lax","otp",s_d,e_d,1000,1 };
    Offer o2{ "2","otp","lax",e_d,s_d,1100,2 };
    temp.append(o1);
    assert(temp.getCapacity() == 1);
    temp.append(o1);
    assert(temp.getCapacity() == 2);
    temp.append(o1);
    temp.append(o1);
    assert(temp.getCapacity() == 4);
}
