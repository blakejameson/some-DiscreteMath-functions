#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string convert_decimal_to_binary(int decimal_number);
string convert_octal_to_binary(string octal_value);
string convert_hexadecimal_to_binary(string hexadecimal_value);


int main() {
    cout << convert_hexadecimal_to_binary("1AC");
}
// In this function, the user enters a decimal (base 10) number,
// and the binary result (base 2) is returned as a string.

string convert_decimal_to_binary(int decimal_number){
    std::string binary_result= "";
    bool function_completed = false;
    while (!(function_completed)){
        int resulting_int = decimal_number/2;
        int modulo = decimal_number - resulting_int*2;
        decimal_number = resulting_int;
        if (modulo == 1){
            binary_result = "1" + binary_result ;
        }
        else {
            binary_result = "0" + binary_result;
        }
        if (resulting_int==0){
            function_completed = true;
            break;
        }
    }
    return binary_result;
}

// The user enters an octal (base 8) value, and a binary (base 2) value is returned as a string
string convert_octal_to_binary(string octal_value)   //, bool extra_zeros_at_beginning= false){
{
    string resulting_octal;
    int right_index = octal_value.length()-1;
    while (right_index >= 0){
        char right_value = octal_value.at(right_index);
        int right_valuee = right_value - '0';
        string current_binary;
        int current_factor =1;
        string ok = convert_decimal_to_binary(right_valuee);
        while (ok.length()<3){
            ok = "0" + ok;
        }
        right_index-=1;
        resulting_octal =  ok + resulting_octal;
        }

    /*
    int octal_length = resulting_octal.length();
    if (extra_zeros_at_beginning) {
        while (octal_length % 4 != 0) {
            resulting_octal = "0" + resulting_octal;
            octal_length = resulting_octal.length();

        }
    }
     */
    return resulting_octal;
    }

string convert_hexadecimal_to_binary(string hexadecimal_value){
    string final_value;
    unordered_map<char,int> results= {
            {'A',10},
            {'B',11},
            {'C',12},
            {'D',13},
            {'E',14},
            {'F',15},
    };
    int right_index = hexadecimal_value.length() - 1;
    while (right_index>=0){
        int right_val;
        char right_value = hexadecimal_value.at(right_index);
        if (results.count(right_value)){
            right_val = results.at(right_value);
        }
        else{
            right_val = right_value - '0';
        }
        string binary_result = convert_decimal_to_binary(right_val);
        final_value= binary_result + final_value;
        right_index-=1;
        }
    return final_value;
    }

