
#include <iostream>
#include <sstream>
#include <fstream>
#include "NumberWithUnits.hpp"
#include <string>
using namespace ariel;
using namespace std;
std::unordered_map<std::string ,std::unordered_map<std::string, double>> NumberWithUnits::theMap;
NumberWithUnits::NumberWithUnits(){};
NumberWithUnits::NumberWithUnits(double _num, std::string n){
    x = _num;
    s = n;
}
void NumberWithUnits::read_units(std::ifstream  &theRead){
   std:: string left;
    std:: string right;
    std:: string s;
    double dr;
    double dl;
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
        NumberWithUnits::theMap[unitr][unitl]=dl; 
        NumberWithUnits::theMap[unitl][unitr]=1/dl;
           
}

        for(auto const& Key:theMap){
        for(auto const& KeyTwo:Key.second){
        std::cout<<Key.first << " : " << KeyTwo.first << " : " << KeyTwo.second << std::endl;}}
}
    NumberWithUnits NumberWithUnits::operator+(NumberWithUnits &other) {
        x = x + theMap[other.s][s]*other.x;
        return other;
     }
        NumberWithUnits NumberWithUnits:: operator- ( NumberWithUnits& other){
            return other;
        }
        NumberWithUnits NumberWithUnits:: operator- (){
            return NumberWithUnits() ;
        }
        NumberWithUnits NumberWithUnits:: operator+ () const{
            return NumberWithUnits();
        }
        NumberWithUnits& NumberWithUnits:: operator+= (const NumberWithUnits& other){
            if (theMap[other.s].find(s) != theMap[other.s].end()){
               this->x = this->x + theMap[other.s][s];
            }
            return *this;
        }
        NumberWithUnits& NumberWithUnits:: operator-= (const NumberWithUnits& other){
            if (theMap[other.s].find(s) != theMap[other.s].end()){
            this->x = this->x - theMap[other.s][s];
            }
            return *this;
        }
        NumberWithUnits& NumberWithUnits:: operator++( ){
            x++;
            return *this;
        }
        NumberWithUnits& NumberWithUnits:: operator -- (){
            x--;
            return *this;
        }
        NumberWithUnits NumberWithUnits:: operator++ (int){
            x++;
            return *this;
        }
        NumberWithUnits NumberWithUnits:: operator-- (int){
            x--;
            return *this;
        }

        bool ariel::operator==(const  NumberWithUnits&  a , const  NumberWithUnits&  b) {
            double a1 = a.x;
            double b1 = b.x;
            if(a1 > b1){
                a1 = (a1/a1)*b1;
                if (a1 != b1 ){
                return false;
            }
            }
            else if(a1 < b1){   
               b1 = (b1/b1)*a1;
                if (a1 != b1 ){
                return false;
            } 
            }
            
            return true;
        }
        bool ariel::operator!=(const  NumberWithUnits&  a , const  NumberWithUnits&  b) {
             double a1 = b.x;
             double b1 = a.x;
             if (a1 == b1){
                 return false;
             }
             return true;
        }
        bool ariel::operator<=(const  NumberWithUnits&  a , const  NumberWithUnits&  b) {
            double a1 = b.x;
             double b1 = a.x;
             if (a1 > b1){
                 return false;
             }
            return true;
        }
        bool ariel::operator>=(const  NumberWithUnits&  a , const  NumberWithUnits&  b) {
            double a1 = b.x;
            double b1 = a.x;
             if (a1 < b1){
                 return false;
             }
             return true;
        }  
        bool ariel::operator<(const  NumberWithUnits&  a , const  NumberWithUnits&  b) {
            double a1 = b.x;
             double b1 = a.x;
             if (a1 >= b1){
                 return false;
             }
            return true;
        }
        bool ariel::operator>(const  NumberWithUnits&  a ,const  NumberWithUnits&  b) {
            double a1 = b.x;
             double b1 = a.x;
             if (a1 <= b1){
                 return false;
             }
            return true;
        }
    
        double ariel::operator* (double Num , const NumberWithUnits &p1){
        //  double d = Num*theMap[p1.s][s]*p1.x;
        //  return d;
        return Num;
     }
        double NumberWithUnits::operator*(double num){
            return num;
        }
         std::ostream& ariel::operator<<(std::ostream& os, const NumberWithUnits& p){
             return os;
        }
         std::istream& ariel::operator>>(std::istream& is, NumberWithUnits& p){
             return is;
        }
