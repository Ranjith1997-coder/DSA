#include"../stdc++.h"

using namespace std;

string greatest_comm_divisor(string str1, string str2){
    string gcd_string ;

    if (str1.length() > str2.length()) {
        gcd_string = str2;
    } else {
        gcd_string = str1;
    }

    string sub_string;
    for (int length = gcd_string.size(); length > 0 ; length--) {

        if ((str1.length()% length != 0) && (str2.length()% length != 0)){
            continue;
        }
        sub_string = gcd_string.substr(0, length);
        
        string rep_string1 = "";
        string rep_string2 = "";
        for (int i = 0; i < str1.length() / length; i ++){
            rep_string1 = rep_string1+sub_string;
        }

        for (int i = 0; i < str2.length() / length; i ++){
            rep_string2 = rep_string2+sub_string;
        }

        if ((rep_string1 == str1) && (rep_string2 == str2)){
            return sub_string;
        }


    }

    return "";

}



int main(){
    string str1 = "ABABAB";
    string str2 = "ABAB";

    string res = greatest_comm_divisor(str1, str2);
}