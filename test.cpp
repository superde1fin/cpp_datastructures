//#include "datastructures.hpp"
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <openssl/sha.h>
#include <gmpxx.h>
#include <math.h>

using namespace std;


int hash_function(const string str){
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    string result = ss.str();
    mpz_class hash_num = 0;
    for(int i = 0; i < result.length(); i++){
        int ascii_value = int(result[i]);
        ss.str("");
        ss << ascii_value;
        hash_num = hash_num*int(pow(10, ss.str().length())) + ascii_value;
        }
    return hash_num.get_ui() % 10;
    }
int main(){
    cout << hash_function("lolk");
    
    return 0;
    }
