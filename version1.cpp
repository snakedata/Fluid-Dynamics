#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
//External libraries
//GSL
//Google Test

//Twenty lines per function maximum
//Pointer arithmetic forbidden

//Vectores iniciales - fuerzas resultantes -


struct particle{
    float px;
    float py;
    float pz;
    float hvx;
    float hvy;
    float hvz;
    float vx;
    float vy;
    float vz;
    float p = 0;
    float a = 9.81;
};
double distance_squared(particle p1, particle p2){
    double dx = p1.px - p2.px;
    double dy = p1.py - p2.py;
    double dz = p1.pz - p2.pz;

    return dx * dx + dy * dy + dz * dz;
};

int main(int argc, char** argv) {
    //Contsants intialization
    double r = 1.695;
    double p = 1000;
    double ps = 3.0;
    double sc = 30000;
    double dv = 128.0;
    double nu = 0.4;
    double dp = 0.0002;
    double time_step = 0.001;
    int particle_num = 2;
    double ppm = 2;
    double mass = p*pow(ppm,3);
    double h = r/ppm;




    vector<particle> vector_particles;

    particle particle1{};
    particle1.px = 2;
    particle1.py = 2;
    particle1.pz = 2;
    particle1.hvx = 2;
    particle1.hvy = 2;
    particle1.hvz = 2;
    particle1.vx = 2;
    particle1.vy = 2;
    particle1.vz = 2;

    particle particle2{};
    particle2.px = 2;
    particle2.py = 1.99;
    particle2.pz = 2;
    particle2.hvx = 2;
    particle2.hvy = 2;
    particle2.hvz = 2;
    particle2.vx = 2;
    particle2.vy = 2;
    particle2.vz = 2;


    //Parte de lectura de Juan crear todas las particulas
    vector_particles.push_back(particle1);
    vector_particles.push_back(particle2);


    //Parte del grid creation
    int b_min[3] = {1,2,3};
    int b_max[3] = {4,5,6};
    int boxx = b_max[0] - b_min[0];
    int boxy = b_max[1] - b_min[1];
    int boxz = b_max[2] - b_min[2];

    //Density computation
    double d;
    for (auto i = vector_particles.begin();i !=vector_particles.end(); i++){
        for (auto j = i++;j != vector_particles.end(); j++){
            d = distance_squared(*i,*j);
            if (d < h){
                auto density_inc =pow((h*h-d),3);
                auto increment = static_cast<float>(density_inc);
                cout << increment;
                i->p = i->p + increment;
                j->p += i->p +increment;
            }
        }
    }
    cout << particle1.p;
    cout << particle2.p;

    //Reposicionamiento de las acceleraciones
    //Verification of distance


}
