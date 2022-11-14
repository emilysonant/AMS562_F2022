#include <cmath>
#include <cstdlib>
#include <ctime>  // for trigger the seed of random number generator
#include <iostream>

static void genPointsOnUnitSphere(const int N, float *x, float *y, float *z);
float dotProduct(float n1[3], float n2[3]);

int main(int argc, char *argv[]) {
  // parse input argc/argv and get the size of N
  std::string N_str = argv[1];
  int N = std::stoi(N_str);

  // allocate memory for x, y, z
  float *x = nullptr, *y = nullptr, *z = nullptr;

  x = new float[N];
  y = new float[N];
  z = new float[N];

  genPointsOnUnitSphere(N, x, y, z);

  // determine the extreme arc lengths
  int i = 1;
  float n1[3] = {x[0], y[0], z[0]};
  float n2_max[3] = {x[1], y[1], z[1]};
  float n2_min[3] = {x[1], y[1], z[1]};

  //calculate the initial values of l
  float dot_product_max = dotProduct(n1, n2_max);
  float dot_product_min = dotProduct(n1, n2_min);

  float l_max = acos(dot_product_max);
  float l_min = acos(dot_product_min);

  while (i < N){

    float n2_new_max[3] = {x[i+1], y[i+1], z[i+1]};
    float n2_new_min[3] = {x[i+1], y[i+1], z[i+1]};

    float l_new_max = acos(dotProduct(n1, n2_new_max));
    float l_new_min = acos(dotProduct(n1, n2_new_min));

    if (l_new_max > l_max) {
        n2_max[0] = n2_new_max[0];
        n2_max[1] = n2_new_max[1];
        n2_max[2] = n2_new_max[2];
        
        l_max = acos(dotProduct(n1, n2_max));
    }
    if (l_new_min < l_min) {
        n2_min[0] = n2_new_min[0];
        n2_min[1] = n2_new_min[1];
        n2_min[2] = n2_new_min[2];
        
        l_min = acos(dotProduct(n1, n2_min));
    }
    i++;
  }  
  std::cout << "x[0]:\t" << n1[0] << "\ty[0]:\t" << n1[1] << "\tz[0]:\t" << n1[2] << std::endl;
  std::cout << "x_max:\t" << n2_max[0] << "\ty_max:\t" << n2_max[1] << "\tz_max:\t" << n2_max[2] << std::endl;
  std::cout << "x_min:\t" << n2_min[0] << "\ty_min:\t" << n2_min[1] << "\tz_min:\t" << n2_min[2] << std::endl;
  std::cout << "The maximum arc length is:\t" << l_max << std::endl;
  std::cout << "The minimum arc length is:\t" << l_min << std::endl;

  // relax memory
  delete[] x;
  delete[] y;
  delete[] z;

  return 0;
}
//dot product function
float dotProduct(float n1[3], float n2[3]) {
    float dot_product = n1[0]*n2[0] + n1[1]*n2[1] + n1[2]*n2[2];
    return dot_product;
}

// black-box function to generate a collection of random points
void genPointsOnUnitSphere(const int N, float *x, float *y, float *z) {
  if (x == nullptr || y == nullptr || z == nullptr || N <= 0) {
    std::cerr << "invalid pointers or size, aborting...\n";
    std::exit(1);
  }
  std::srand(std::time(0));  // trigger the seed
  const int BD = 10000000, BD2 = 2 * BD;
  const float inv_bd = 1.0f / BD;  // not integer division
  for (int i = 0; i < N; ++i) {
    x[i] = (std::rand() % BD2 - BD) * inv_bd;
    y[i] = (std::rand() % BD2 - BD) * inv_bd;
    z[i] = (std::rand() % BD2 - BD) * inv_bd;
    const float len = std::sqrt(x[i] * x[i] + y[i] * y[i] + z[i] * z[i]);
    if (len > 1e-5f) {
      // project on to unit sphere  
      x[i] /= len;
      y[i] /= len;
      z[i] /= len;
    } else {
      // too close to zero
      // directly set the point to be (1,0,0)
      x[i] = 1.0f;
      y[i] = z[i] = 0.0f;
    }
  }
}
