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

CHECK_EQ((xkm + ym) , "1.6[km]");
CHECK_EQ((xkm + tkm) , "6[km]");
CHECK_EQ((ym + zcm) , "600.60[m]");
CHECK_EQ((xkm + zcm) , "1.00060[km]");
CHECK_EQ((xkm + tkm + ym) , "6.6[km]");
CHECK_EQ((ym + zcm + tkm) , "5600.60[M]");

NumberWithUnits xhour{1, "hour"};
NumberWithUnits ymin{600, "min"};
NumberWithUnits zsec{60, "sec"};
NumberWithUnits thour{6, "hour"};


CHECK_EQ((xhour + thour) , "7[hour]");
CHECK_EQ((xhour + ymin) , "11[hour]");
CHECK_EQ((xhour + zsec) , "1.0100[hour]");
CHECK_EQ((ymin + xhour) , "660[min]");
CHECK_EQ((ymin + thour) , "960[min]");

NumberWithUnits xton{6, "ton"};
NumberWithUnits ykg{600, "kg"};
NumberWithUnits zg{6, "g"};


CHECK_EQ((xton + ykg) , "6.6[ton]");
CHECK_EQ((ykg + zg) , "600.006[kg]");

NumberWithUnits xusd{4, "USD"};
NumberWithUnits xusd2{5, "USD"};

CHECK_EQ((xusd + xusd2) ,"9[USD]");

}

TEST_CASE("GOOD MINUS"){
ifstream units("units.txt");
NumberWithUnits::read_units(units);
NumberWithUnits xkm{1, "km"};
NumberWithUnits ym{600, "m"};
NumberWithUnits zcm{60, "cm"};
NumberWithUnits tkm{5, "km"};

CHECK_EQ((xkm - ym) , "0.4[km]");
CHECK_EQ((tkm - xkm) , "4[km]");
CHECK_EQ((ym - zcm) , "599.40[m]");
CHECK_EQ((xkm - zcm) , "0.99940[km]");
CHECK_EQ((tkm - xkm - ym) , "4.4[km]");

NumberWithUnits xhour{1, "hour"};
NumberWithUnits ymin{6, "min"};
NumberWithUnits zsec{60, "sec"};
NumberWithUnits thour{6, "hour"};


CHECK_EQ((thour - xhour) , "5[hour]");
CHECK_EQ((xhour - ymin) , "0.54[hour]");
CHECK_EQ((xhour - zsec) , "0.59[hour]");
CHECK_EQ((thour - ymin) , "354[min]");


NumberWithUnits xton{6, "ton"};
NumberWithUnits ykg{600, "kg"};
NumberWithUnits zg{6, "g"};


CHECK_EQ((xton - ykg) , "5.4[ton]");
CHECK_EQ((ykg - zg) , "599.994[kg]");

NumberWithUnits xusd{4, "USD"};
NumberWithUnits xusd2{5, "USD"};

CHECK_EQ((xusd - xusd2) ,"-1[USD]");



}


TEST_CASE("GOOD +="){
ifstream units("units.txt");
NumberWithUnits::read_units(units);
NumberWithUnits xkm{1, "km"};
NumberWithUnits ym{600, "m"};
NumberWithUnits zcm{60, "cm"};
NumberWithUnits tkm{5, "km"};

CHECK_EQ((xkm += ym) , "1.6[km]");
CHECK_EQ((xkm += tkm) , "6[km]");
CHECK_EQ((ym += zcm) , "600.60[m]");
CHECK_EQ((xkm += zcm) , "1.00060[km]");
CHECK_EQ((xkm += tkm + ym) , "6.6[km]");
CHECK_EQ((ym += zcm + tkm) , "5600.60[M]");

NumberWithUnits xhour{1, "hour"};
NumberWithUnits ymin{600, "min"};
NumberWithUnits zsec{60, "sec"};
NumberWithUnits thour{6, "hour"};


CHECK_EQ((xhour += thour) , "7[hour]");
CHECK_EQ((xhour += ymin) , "11[hour]");
CHECK_EQ((xhour += zsec) , "1.0100[hour]");
CHECK_EQ((ymin += xhour) , "660[min]");
CHECK_EQ((ymin += thour) , "960[min]");

NumberWithUnits xton{6, "ton"};
NumberWithUnits ykg{600, "kg"};
NumberWithUnits zg{6, "g"};


CHECK_EQ((xton += ykg) , "6.6[ton]");
CHECK_EQ((ykg += zg) , "600.006[kg]");

NumberWithUnits xusd{4, "USD"};
NumberWithUnits xusd2{5, "USD"};

CHECK_EQ((xusd += xusd2) ,"9[USD]");

}








TEST_CASE("GOOD -="){
ifstream units("units.txt");
NumberWithUnits::read_units(units);
NumberWithUnits xkm{1, "km"};
NumberWithUnits ym{600, "m"};
NumberWithUnits zcm{60, "cm"};
NumberWithUnits tkm{5, "km"};

CHECK_EQ((xkm -= ym) , "0.4[km]");
CHECK_EQ((tkm -= xkm) , "4[km]");
CHECK_EQ((ym -= zcm) , "599.40[m]");
CHECK_EQ((xkm -= zcm) , "0.99940[km]");
CHECK_EQ((tkm -= xkm - ym) , "4.4[km]");

NumberWithUnits xhour{1, "hour"};
NumberWithUnits ymin{6, "min"};
NumberWithUnits zsec{60, "sec"};
NumberWithUnits thour{6, "hour"};


CHECK_EQ((thour -= xhour) , "5[hour]");
CHECK_EQ((xhour -= ymin) , "0.54[hour]");
CHECK_EQ((xhour -= zsec) , "0.59[hour]");
CHECK_EQ((thour -= ymin) , "354[min]");


NumberWithUnits xton{6, "ton"};
NumberWithUnits ykg{600, "kg"};
NumberWithUnits zg{6, "g"};


CHECK_EQ((xton -= ykg) , "5.4[ton]");
CHECK_EQ((ykg -= zg) , "599.994[kg]");

NumberWithUnits xusd{4, "USD"};
NumberWithUnits xusd2{5, "USD"};

CHECK_EQ((xusd -= xusd2) ,"-1[USD]");

}
TEST_CASE("GOOD ++$$--"){
ifstream units("units.txt");
NumberWithUnits::read_units(units);
NumberWithUnits xkm{1, "km"};
NumberWithUnits ym{600, "m"};
NumberWithUnits zcm{60, "cm"};
NumberWithUnits tkm{5, "km"};

CHECK_EQ((xkm++) , "2[km]");
CHECK_EQ((tkm++) , "6[km]");
CHECK_EQ((ym++) , "601[m]");
CHECK_EQ((zcm++) , "0.61[cm]");
CHECK_EQ((xkm--) , "1[km]");
CHECK_EQ((tkm--) , "5[km]");
CHECK_EQ((ym--) , "600[m]");
CHECK_EQ((zcm--) , "0.60[cm]");


NumberWithUnits xhour{1, "hour"};
NumberWithUnits ymin{600, "min"};
NumberWithUnits zsec{60, "sec"};
NumberWithUnits thour{6, "hour"};


CHECK_EQ((xhour++) , "2[hour]");
CHECK_EQ((ymin++) , "601[min]");
CHECK_EQ((zsec++) , "61[sec]");
CHECK_EQ((thour++) , "7[min]");
CHECK_EQ((xhour--) , "1[hour]");
CHECK_EQ((ymin--) , "600[min]");
CHECK_EQ((zsec--) , "60[sec]");
CHECK_EQ((thour--) , "6[hour]");

NumberWithUnits xton{6, "ton"};
NumberWithUnits ykg{600, "kg"};
NumberWithUnits zg{6, "g"};


CHECK_EQ((xton++) , "7[ton]");
CHECK_EQ((ykg++) , "601[kg]");
CHECK_EQ((xton--) , "6[ton]");
CHECK_EQ((ykg--) , "600[kg]");

NumberWithUnits xusd{4, "USD"};
CHECK_EQ((xusd++) ,"5[USD]");
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