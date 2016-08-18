// Write a method to decide if two strings are anagrams or not.

#include <iostream>

bool IsAnagram(const std::string& s0, const std::string& s1) {
    if (s0.length()!=s1.length()) {
        return false;
    }
    int char_count[256]={0};
    
    for(int i=0;i<s0.length();i++){
        int value=s0.at(i);
        char_count[value]++;
    }
    for(int i=0;i<s1.length();i++){
        int value=s1.at(i);
        char_count[value]--;
    }
    for (int i =0; i<256; i++) {
        if(char_count[i]!=0){
            return false;
        }
    }
    return true;
}

int main() {
  std::string s = "ass bf";
  std::string s1 = "assb f";
  bool b = IsAnagram(s, s1);
    printf("Is %s and %s Anagram? %s\n", s.c_str(), s1.c_str(),(b?"Yes" : "No"));
}