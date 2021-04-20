#include "doctest.h"
#include <iostream>
#include <sstream>
#include "NumberWithUnits.hpp"
#include <string>
using namespace std;
using namespace ariel;

TEST_CASE("GOOD PLUS"){
ifstream units("units.txt");
NumberWithUnits::read_units(units);
NumberWithUnits xkm{1, "km"};
NumberWithUnits ym{600, "m"};
NumberWithUnits zcm{60, "cm"};
NumberWithUnits tkm{5, "km"};

CHECK_EQ((xkm + ym) , NumberWithUnits{"1.6[km]"});
CHECK_EQ((xkm + tkm) , NumberWithUnits{"6[km]"});
CHECK_EQ((ym + zcm) , NumberWithUnits{"600.60[m]"});
CHECK_EQ((xkm + zcm) , NumberWithUnits{"1.00060[km]"});
CHECK_EQ((xkm + tkm + ym) , NumberWithUnits{"6.6[km]"});
CHECK_EQ((ym + zcm + tkm) , NumberWithUnits{"5600.60[M]"});

NumberWithUnits xhour{1, "hour"};
NumberWithUnits ymin{600, "min"};
NumberWithUnits zsec{60, "sec"};
NumberWithUnits thour{6, "hour"};


CHECK_EQ((xhour + thour) , NumberWithUnits{"7[hour]"});
CHECK_EQ((xhour + ymin) , NumberWithUnits{"11[hour]"});
CHECK_EQ((xhour + zsec) , NumberWithUnits{"1.0100[hour]"});
CHECK_EQ((ymin + xhour) , NumberWithUnits{"660[min]"});
CHECK_EQ((ymin + thour) , NumberWithUnits{"960[min]"});

NumberWithUnits xton{6, "ton"};
NumberWithUnits ykg{600, "kg"};
NumberWithUnits zg{6, "g"};


CHECK_EQ((xton + ykg) , NumberWithUnits{"6.6[ton]"});
CHECK_EQ((ykg + zg) , NumberWithUnits{"600.006[kg]"});

NumberWithUnits xusd{4, "USD"};
NumberWithUnits xusd2{5, "USD"};

CHECK_EQ((xusd + xusd2) , NumberWithUnits{"9[USD]"});

}

TEST_CASE("GOOD MINUS"){
NumberWithUnits xkm{1, "km"};
NumberWithUnits ym{600, "m"};
NumberWithUnits zcm{60, "cm"};
NumberWithUnits tkm{5, "km"};

CHECK_EQ((xkm - ym) , NumberWithUnits{"0.4[km]"});
CHECK_EQ((tkm - xkm) , NumberWithUnits{"4[km]"});
CHECK_EQ((ym - zcm) , NumberWithUnits{"599.40[m]"});
CHECK_EQ((xkm - zcm) , NumberWithUnits{"0.99940[km]"});
CHECK_EQ((tkm - xkm - ym) , NumberWithUnits{"4.4[km]"});

NumberWithUnits xhour{1, "hour"};
NumberWithUnits ymin{6, "min"};
NumberWithUnits zsec{60, "sec"};
NumberWithUnits thour{6, "hour"};


CHECK_EQ((thour - xhour) , NumberWithUnits{"5[hour]"});
CHECK_EQ((xhour - ymin) , NumberWithUnits{"0.54[hour]"});
CHECK_EQ((xhour - zsec) , NumberWithUnits{"0.59[hour]"});
CHECK_EQ((thour - ymin) , NumberWithUnits{"354[min]"});


NumberWithUnits xton{6, "ton"};
NumberWithUnits ykg{600, "kg"};
NumberWithUnits zg{6, "g"};


CHECK_EQ((xton - ykg) , NumberWithUnits{"5.4[ton]"});
CHECK_EQ((ykg - zg) , NumberWithUnits{"599.994[kg]"});

NumberWithUnits xusd{4, "USD"};
NumberWithUnits xusd2{5, "USD"};

CHECK_EQ((xusd - xusd2) ,NumberWithUnits{"-1[USD]"});



}


TEST_CASE("GOOD +="){
NumberWithUnits xkm{1, "km"};
NumberWithUnits ym{600, "m"};
NumberWithUnits zcm{60, "cm"};
NumberWithUnits tkm{5, "km"};

CHECK_EQ((xkm += ym) , NumberWithUnits{"1.6[km]"});
CHECK_EQ((xkm += tkm) , NumberWithUnits{"6[km]"});
CHECK_EQ((ym += zcm) , NumberWithUnits{"600.60[m]"});
CHECK_EQ((xkm += zcm) , NumberWithUnits{"1.00060[km]"});
CHECK_EQ((xkm += tkm + ym) , NumberWithUnits{"6.6[km]"});
CHECK_EQ((ym += zcm + tkm) , NumberWithUnits{"5600.60[M]"});

NumberWithUnits xhour{1, "hour"};
NumberWithUnits ymin{600, "min"};
NumberWithUnits zsec{60, "sec"};
NumberWithUnits thour{6, "hour"};


CHECK_EQ((xhour += thour) , NumberWithUnits{"7[hour]"});
CHECK_EQ((xhour += ymin) , NumberWithUnits{"11[hour]"});
CHECK_EQ((xhour += zsec) , NumberWithUnits{"1.0100[hour]"});
CHECK_EQ((ymin += xhour) , NumberWithUnits{"660[min]"});
CHECK_EQ((ymin += thour) , NumberWithUnits{"960[min]"});

NumberWithUnits xton{6, "ton"};
NumberWithUnits ykg{600, "kg"};
NumberWithUnits zg{6, "g"};


CHECK_EQ((xton += ykg) , NumberWithUnits{"6.6[ton]"});
CHECK_EQ((ykg += zg) , NumberWithUnits{"600.006[kg]"});

NumberWithUnits xusd{4, "USD"};
NumberWithUnits xusd2{5, "USD"};

CHECK_EQ((xusd += xusd2) ,NumberWithUnits{"9[USD]"});

}








TEST_CASE("GOOD -="){
NumberWithUnits xkm{1, "km"};
NumberWithUnits ym{600, "m"};
NumberWithUnits zcm{60, "cm"};
NumberWithUnits tkm{5, "km"};

CHECK_EQ((xkm -= ym) , NumberWithUnits{"0.4[km]"});
CHECK_EQ((tkm -= xkm) , NumberWithUnits{"4[km]"});
CHECK_EQ((ym -= zcm) , NumberWithUnits{"599.40[m]"});
CHECK_EQ((xkm -= zcm) , NumberWithUnits{"0.99940[km]"});
CHECK_EQ((tkm -= xkm - ym) , NumberWithUnits{"4.4[km]"});

NumberWithUnits xhour{1, "hour"};
NumberWithUnits ymin{6, "min"};
NumberWithUnits zsec{60, "sec"};
NumberWithUnits thour{6, "hour"};


CHECK_EQ((thour -= xhour) , NumberWithUnits{"5[hour]"});
CHECK_EQ((xhour -= ymin) , NumberWithUnits{"0.54[hour]"});
CHECK_EQ((xhour -= zsec) , NumberWithUnits{"0.59[hour]"});
CHECK_EQ((thour -= ymin) , NumberWithUnits{"354[min]"});


NumberWithUnits xton{6, "ton"};
NumberWithUnits ykg{600, "kg"};
NumberWithUnits zg{6, "g"};


CHECK_EQ((xton -= ykg) , NumberWithUnits{"5.4[ton]"});
CHECK_EQ((ykg -= zg) , NumberWithUnits{"599.994[kg]"});

NumberWithUnits xusd{4, "USD"};
NumberWithUnits xusd2{5, "USD"};

CHECK_EQ((xusd -= xusd2) , NumberWithUnits{"-1[USD]"});

}
TEST_CASE("GOOD ++$$--"){
NumberWithUnits xkm{1, "km"};
NumberWithUnits ym{600, "m"};
NumberWithUnits zcm{60, "cm"};
NumberWithUnits tkm{5, "km"};

CHECK_EQ((xkm++) , NumberWithUnits{"2[km]"});
CHECK_EQ((tkm++) , NumberWithUnits{"6[km]"});
CHECK_EQ((ym++) , NumberWithUnits{"601[m]"});
CHECK_EQ((zcm++) , NumberWithUnits{"0.61[cm]"});
CHECK_EQ((xkm--) , NumberWithUnits{"1[km]"});
CHECK_EQ((tkm--) , NumberWithUnits{"5[km]"});
CHECK_EQ((ym--) , NumberWithUnits{"600[m]"});
CHECK_EQ((zcm--) , NumberWithUnits{"0.60[cm]"});


NumberWithUnits xhour{1, "hour"};
NumberWithUnits ymin{600, "min"};
NumberWithUnits zsec{60, "sec"};
NumberWithUnits thour{6, "hour"};


CHECK_EQ((xhour++) , NumberWithUnits{"2[hour]"});
CHECK_EQ((ymin++) , NumberWithUnits{"601[min]"});
CHECK_EQ((zsec++) , NumberWithUnits{"61[sec]"});
CHECK_EQ((thour++) , NumberWithUnits{"7[min]"});
CHECK_EQ((xhour--) , NumberWithUnits{"1[hour]"});
CHECK_EQ((ymin--) , NumberWithUnits{"600[min]"});
CHECK_EQ((zsec--) , NumberWithUnits{"60[sec]"});
CHECK_EQ((thour--) , NumberWithUnits{"6[hour]"});

NumberWithUnits xton{6, "ton"};
NumberWithUnits ykg{600, "kg"};
NumberWithUnits zg{6, "g"};


CHECK_EQ((xton++) , NumberWithUnits{"7[ton]"});
CHECK_EQ((ykg++) , NumberWithUnits{"601[kg]"});
CHECK_EQ((xton--) , NumberWithUnits{"6[ton]"});
CHECK_EQ((ykg--) , NumberWithUnits{"600[kg]"});

NumberWithUnits xusd{4, "USD"};
CHECK_EQ((xusd++) ,NumberWithUnits{"5[USD]"});
}

TEST_CASE("GOOD >&&>=&&<&<=&&==&&!="){
NumberWithUnits xkm{1, "km"};
NumberWithUnits ym{600, "m"};
NumberWithUnits zcm{60, "cm"};
NumberWithUnits tkm{5, "km"};

CHECK_EQ((tkm >= xkm) , true);
CHECK_EQ((tkm != xkm) , true);
CHECK_EQ((tkm == xkm) , false);
CHECK_EQ((ym <= zcm) , false);
CHECK_EQ((ym < zcm) , false);
CHECK_EQ((xkm < tkm) , true);



}