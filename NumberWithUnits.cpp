
#include <iostream>
#include <sstream>
#include <fstream>
#include "NumberWithUnits.hpp"
#include <string>
using namespace ariel;
using namespace std;
const double closeZero = 0.00001;
std::unordered_map<std::string ,std::unordered_map<std::string, double>> theMap;
NumberWithUnits::NumberWithUnits(double _num, const std::string& n){
    try {
            theMap.at(n);
            }
        catch(const exception& e) {
            throw invalid_argument{"not exsist" };
        }
    x = _num;
    s = n;
}

void NumberWithUnits::read_units(std::ifstream  &theRead){
   std:: string left;
    std:: string right;
    std:: string s;
    double dr = 0;
    double dl = 0;
    std:: string unitr;
    std:: string unitl;
    while (getline(theRead,s)){
        left = s.substr(0,s.find('='));
        right = s.substr(s.find('=')+1); //1 km = 1000 m
        std:: istringstream temp(right);
        std:: istringstream temp2(left);//temp2 = 1km   
        temp>>dl; //temp2 = km
        temp>>unitl;
        temp2>>dr; //1000
        temp2>>unitr;  // m
        theMap[unitr][unitl]=dl;
        theMap[unitr][unitr]=1; 
        theMap[unitl][unitr]=1/dl;
        for(auto const& theKeyOfMap:theMap[unitr]){
          double w = theMap[unitl][unitr]*theKeyOfMap.second;
                theMap[unitl][theKeyOfMap.first] = w;
                theMap[theKeyOfMap.first][unitl] = 1/w;
        }
        for(auto const& theKeyOfMap:theMap[unitl]){
          double w = theMap[unitr][unitl]*theKeyOfMap.second;
                theMap[unitr][theKeyOfMap.first] = w;
                theMap[theKeyOfMap.first][unitr] = 1/w;
        }
}
        
}


        double NumberWithUnits::toChange(double theV, const std::string &uunitl, const std::string &uunitr){
         
        if(uunitl == uunitr) {
            return theV;
        }
        try {
            return theV*theMap.at(uunitl).at(uunitr);
        }
        catch(const exception& e) {
            throw invalid_argument{"Units do not match - ["+uunitl+"] cannot be converted to ["+uunitr+"]"};
        }
    }

    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &other)const {
        std::string s1 = s;
        double tor = toChange(other.x ,other.s ,s1);
        return NumberWithUnits(this->x + tor ,this->s);
     }
        NumberWithUnits NumberWithUnits:: operator- (const NumberWithUnits& other)const{
            double tor = toChange(other.x ,other.s ,s);
        return NumberWithUnits(this->x - tor ,this->s);
        }

        NumberWithUnits NumberWithUnits:: operator- ()const{
            return NumberWithUnits(-1 * x, s);
        }

        NumberWithUnits NumberWithUnits:: operator+ () const{
            return NumberWithUnits(1*x ,s);
        }

        NumberWithUnits& NumberWithUnits:: operator+= (const NumberWithUnits& other){
           double tor = toChange(other.x ,other.s ,s);
           this->x = this->x + tor;
           return *this;
        }
        NumberWithUnits& NumberWithUnits:: operator-= (const NumberWithUnits& other){
            double tor = toChange(other.x ,other.s ,s);
           this->x = this->x - tor;
           return *this;
        }

        NumberWithUnits& NumberWithUnits:: operator++( ){
            ++x;
            return *this;
        }

        NumberWithUnits& NumberWithUnits:: operator -- (){
            --x;
            return *this;
        }

        NumberWithUnits NumberWithUnits:: operator++ (int){
            NumberWithUnits temp(x ,s);
            x++;
            return temp;
        }
        
        NumberWithUnits NumberWithUnits:: operator-- (int){
            NumberWithUnits temp(x ,s);
            x--;
            return temp;
        }
        
        bool ariel::operator==(const  ariel::NumberWithUnits&  a , const  ariel::NumberWithUnits&  b) {
         
            double trueOrfalse2 = b.x - a.toChange(a.x ,a.s ,b.s);
           
            return abs(trueOrfalse2)<closeZero;
        }

        bool ariel::operator!=(const  NumberWithUnits&  a , const  NumberWithUnits&  b) {
            double trueOrfalse2 = b.x - a.toChange(a.x ,a.s ,b.s);
           
            return !(abs(trueOrfalse2)<closeZero);
        }
        
        bool ariel::operator<=(const  NumberWithUnits&  a , const  NumberWithUnits&  b) {
            double trueOrfalse2 = a.toChange(a.x ,a.s ,b.s) - b.x;
           
            return abs(trueOrfalse2)<closeZero || trueOrfalse2<-closeZero;
        }

        bool ariel::operator>=(const  NumberWithUnits&  a , const  NumberWithUnits&  b) {
            double trueOrfalse2 = a.toChange(a.x ,a.s ,b.s) - b.x;
           
            return abs(trueOrfalse2)<closeZero || trueOrfalse2>closeZero;
        }

        bool ariel::operator<(const  NumberWithUnits&  a , const  NumberWithUnits&  b) {
            double trueOrfalse2 = a.toChange(a.x ,a.s ,b.s) - b.x;
           
            return  trueOrfalse2<-closeZero;
        }
        
        bool ariel::operator>(const  NumberWithUnits&  a ,const  NumberWithUnits&  b) {
            double trueOrfalse2 = a.toChange(a.x ,a.s ,b.s) - b.x;
           
            return  trueOrfalse2>closeZero;
        }
    
        NumberWithUnits ariel::operator* (double Num , const NumberWithUnits &p1){
        return NumberWithUnits(Num*p1.x , p1.s);
     }

        NumberWithUnits NumberWithUnits::operator* (double Num){
            return NumberWithUnits(Num*(this->x) , s);
        }

         std::ostream& ariel::operator<<(std::ostream& os, const NumberWithUnits& p){
             
             return (os << p.x << "[" << p.s << "]");
        }

         std::istream& ariel::operator>>(std::istream& is, NumberWithUnits& p){
             char a = ' ';
             std::string t;
             while(is.get(a)){
                 if(a==' '){
                     continue;
                 }
                 if(a=='['){
                    break;
                    }
                t+=a;
                    
             }
            std:: string l ;
             while(is.get(a)){
                  if(a==' '){
                     continue;
                 }
                 if(a==']'){
                    break;
                    }
                l+=a;
                    
             }

             p.x =stod(t);
             p.s =l;
             try{
                theMap.at(p.s);
             }
             catch(const exception& e) {
            throw invalid_argument{"not exsist"};
            }
            
             return is;
        }

