#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Check if given char is a number or not.
bool checkNum(char c){
  return c>='0'&&c<='9';
}

// Check the multiply condition and return the value.
int multiply(bool isMultiplying, char cal, int pre, bool sign, int val){
  if(isMultiplying){
    if(cal=='*'){
      val = pre*val;
    }
    if(cal=='/'){
      val = pre/val;
    }
  }else{
    val = val*(sign?1:-1);
  }
  return val;
}

// Calculate the sum of given stack.
int calculate(stack<int> nums){
  int val=0;
  while(!nums.empty()){
    val+=nums.top();
    nums.pop();
  }
  return val;
}

//Recursively solving the expression, given input string, 
// start position, and where this calculation ends.
int solve(string input, int start, int& end){
  int i=start;
  stack<int> nums; // stack for holding numbers.
  int pre=0; // previous number for multiply.
  bool sign=true; // the current sign, true is +, false is -.
  char cal=' '; // the current calculate.
  bool isMultiplying=false; // if we have a number waiting for multiply.
  int val=0; //value of current number.

  // we calculate until we see ')' or the end of the input string.
  while(i<input.size() && input[i]!=')'){

    if(input[i]=='('){ // If we see the '(', recursively solve it to get a result.
      int _end;
      int temp = multiply(isMultiplying, cal, pre, sign, solve(input, i+1, _end));
      nums.push(temp);
      i = _end;
    }else{ 
      // If we see the '+' or '-', change the sign.
      if(input[i]=='+'||input[i]=='-'){
        isMultiplying=false;
        sign = input[i]=='+';
      }else if(input[i]=='*'||input[i]=='/'){
        // If we see the '*' or '/', pop the previous number in stack as pre, waiting to be multiplied.
        isMultiplying = true;
        pre = nums.top();
        nums.pop();
        cal = input[i];
      }else{
        val=val*10+(input[i]-'0');
        // If to the end of the input, or next char is not a number, push cur into nums stack.
        if((i+1)>=input.size()||!checkNum(input[i+1])){
          nums.push(multiply(isMultiplying, cal, pre, sign, val));
          cout<<nums.top()<<endl;
          val=0;
        }
      }
      i++;
    }
  }
  end = i+1;
  return calculate(nums);
}

int main() {
  //"5+89*(10*(5*(7+9)+7))-100"
  //"5-23*8/2-1+22*2"
  string s="5+89*(10*(5*(7+9)+7))-100";
  int end;
  cout << s<<" = " << solve(s, 0, end) << endl;
  return 0;
}