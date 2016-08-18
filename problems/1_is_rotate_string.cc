#include <iostream>

bool isRotateString(const std::string& a, const std::string& b){
    if(a.length()!=b.length()){
        return false;
    }
    std::string repeat_string = a+a;
    std::size_t found = repeat_string.find(b);
    if(found>=a.length()*2){
        return false;
    }
    return true;
}


int main() {
    std::string a = "waterbottoe";
    std::string b = "erbottlewat";

	printf("%d\n", isRotateString(a, b));
}