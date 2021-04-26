#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>

namespace ariel {
    static std::unordered_map<std::string ,std::unordered_map<std:: string, double>> theMap;
    class NumberWithUnits{ 
        public:
        double x;
        std::string s; 
        static void read_units(std::ifstream  &theRead);
        //constractor
         NumberWithUnits(double num,const std::string& n);
         NumberWithUnits(std::string s);
         double getNum();
        std::string gets();
        static double toChange(double theV, const std::string &uunitl, const std::string &uunitr);
        //+ , - , plus onary , minuos onary , += , -= , ++ , --
        NumberWithUnits operator + (const NumberWithUnits& other)const  ;
        NumberWithUnits operator - (const NumberWithUnits& other) const ;
        NumberWithUnits operator - () const;
        NumberWithUnits operator + () const;
        NumberWithUnits& operator += (const NumberWithUnits& other);
        NumberWithUnits& operator -= (const NumberWithUnits& other);
        NumberWithUnits& operator ++( );
        NumberWithUnits& operator -- ();
        NumberWithUnits operator ++ (int);
        NumberWithUnits operator -- (int);
        friend bool operator==(const  ariel::NumberWithUnits&  a , const  ariel::NumberWithUnits&  b);
        friend bool operator!=(const  NumberWithUnits&  a , const  NumberWithUnits&  b);
        friend bool operator<=(const  NumberWithUnits&  a , const  NumberWithUnits&  b);
        friend bool operator>=(const  NumberWithUnits&  a , const  NumberWithUnits&  b);  
        friend bool operator<(const  NumberWithUnits&  a , const  NumberWithUnits&  b);
        friend bool operator>(const  NumberWithUnits&  a ,const  NumberWithUnits&  b);

        friend NumberWithUnits operator* (double Num , const NumberWithUnits &p1);
        NumberWithUnits operator* (double Num);
        friend std::ostream& operator<<(std::ostream& os, const NumberWithUnits& p);
        friend std::istream& operator>>(std::istream& is, NumberWithUnits& p);
        
        
    };
       std::ostream& operator<<(std::ostream& os, const NumberWithUnits& p);
       std::istream& operator>>(std::istream& is, NumberWithUnits& p);
}
