/*In this code we analyze just how random some psuedo-random number generators 
 * are.*/

#include <cstdio>
#include <cstdlib>
#include <fstream> 
#include <iostream>
#include <cmath>
#include <cstring>
#include <ctime>

//first we include the libraries we need


using namespace std;
double rand_uniform ( long rand_int);
double randU();
double randS(double rngnum);
int iseed = 1;
double r_u[6][10] = {0};
double ru[6][10] = {0};
double rs[6][10] = {0};
double ind = 1;
double iterations = 10000;
//Then we initialize our counters and include our functions





int main(int argc, char** argv) {
    ofstream rand_uniform_number_list;
    ofstream randU_number_list;
    ofstream randS_number_list;
    
    std::remove("rand_uniform_number_list.txt");
    std::remove("randU_number_list.txt");
    std::remove("randS_number_list.txt");
    //Then we allow for our data files to be created
    
    
    
    for ( int i = 0; i<iterations; i++ ) {
        
        double randomuniform= rand_uniform (rand());
        double randomu=randU();
        double randoms=randS(ind);
        
        //we get our random numbers
        
        rand_uniform_number_list.open("rand_uniform_number_list.txt",ios::app);
        rand_uniform_number_list << " " << randomuniform << " " <<endl;
        rand_uniform_number_list.close();

        randU_number_list.open("randU_number_list.txt", ios::app);
        randU_number_list << " " << randomu << " " << endl;
        randU_number_list.close();
        
        randS_number_list.open("randS_number_list.txt", ios::app);
        randS_number_list << " " << randoms << " " << endl;
        randS_number_list.close();
    
        //and we store them in text files
        
        double digits_r_u[8];
        double digits_ru[8];
        double digits_rs[8]; 
        
        for(int j=0; j<6; j++){
            digits_r_u[j] =   floor(fmod(randomuniform*pow(10,j+1),10));
            digits_ru[j] =  floor(fmod(randomu*pow(10,j+1),10));
            digits_rs[j] =  floor(fmod(randoms*pow(10,j+1),10));
        }
        
        //we turn our random numbers into arrays where each element is a part
        //of the number
             
        
        for(int j=0; j<6; j++){
            for(int k=0; k<10; k++){
                if (digits_r_u[j] == k ){
                    r_u[j][k] += 1;
                }
                if (digits_ru[j] == k ){
                    ru[j][k] += 1;
                }
                if (digits_rs[j] == k ){
                    rs[j][k] += 1;
                }  
            }
        }
        ind++;
    }
    //We count what happens over all iterations
    
    ofstream rand_uniform_freq;
    std::remove("rand_uniform_freq.txt");
    rand_uniform_freq.open("rand_uniform_freq.txt",ios::app);
    
    for(int i=0; i<6; i++){
    
    rand_uniform_freq <<  "frequency of numbers 0-9 occur the"<<"\t" 
        << i+1 << "\t" <<"digit place in rand_uniform in order are:" << endl;
    rand_uniform_freq << endl;
        for(int j=0; j<10; j++){
            rand_uniform_freq << "\t" << r_u[i][j]/iterations << "\t";
            
        }
         rand_uniform_freq << endl;
         rand_uniform_freq << endl;
    }
    
    ofstream randU_freq;
    std::remove("randU_freq.txt");
    randU_freq.open("randU_freq.txt",ios::app);
    
    for(int i=0; i<6; i++){
    
    randU_freq <<  "frequency of numbers 0-9 occur the"<<"\t" 
        << i+1 << "\t" <<"digit place in rand_uniform in order are:" << endl;
    randU_freq << endl;
        for(int j=0; j<10; j++){
            randU_freq << "\t" << ru[i][j]/iterations << "\t";
            
        }
         randU_freq << endl;
         randU_freq << endl;
    }
    
    ofstream randS_freq;
    std::remove("randS_freq.txt");
    randS_freq.open("randS_freq.txt",ios::app);
    
    for(int i=0; i<6; i++){
    
    randS_freq <<  "frequency of numbers 0-9 occur the"<<"\t" 
        << i+1 << "\t" <<"digit place in rand_uniform in order are:" << endl;
    randS_freq << endl;
        for(int j=0; j<10; j++){
            randS_freq << "\t" << rs[i][j]/iterations << "\t";
            
        }
         randS_freq << endl;
         randS_freq << endl;
    }
    //and finally we output the frequencies in text files
    
    
    return 0;
}

double rand_uniform ( long rand_int ) {

  return double(rand_int) / (double)RAND_MAX;

}


//Here we have three different random number generators

double randU () {

  long imax = 2147483647;
  double xmax_inv = 1./double(imax);
  iseed *= 65539;
  if ( iseed < 0 )
    iseed += imax + 1;
  double x = double(iseed) * xmax_inv;
  return x;
  
}

double randS (double rngnum){
    srand(time(0) + rngnum);
    double epsilon = (double) rand()/RAND_MAX;
    return epsilon;
}