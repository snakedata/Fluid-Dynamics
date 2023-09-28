#include <iostream>

#include <string>
#include <fstream>

using namespace std;





int main(int argc, char *argv[]){
    int x[5];
    string input_file = "small.fld";
    string output_file;
    ifstream myfile;

//Create the simulation grid
    int b_min[3] = {1,2,3};
    int b_max[3] = {4,5,6};
    int boxx = b_max[0] - b_min[0];
    int boxy = b_max[1] - b_min[1];
    int boxz = b_max[2] - b_min[2];


};
