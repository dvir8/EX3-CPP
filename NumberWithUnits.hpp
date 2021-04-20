#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>

namespace ariel {
    
    class NumberWithUnits{ 
        public:
        static std::unordered_map<std::string ,std::unordered_map<std:: string, double>> theMap;
        double x;
        std::string s; 
        static void read_units(std::ifstream  &theRead);
        //constractor
         NumberWithUnits(double num,std::string s);
         NumberWithUnits(std::string s);
         double getNum();
        std::string gets();
        //+ , - , plus onary , minuos onary , += , -= , ++ , --
        NumberWithUnits operator + ( NumberWithUnits& other)  ;
        NumberWithUnits operator - ( NumberWithUnits& other)  ;
        NumberWithUnits operator - () ;
        NumberWithUnits operator + () const;
        NumberWithUnits& operator += (const NumberWithUnits& other);
        NumberWithUnits& operator -= (const NumberWithUnits& other);
        NumberWithUnits& operator ++( );
        NumberWithUnits& operator -- ();
        NumberWithUnits operator ++ (int);
        NumberWithUnits operator -- (int);

        friend bool operator==(const  NumberWithUnits&  a , const  NumberWithUnits&  b);
        friend bool operator!=(const  NumberWithUnits&  a , const  NumberWithUnits&  b);
        friend bool operator<=(const  NumberWithUnits&  a , const  NumberWithUnits&  b);
        friend bool operator>=(const  NumberWithUnits&  a , const  NumberWithUnits&  b);  
        friend bool operator<(const  NumberWithUnits&  a , const  NumberWithUnits&  b);
        friend bool operator>(const  NumberWithUnits&  a ,const  NumberWithUnits&  b);

        friend double operator* (double Num , const NumberWithUnits &p1);
        double operator*(double num);
        friend std::ostream& operator<<(std::ostream& os, const NumberWithUnits& p);
        friend std::istream& operator>>(std::istream& is, NumberWithUnits& p);
        NumberWithUnits();
        
    };
       std::ostream& operator<<(std::ostream& os, const NumberWithUnits& p);
       std::istream& operator>>(std::istream& is, NumberWithUnits& p);
}
