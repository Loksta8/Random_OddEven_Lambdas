/*
@Author: Logan Herrera
@Date: 4/17/2020
@C++11 Standard
@Compiled with g++-4.7 compiler using Linux
@Program Description: Generate 10 random numbers and store inside a vector, create 2 more vectors,
store even and odd values from the first vector, use Lambdas for doing the "heavy lifting" aka
finding the even and odd values utilizing copy_if and for_each loops.
Finally display even and odd findings to the user to show that Lambdas are awesome to use!
@Program Purpose: To better understand how to use Lambdas
*/

//Import Libraries to use with this program
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

//Define std namespace
using namespace std;

//Create random integer function as a vector of integers
//that takes 2 arguments a number and maxvalue
vector<int> randomInts(int num, int maxValue){
        vector<int> tmp(num);

        for (int & i : tmp){
                i = rand() % maxValue;
        }

        return tmp;
}

//Make use of the template to distinguish between generic data types
//specifically
template<typename T>
void print(const vector<T>& v){
        for (T elem : v){
                cout << elem << " ";
        }
        cout << endl;
}

//Create main function
int main(){
        //Create srand call for random number generation using time
        srand(static_cast<unsigned int>(time(0)));
        //Create variables for 10 random ints ranging up to 200
        //And initialize up to 10 spaces for other variables
        vector<int> col1 = randomInts(10, 200);
        vector<int> col2(10);
        vector<int> col3(10);
        //print to the user the column 1 vector to display random numbers
        print(col1);
        //Utilize lambda with copy_if and return odd numbers only from column1,
        //store odd values found in column2, then clean up
        auto i = copy_if(col1.begin(), col1.end(), col2.begin(),
                       [](int x){return x % 2 == 1;});
        col2.erase(i, col2.end());
        //Display odd values found to the user(Column 2)
        cout << "odd : ";
        print(col2);

        //Create num variable to check for even cases and use in lambda
        int num = 2;
        //Utilize lambda with copy_if and return if even condition is met,
        //store even values found in column3, then clean up
        auto i2 = copy_if(col1.begin(), col1.end(), col3.begin(),
                          [num](int x) {return !(x % num) ;});
        col3.erase(i2, col3.end());
        //Display even values found to the user(Column 3)
        cout << "even : ";
        print(col3);

        // Create sum variable to check for odd cases and use in lambda
        int sum = 0;
        //Utilize lambda with reference to sum variable and perform a sum for each odd number
        for_each(col1.begin(), col1.end(),
                 [&sum](int n) { if (n % 2 == 1) sum += n; });
        //Display the odd summation
        cout << "odd sum : " << sum << endl;

        //Set sum back to zero to check for even case
        sum = 0;
        //Utilize lambda in for_each loop and perform a sum on all even numbers
        //stored in sum
        for_each(col1.begin(), col1.end(),
                 [&sum](int n) { if (n % 2 == 0) sum += n; });
        //Display the even summation
        cout << "even sum : " << sum << endl;

        //end program
}
