/* **********************************************************************
 File: hw2.cpp
 Author: Cheechee Lin
 Date: October 12, 2015
 
 Program that repeatedly performs linear searches on a vector
 and computes the average number of comparisons needed to find
 an element.
 
 This program has a running time T = O(N).
 Best case: 1 comparison
 Average case: N/2 comparisons
 Worst case: N comparisons
 ********************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <algorithm>

const int RUN_TIMES = 100;

//implementing linear search, avoid modifying the vector passed in
int linear_search(const std::vector<int>&a, int target){
    //comparing the target to the element in the vector and advancing with each turn until the target matches the element in vector
    for (int i=0; i<a.size(); i++){
        if (a[i]==target) return i;
        //statements+=2;//every time an element is compared and i advances
    }
    return -1; //element not found
    
}

/* 
 THE SHUFFLE CAN BE DONE THIS WAY

 for(int i=0; i<x;i++){
 int m= (rand()%v1.size());//this can be treated as const time 
 v2. push_back(v1[m]);//lookups on vectors: not expensive, still treated as const time
 v1[m]=v1[v1.size()-1];//assignments are also cheap, still treated as const time 
 v1.pop_back();
 return v2;
 }
 
 //O(N)+ O(N)= O(N) 
 */
int main() {
    //opening files to write text to
    std::ofstream myfile;
    myfile.open("data.txt");
    
    //seeding the random numbers used in this program
    srand(static_cast<int>(time(0)));
    
    //for the purpose of counting statements and finding complexity, declaring variables used
    std::vector<int> myVector;
    std::vector<int> countingPosition;
    int upperBound;
    int randomNumber, randomSize;
    int position=0;
    int sum;

    
    //to calculate time elapsed
    //const clock_t begin_time=clock();
    
    //setting the upper bound of the random numbers
    std:: cout<<"Please enter an upper bound N"<<std::endl;
    std:: cin>> upperBound;
    
    
    for (int i=0; i<RUN_TIMES; i++) {
        myVector.resize(0);
        countingPosition.resize(0);
        sum=0;
        
        //creating a random size of the vector between 1 and a big number N
        randomSize=1+rand()%upperBound;
        
        //creating a vector with a size of "randomSize" and numbers 1 through randomSize
        for (int j=1; j<randomSize+1; j++) {
            myVector.push_back(j);
        }
        //shuffling said vector in previous step so it is completely random
        std::random_shuffle ( myVector.begin(), myVector.end());
        
        //linear searching for a random number between 1 and randomSize randomSize times
        for (int j=0; j<randomSize;j++){
            randomNumber=1+rand()%randomSize;
            position= linear_search(myVector,randomNumber)+1; //this way it will not be the index
            sum+=position;
            //std::cout<<randomSize<<"\t"<<position<<std::endl;
        }
        
        //computing average and writing to file
        double average=(double)sum/randomSize;
        myfile<<randomSize<<"\t"<<std::fixed<<std::setprecision(3)<<average<<std::endl;
        
        //std::cout<<RAND_MAX;
        

    //for the purpose of calculating time elapsed
    //std::cout<<float(clock()- begin_time)/1000<<" seconds have elapsed";
    }
    return 0;
    
    
}
