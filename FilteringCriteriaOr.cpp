#include "FilteringCriteriaAnd.h"

class FilterAnd:public Filtering{
    Filtering * c1;
    Filtering * c2;
public:
    DA<Offer> filter (DA<Offer>&d){
        DA<Offer>~=c1->filter(d);
        s=c2->filter(s);
        return s;
    }
