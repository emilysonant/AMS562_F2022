#include "manip.hpp"

#include <algorithm>
#include <cmath>

// you will need cmath and algorithm headers.

namespace ams562_final {

void compute_n2e_adj(const unsigned n, const Triangles &conn,
                     std::vector<std::vector<int>> &adj) {
  // resize adj to n
  adj.resize(n);
  // reserve for each of them with a reasonable upper bound

  // your code
  /* for(i = 0; i < 146; i++) {
    for(j = 0; j <= 2; j++) {
      
    }
  } */
}

void compute_avg_normals(const SphCo &points, const Triangles &conn,
                         const std::vector<std::vector<int>> &n2e_adj,
                         SphCo &nrms) {
  // resize the nrms
  nrms.resize(points.npoints());

  // your code
  for (int i = 0; i <= 146; i++) {
    
    // defining the coordinates of each connection
    std::vector<std::array<double, 3>> pts = points.to_vector();

    std::array<double, 3> pts1 = pts[i];
    std::array<double, 3> pts2 = pts[i+1];
    std::array<double, 3> pts3 = pts[i+2];

    // finding the vector between the points
    std::vector<double> vec12 = {(pts2[0] - pts1[0]), (pts2[1] - pts1[1]), (pts2[2] - pts1[2])};
    std::vector<double> vec13 = {(pts3[0] - pts1[0]), (pts3[1] - pts1[1]), (pts3[2] - pts1[2])};

    // cross product of vector 12 and 13
    std::vector<double> crossprod = {(vec12[1]*vec13[2] - vec12[2]*vec13[1]), {vec12[2]*vec13[0] - vec12[0]*vec13[2]}, (vec12[0]*vec13[1] - vec12[1]*vec13[0])};
  
    // magnitude of the cross product
    double mag = sqrt((pow(crossprod[0], 2)) + pow(crossprod[1], 2) + pow(crossprod[2], 2));

    // normalize vectors
    std::vector<double> norm = {(crossprod[0]/mag), (crossprod[1]/mag), (crossprod[2]/mag)};
  }

  // hint don't forget normalizing the normals
}

void compute_errors(const SphCo &exact, const SphCo &num,
                    std::vector<double> &acos_theta) {
  // resize the error array
  acos_theta.resize(num.npoints());

  // your code
}

}  // namespace ams562_final