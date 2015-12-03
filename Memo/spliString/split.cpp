1. using built in function, Making sure to add header file
complier instruction :
//g++ -I/usr/local/include

#include <boost/algorithm/string.hpp>
 std::vector<std::string> strs;
 boost::split(strs, "string to split", boost::is_any_of("\t "));
 
 //std::string str = "HELLO, WORLD!";
 //boost::algorithm::to_lower(str);
 
 2. using stringstream
 a.
 #include <sstream>
 (1)istream& getline (istream& is, string& str, char delim);
 (2) istream& getline (istream& is, string& str);
 default delim is ' ';
 ex: 
   while (std::getline(ss, item, delim)) {
         elems.push_back(item);
    }
 
 (3)
 operator>> (string)  // delimitation is space or new line '\n'; 
 ex:
 stringstream in(inputstring);
 while(in >> string){
 elems.push_back(item);
 }
 
 
 
 java could use 
string [] words = str.split(" ");
 
 
 
 
