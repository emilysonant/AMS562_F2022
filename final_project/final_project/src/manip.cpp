#include "manip.hpp"
#include <cmath>
#include <algorithm>

// you will need cmath and algorithm headers.

namespace ams562_final {

void compute_n2e_adj(const unsigned n, const Triangles &conn,
                     std::vector<std::vector<int>> &adj) {
  // resize adj to n
  adj.resize(n);
  // reserve for each of them with a reasonable upper bound

  // your code
}

void compute_avg_normals(const SphCo &points, const Triangles &conn,
                         const std::vector<std::vector<int>> &n2e_adj,
                         SphCo &nrms) {
  // resize the nrms
  nrms.resize(points.npoints());

  // your code
  for(int i = 0; i <= 146; i++){
    //declaring the current triangle that is being evaluated in conn
    double curr_conn = conn[i]; 

    //defining the three connections of the triangle
    conn1 = curr_conn[0];
    conn2 = curr_conn[1];
    conn3 = curr_conn[2];

    //defining the coordinates of each connection
    pts1 = points[conn1];
    pts2 = points[conn2];
    pts3 = points[conn3];

    //finding the vectors between the points
    dist12 = pow((pts2[0] - pts1[0]), 2) + pow((pts2[1] - pts1[1]), 2) + pow((pts2[2] - pts1[2]), 2);
    dist12 = sqrt(dist12);

    dist13 = pow((pts3[0] - pts1[0]), 2) + pow((pts3[1] - pts1[1]), 2) + pow((pts3[2] - pts1[2]), 2);
    dist13 = sqrt(dist13);
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