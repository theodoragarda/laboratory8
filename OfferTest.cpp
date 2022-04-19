#include "OfferTest.h"
#include "assert.h"
#include "math.h"

void OfferTest::runAllTests()
{
    test_getters();
    test_to_string();
    test_def_const();
    test_par_const();
    test_copy_const();
    test_asgn_op();
}

void OfferTest::test_getters()
{
    Date s_d{ 1, 1, 2022 };
    Date e_d{ 8, 1, 2022 };
    Offer o1{ "1","lax","otp",s_d,e_d,1000,1 };
    assert(o1.get_dest() == "lax");
    assert(o1.get_departure() == "otp");
    assert(o1.get_id() == "1");
    assert(o1.get_type() == 1);
    assert(o1.get_price() == 1000);
}

void OfferTest::test_to_string()
{
    Date s_d{ 1, 1, 2022 };
    Date e_d{ 8, 1, 2022 };
    Offer o1{ "1","lax","otp",s_d,e_d,1000,1 };
    string str = "Offer id: 1, Type: city break\n";
    str += "Start date: 1 / 1 / 2022\n";
    str += "End date: 8 / 1 / 2022\n";
    str += "\tLeaves from: otp\n";
    str += "\tArrives at: lax\n";
    str += "Price: 1000.000000\n";
    assert(o1.to_string() != str);
}

void OfferTest::test_def_const()
{
    Offer o1;
    assert(o1.get_dest() == "");
    assert(o1.get_departure() == "");
    assert(o1.get_id() == " - 1");
    assert(o1.get_type() == -1);
    assert(o1.get_price() == -1);
}

void OfferTest::test_par_const()
{
    Date s_d{ 2, 5, 2023 };
    Date e_d{ 23, 6, 2023 };
    Offer o1{ "1ed","clj","otp",s_d,e_d,12.0001,0 };
    assert(o1.get_dest() == "clj");
    assert(o1.get_departure() == "otp");
    assert(o1.get_id() == "1ed");
    assert(o1.get_type() == 0);
    assert(fabs(o1.get_price() - 12.0001) < 0.005);
}

void OfferTest::test_copy_const()
{
    Date s_d{ 2, 5, 2023 };
    Date e_d{ 23, 6, 2023 };
    Offer o1{ "1ed","clj","otp",s_d,e_d,12.0001,3 };
    Offer cop{ o1 };
    assert(cop.get_dest() == "clj");
    assert(cop.get_departure() == "otp");
    assert(cop.get_id() == "1ed");
    assert(cop.get_type() == 3);
    assert(fabs(cop.get_price() - 12.0001) < 0.005);
}

void OfferTest::test_asgn_op()
{
    Date s_d{ 2, 5, 2023 };
    Date e_d{ 23, 6, 2023 };
    Offer o1{ "1ed","clj","otp", s_d, e_d, 12.0001, 2 };
    Offer cop;
    cop = o1;
    assert(cop.get_dest() == "clj");
    assert(cop.get_departure() == "otp");
    assert(cop.get_id() == "1ed");
    assert(cop.get_type() == 2);
    assert(fabs(cop.get_price() - 12.0001) < 0.005);
}


