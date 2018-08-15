//
//  main.cpp
//  Regex
//
//  Created by Zidong Yu on 8/14/18.
//  Copyright © 2018 Zidong Yu. All rights reserved.
//
// regex_match example
#include <iostream>
#include <string>
#include <regex>

//Regex Match
int main ()
{
    
    if (std::regex_match ("subject", std::regex("(sub)(.*)") ))
        std::cout << "string literal matched\n";
    
    std::string s ("subject");
    std::regex e ("(sub)(.*)");
    if (std::regex_match (s,e))
        std::cout << "string object matched\n";
    
    if ( std::regex_match ( s.begin(), s.end(), e ) )
        std::cout << "range matched\n";
    
    std::cmatch cm;    // same as std::match_results<const char*> cm;
    std::regex_match ("subject",cm,e);
    std::cout << "string literal with " << cm.size() << " matches\n";
    
    std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
    std::regex_match (s,sm,e);
    std::cout << "string object with " << sm.size() << " matches\n";
    
    std::regex_match ( s.cbegin(), s.cend(), sm, e);
    std::cout << "range with " << sm.size() << " matches\n";
    
    // using explicit flags:
    std::regex_match ( "subject", cm, e, std::regex_constants::match_default );
    
    std::cout << "the matches were: ";
    for (unsigned i=0; i<sm.size(); ++i) {
        std::cout << "[" << sm[i] << "] ";
    }
    
    std::cout << std::endl;
    
    return 0;
}


//Regex Search
//regex_search example
//#include <iostream>
//#include <regex>
//#include <string>
//
//int main(){
//    std::string s ("this subject has a submarine as a subsequence");
//    std::smatch m;
//    std::regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"
//
//    std::cout << "Target sequence: " << s << std::endl;
//    std::cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl;
//    std::cout << "The following matches and submatches were found:" << std::endl;
//
//    while (std::regex_search (s,m,e)) {
//        for (auto x=m.begin();x!=m.end();x++)
//            std::cout << x->str() << " ";
//        std::cout << "--> ([^ ]*) match " << m.format("$2") <<std::endl;
//        s = m.suffix().str();
//    }
//}

//Regex replace
//#include <regex>
//#include <iostream>
//
//int main() {
//    char buf[20];
//    const char *first = "axayaz";
//    const char *last = first + strlen(first);
//    std::regex rx("a");
//    std::string fmt("A");
//    std::regex_constants::match_flag_type fonly =
//    std::regex_constants::format_first_only;
//
//    *std::regex_replace(&buf[0], first, last, rx, fmt) = '\0';
//    std::cout << &buf[0] << std::endl;
//
//    *std::regex_replace(&buf[0], first, last, rx, fmt, fonly) = '\0';
//    std::cout << &buf[0] << std::endl;
//
//    std::string str("adaeaf");
//    std::cout << std::regex_replace(str, rx, fmt) << std::endl;
//
//    std::cout << std::regex_replace(str, rx, fmt, fonly) << std::endl;
//
//    return 0;
//}
