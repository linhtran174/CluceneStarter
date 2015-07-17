#include <stdio.h>
#include "LinhHelperLibrary.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

void doSomeThing(stack<int>& temp){
	temp.push(1);
	temp.push(2);
	temp.push(3);
	temp.push(4);
}

int main(){
	stack<string> output;
	LINH_LIST_DIRECTORY("/home/linh/Desktop/websites",output);
	cout<<output.size()<<endl;

	while(!output.empty()){
		cout << "TOP: " << output.top() << endl;
		output.pop();
	}
}