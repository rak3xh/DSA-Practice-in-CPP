/*
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
   int i=0;
    for( i=0;i<n;i++){
        for(int j=n-1;j>i;j--){ //space
            cout<<" ";
        }
            char ch='A';

        for (int k=0;k<=i;k++) {   //first triangle
                cout<<ch;
                ch++;
        }
        
         
         for (char cha = 'A' + i; cha >= 'A'; --cha) {
            cout << cha;
        
        }

        cout<<endl; 
    }
    
}

*/
#include <iostream>
using namespace std;
int main() {
    int n ; // Number of lines in the pattern
    cin>>n;
    
    // Loop for each line
    for (int i = 0; i < n; ++i) {
        // Print leading spaces
        for (int j = 0; j < n - i - 1; ++j) {
            cout << " ";
        }
        // Print ascending part of the pattern
        for (char ch = 'A'; ch <= 'A' + i; ++ch) {
            cout << ch;
        }
        // Print descending part of the pattern
        for (char ch = 'A' + i - 1; ch >= 'A'; --ch) {
            cout << ch;
        }
        // Move to the next line
        cout <<endl;
    }

    return 0;
}
