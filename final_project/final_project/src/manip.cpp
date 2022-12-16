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
  for (unsigned i = 0; i < conn.ntris(); i++) {
    std::array<int, 3> triangle = conn[i];
    for (int j = 0; j <= 2; j++) {
      int node = triangle[j];
      adj[node].push_back(i);
    }
  }
}

void compute_avg_normals(const SphCo &points, const Triangles &conn, const std::vector<std::vector<int>> &n2e_adj, SphCo &nrms) {
 
  // resize the nrms
  nrms.resize(points.npoints());

  // your code

  // facial normal vectors initialize
  int m = conn.ntris();
  std::vector<std::vector<double>> facialNormals;
  facialNormals.resize(m);

  for (int i = 0; i < m; i++) {
    std::array<int, 3> current_triangle = conn[i];

    // defining the coordinates of each connection
    std::vector<std::array<double, 3>> pts = points.to_vector();

    std::array<double, 3> pts1 = pts[current_triangle[0]];
    std::array<double, 3> pts2 = pts[current_triangle[1]];
    std::array<double, 3> pts3 = pts[current_triangle[2]];

    // finding the vector between the points
    std::vector<double> vec12 = {(pts2[0] - pts1[0]), (pts2[1] - pts1[1]), (pts2[2] - pts1[2])};
    std::vector<double> vec13 = {(pts3[0] - pts1[0]), (pts3[1] - pts1[1]), (pts3[2] - pts1[2])};

    // cross product of vector 12 and 13
    std::vector<double> crossprod = {(vec12[1] * vec13[2] - vec12[2] * vec13[1]), {vec12[2] * vec13[0] - vec12[0] * vec13[2]}, (vec12[0] * vec13[1] - vec12[1] * vec13[0])};

    // magnitude of the cross product
    double mag = sqrt((pow(crossprod[0], 2)) + pow(crossprod[1], 2) +pow(crossprod[2], 2));

    // normalize vectors
    std::vector<double> norm = {(crossprod[0] / mag), (crossprod[1] / mag), (crossprod[2] / mag)};

    // store facial normal
    facialNormals[i] = norm;
  }

  // sum of all adjacent normals
  for (unsigned v = 0; v < n2e_adj.size(); v++) {
    std::vector<int> adj_nodes = n2e_adj[v];
    int k = adj_nodes.size();
    std::vector<double> vect_z{0, 0, 0};
    for (unsigned w = 0; w < k; w++) {
      
      // add vector facialNormals[adj_nodes[w]] to z
      for(unsigned y = 0; y < 3; y++) {
        vect_z[y] += facialNormals[adj_nodes[w]][y];
      }
    }

    // average of adjacent normals
    for(unsigned a = 0; a < 3; a++) {
      vect_z[a] = vect_z[a]/k;
    }
    
    // magnitude of z
    double mag_z = sqrt((pow(vect_z[0], 2)) + pow(vect_z[1], 2) +pow(vect_z[2], 2));

    // normalize the vector
    for(unsigned b = 0; b < 3; b++) {
      nrms[v][b] = vect_z[b]/mag_z;
    }
  }

  // hint don't forget normalizing the normals
}

void compute_errors(const SphCo &exact, const SphCo &num, std::vector<double> &acos_theta) {

  // resize the error array
  acos_theta.resize(num.npoints());

  // your code
  
  //normalize num
  for(unsigned i = 0; i < num.npoints(); i++) {
    std::array<double, 3> points_num = num[i];
    std::array<double, 3> points_exact = exact[i];

    double num_mag = sqrt(points_num[0]*points_num[0] + points_num[1]*points_num[1] + points_num[2]*points_num[2]);
    std::vector<double> num_norm = {(points_num[0] / num_mag), (points_num[1] / num_mag), (points_num[2] / num_mag)};
    double exact_mag = sqrt((pow(points_exact[0], 2) + (pow(points_exact[1], 2) + (pow(points_exact[2], 2)))));
  
    acos_theta[i] = acos((points_num[0]*points_exact[0] + points_num[1]*points_exact[1] + points_num[2]*points_exact[2])/(num_mag*exact_mag)); 
  }  
} 

}  // namespace ams562_final