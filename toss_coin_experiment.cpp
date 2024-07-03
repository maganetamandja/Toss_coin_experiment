//include random
#include <gmp.h>
#include <iostream>
#include <random>
#include <vector>
#include <math.h>
#include "combination.h"

int n = 10; //toss n times
//function to toss a coin

int toss_coin(){
    std:: random_device rd;
    std::mt19937 gen(rd());
    //head is 0 and tail is 1
    std::uniform_int_distribution<> dis(0,1);

    int coin_toss = dis(gen);
    return coin_toss;
}

//vector with n+1 entries to store the coresponding count of h
std::vector<int> distribution_vector(n+1);

//vector with results

std::vector<double> proposed_distribution_vector(n+1);


//populate proposed vector
void populate(){
for (int i=0; i < (n+1); i++ ){
    //std::cout << "combination of : "<<i<<"and "<<n<<"is :" <<  combination(i,n)<< std::endl;
    proposed_distribution_vector[i]= (double)(1.0/pow(2,n))*(double)(combination(n,i));
}
}
//function to toss a coin n times

int toss_n_times(){
    int head_count = 0;
    for (int i = 0; i< n; i++){
        //toss_coin();
        if (toss_coin() == 0)
            {head_count++;}

    }
    return head_count;
}


//std::vector<int> 
void foo(){
    int temp_var = toss_n_times(); // assign # of heads
    //assign count of each n toss to the corresponding vector entry.  

    distribution_vector[temp_var]= distribution_vector[temp_var]+1;
    //return distribution_vector;

}



int main(){
    int k = 10000; // the itterator
    for (int i = 0; i<k; i++){
        foo();
    }

    //populate proposed vector
    populate();

    double sum_ver1 = 0.0;
    double sum_ver2 = 0.0;

    for(int i = 0; i< distribution_vector.size(); i++){
        std::cout << (double)distribution_vector.at(i)/k << std::endl;

        sum_ver1 = sum_ver1+((double)distribution_vector.at(i)/k);

       // std::cout << "sum inter is : "<< sum_ver1 << std::endl;


       
    }
     std::cout << "sum is : "<< sum_ver1 << std::endl;

    std::cout<<"====================="<<std::endl;

     for(int i = 0; i< proposed_distribution_vector.size(); i++){
        std::cout << proposed_distribution_vector.at(i) << std::endl;
        sum_ver2 = sum_ver2 + proposed_distribution_vector.at(i);
      //  std::cout << "sum inter is : "<< sum_ver2 << std::endl;
       // std::cout << typeid(proposed_distribution_vector.at(i)).name() << std::endl;
       
    }
    std::cout << "sum is : "<< sum_ver2 << std::endl;

    //std::cout << distribution_vector << std::endl;
    return 0;
}
